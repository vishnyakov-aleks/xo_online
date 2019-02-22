#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include "mainmenu/QMainMenuLayout.h"
#include "routing/Router.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    auto * rootWidget = new QWidget();
    rootWidget->resize(640, 480);
    rootWidget->setWindowTitle("XO - Game");

    Router::getInstance().init(rootWidget);
    Router::getInstance().setMainMenuScreen();
    rootWidget->show();
    return QApplication::exec();
}