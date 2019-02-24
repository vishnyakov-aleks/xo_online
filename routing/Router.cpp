//
// Created by Aleksey Vishnyakov on 2019-02-22.
//


#include <QObjectCleanupHandler>
#include <QDesktopWidget>
#include <QApplication>
#include <QLayout>
#include "Router.h"

void Router::init(QWidget *qWidget) {
    this->rootWidget = qWidget;
    propertyAnimation = new QPropertyAnimation(rootWidget,"geometry");
    propertyAnimation->setDuration(680);
    propertyAnimation->setEasingCurve(QEasingCurve::InOutElastic);
}

void Router::clearOldLayout() {
    QLayout *layout = rootWidget->layout();
    if (layout == nullptr)
        return;


    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        layout->removeItem (item);
        item->widget()->deleteLater();
    }
    delete layout;
    QObjectCleanupHandler().add(rootWidget->layout());

}

void Router::replaceWithAnimResize(QLayout *layout, int newWidth, int newHeight) {
    bool needMoveToCenter = rootWidget->layout() == nullptr;
    clearOldLayout();

    rootWidget->setLayout(layout);
    if (needMoveToCenter) {
        QDesktopWidget *pDescwidget=QApplication::desktop();
        rootWidget->move(pDescwidget->width()/2 - newWidth/2, pDescwidget->height()/2 - newHeight/2);
        rootWidget->resize(newWidth, newHeight);
        return;
    }


    propertyAnimation->setStartValue(rootWidget->geometry());
    auto rect = QRectF(rootWidget->geometry());
    rect.setX(rect.x() + ((rect.width() - newWidth) / 2));
    rect.setY(rect.y() + ((rect.height() - newHeight) / 2));
    rect.setWidth(newWidth);
    rect.setHeight(newHeight);
    propertyAnimation->setEndValue(rect);
    propertyAnimation->start();
}

void Router::replaceScreen(IScreen *screen) {
    replaceWithAnimResize(screen->createLayout(), screen->widgetWidth, screen->widgetHeight);
}
