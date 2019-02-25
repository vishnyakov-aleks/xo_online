//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include "MainMenuScreen.h"
#include "QMainMenuLayout.h"

MainMenuScreen::MainMenuScreen() {
    widgetHeight = 130;
    widgetWidth = 250;
}

QLayout *MainMenuScreen::createLayout() {
    return new QMainMenuLayout();
}
