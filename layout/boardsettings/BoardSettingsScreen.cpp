//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include "BoardSettingsScreen.h"
#include "BoardSettingsLayout.h"

QLayout *BoardSettingsScreen::createLayout() {
    widgetHeight = 200;
    widgetWidth = 200;
    auto *layout = new BoardSettingsLayout();
    layout->setController(new BoardSettingsController(isLocalGame));
    return layout;
}

BoardSettingsScreen::BoardSettingsScreen(bool isLocalGame) {
    this->isLocalGame = isLocalGame;
}
