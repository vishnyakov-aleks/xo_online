//
// Created by Aleksey Vishnyakov on 2019-02-25.
//

#include "BoardSettingsController.h"
#include "../../routing/Router.h"
#include "../gameboard/BoardScreen.h"

BoardSettingsController::BoardSettingsController(bool isLocalGame) {
    this->isLocalGame = isLocalGame;
}

void BoardSettingsController::startGame(unsigned int linesCount, unsigned int cellsToWin) {
    Router::getInstance().replaceScreen(new BoardScreen(linesCount, cellsToWin));

}
