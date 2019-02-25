//
// Created by Aleksey Vishnyakov on 2019-02-21.
//

#include <string>
#include "BoardController.h"



BoardController::BoardController(unsigned int lineWidth, unsigned int symbolsCountToWin) {
    this->boardSize = lineWidth * lineWidth;
    this->lineWidth = lineWidth;
    this->symbolsCountToWin = symbolsCountToWin;

    for (unsigned int i = 0; i < boardSize; i++) {
        board.push_back(' ');
    }
}

bool BoardController::checkLeftHorizontal(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell - spiralLevel;
    return i >= 0 && i % lineWidth >= 0 && i % lineWidth < lineWidth - 1 && board[i] == symbol;
}

bool BoardController::checkRightHorizontal(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell + spiralLevel;
    return i < boardSize && i % lineWidth <= lineWidth - 1 && i % lineWidth > 0 && board[i] == symbol;
}

bool BoardController::checkTopVertical(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell - (lineWidth * spiralLevel);
    return i >= 0 && board[i] == symbol;
}

bool BoardController::checkBottomVertical(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell + (lineWidth * spiralLevel);
    return i < boardSize && board[i] == symbol;
}

bool BoardController::checkTopLeftDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell - (lineWidth * spiralLevel) - (1 * spiralLevel);
    return i >= 0 && i%lineWidth >= 0 && i%lineWidth < lineWidth-1 && board[i] == symbol;
}

bool BoardController::checkTopRightDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell - (lineWidth * spiralLevel) + (1 * spiralLevel);
    return i >= 0 && i%lineWidth <= lineWidth-1 && i%lineWidth > 0 && board[i] == symbol;
}

bool BoardController::checkBottomLeftDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell + (lineWidth * spiralLevel) - (1 * spiralLevel);
    return i < boardSize && i%lineWidth >= 0 && i%lineWidth < lineWidth-1 && board[i] == symbol;
}

bool BoardController::checkBottomRightDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol) {
    int i = currentCell + (lineWidth * spiralLevel) + (1 * spiralLevel);
    return i < boardSize && i%lineWidth <= lineWidth-1 && i%lineWidth > 0 && board[i] == symbol;
}

bool BoardController::validate(unsigned int cellIndex, char playerSymbol) {
    unsigned int horizontalLeftFilled = 0;
    unsigned int horizontalRightFilled = 0;
    unsigned int verticalTopFilled = 0;
    unsigned int verticalBottomFilled = 0;
    unsigned int diagonalTopLeftFilled = 0;
    unsigned int diagonalTopRightFilled = 0;
    unsigned int diagonalBottomLeftFilled = 0;
    unsigned int diagonalBottomRightFilled = 0;
    unsigned int incrementsCount = 0;


    board[cellIndex] = playerSymbol;
    cellFilledCount++;

    for (unsigned int spiralLevel = 1; symbolsCountToWin > spiralLevel; spiralLevel++) {
        const unsigned int oldIncrementsCount = incrementsCount;
        if (horizontalLeftFilled == spiralLevel-1 &&
            checkLeftHorizontal(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            horizontalLeftFilled++;
        }

        if (horizontalRightFilled == spiralLevel-1 &&
            checkRightHorizontal(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            horizontalRightFilled++;
        }

        if (verticalTopFilled == spiralLevel-1 &&
            checkTopVertical(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            verticalTopFilled++;
        }

        if (verticalBottomFilled == spiralLevel-1 &&
            checkBottomVertical(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            verticalBottomFilled++;
        }

        if (diagonalTopLeftFilled == spiralLevel-1 &&
            checkTopLeftDiagonal(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            diagonalTopLeftFilled++;
        }

        if (diagonalTopRightFilled == spiralLevel-1 &&
            checkTopRightDiagonal(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            diagonalTopRightFilled++;
        }

        if (diagonalBottomLeftFilled == spiralLevel-1 &&
            checkBottomLeftDiagonal(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            diagonalBottomLeftFilled++;
        }

        if (diagonalBottomRightFilled == spiralLevel-1 &&
            checkBottomRightDiagonal(cellIndex, spiralLevel, playerSymbol)) {
            incrementsCount++;
            diagonalBottomRightFilled++;
        }

        if (oldIncrementsCount == incrementsCount)
            return false;

        if (horizontalLeftFilled + horizontalRightFilled >= symbolsCountToWin-1 ||
            verticalTopFilled + verticalBottomFilled >= symbolsCountToWin-1 ||
            diagonalTopLeftFilled + diagonalBottomRightFilled >= symbolsCountToWin-1 ||
            diagonalTopRightFilled + diagonalBottomLeftFilled >= symbolsCountToWin-1) {
            return true;
        }
    }

    return false;
}

BoardController::~BoardController() {
    board.clear();
}
