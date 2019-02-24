//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include "BoardSettingsScreen.h"
#include "../layout/gamesettings/BoardSettingsLayout.h"

QLayout *BoardSettingsScreen::createLayout() {
    widgetHeight = 130;
    widgetWidth = 300;
    return new BoardSettingsLayout();
}
