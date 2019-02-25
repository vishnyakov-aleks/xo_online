//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include "BoardSettingsScreen.h"
#include "BoardSettingsLayout.h"

QLayout *BoardSettingsScreen::createLayout() {
    widgetHeight = 130;
    widgetWidth = 200;
    return new BoardSettingsLayout();
}
