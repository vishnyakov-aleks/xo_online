//
// Created by Aleksey Vishnyakov on 2019-02-22.
//


#include <QObjectCleanupHandler>
#include <iostream>
#include "Router.h"
#include "../mainmenu/QMainMenuLayout.h"
#include "../gameboard/BoardLayout.h"

void Router::init(QWidget *qWidget) {
    this->rootWidget = qWidget;
}

void Router::clearOldLayout() {
    QLayout* layout = rootWidget->layout ();
    if (layout == nullptr) return;

    for (auto i : layout->children()) {
        QObjectCleanupHandler().add(i);
    }

    qDeleteAll(layout->children());
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != 0) {
        layout->removeItem (item);
        item->widget()->deleteLater();
    }
    delete layout;
    QObjectCleanupHandler().add(rootWidget->layout());

}

void Router::setMainMenuScreen() {
    clearOldLayout();
    auto * mainMenu = new QMainMenuLayout(rootWidget);
    rootWidget->setLayout(mainMenu);
}

void Router::setBoardScreen(BoardController * controller) {
    clearOldLayout();
    auto * boardLayout = new BoardLayout(rootWidget);
    rootWidget->resize(800, 800);
    boardLayout->setController(controller);
    std::cout << rootWidget->children().size();
    rootWidget->setLayout(boardLayout);
}
