#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QDesktopWidget>
#include "routing/Router.h"
#include "layout/mainmenu/MainMenuScreen.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    auto * rootWidget = new QWidget();
    rootWidget->setWindowTitle("XO - Game");

    Router::getInstance().init(rootWidget);
    Router::getInstance().newChain(new MainMenuScreen());
    rootWidget->show();
    return QApplication::exec();
}