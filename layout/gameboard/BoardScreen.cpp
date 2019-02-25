//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include "BoardScreen.h"
#include "BoardController.h"
#include "BoardLayout.h"

QLayout *BoardScreen::createLayout() {
    auto * controller = new BoardController(linesCount, cellsToWin);
    auto layout = new BoardLayout();
    layout->setController(controller);
    return layout;
}

BoardScreen::BoardScreen(unsigned int linesCount, unsigned int cellsToWin) {
    this->linesCount = linesCount;
    this->cellsToWin = cellsToWin;
    widgetWidth = 60 * linesCount + 40;
    widgetHeight = 55 * linesCount;
}
