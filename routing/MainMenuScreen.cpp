//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include "MainMenuScreen.h"
#include "../mainmenu/QMainMenuLayout.h"

MainMenuScreen::MainMenuScreen() {
    widgetHeight = 130;
    widgetWidth = 300;
}

QLayout *MainMenuScreen::createLayout() {
    return new QMainMenuLayout();
}
