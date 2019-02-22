//
// Created by Aleksey Vishnyakov on 2019-02-21.
//

#ifndef XO_ONLINE_STEPVALIDATOR_H
#define XO_ONLINE_STEPVALIDATOR_H


#include <vector>

class BoardController {
public:
    BoardController(unsigned int lineWidth, unsigned int symbolsCountToWin);
    ~BoardController();
    int STEP_VALIDATOR_VERSION = 1;
    bool validate(unsigned int cellIndex, char playerSymbol);

public:
    std::vector<char> board;
    unsigned int boardSize;
    unsigned int lineWidth;
    unsigned int symbolsCountToWin;
    unsigned int cellFilledCount = 0;
    unsigned int playerRun = 1;


private:
    bool checkLeftHorizontal(unsigned int currentCell, unsigned int spiralLevel, char symbol);
    bool checkRightHorizontal(unsigned int currentCell, unsigned int spiralLevel, char symbol);
    bool checkTopVertical(unsigned int currentCell, unsigned int spiralLevel, char symbol);
    bool checkBottomVertical(unsigned int currentCell, unsigned int spiralLevel, char symbol);
    bool checkTopLeftDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol);
    bool checkTopRightDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol);
    bool checkBottomLeftDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol);
    bool checkBottomRightDiagonal(unsigned int currentCell, unsigned int spiralLevel, char symbol);

};


#endif //XO_ONLINE_STEPVALIDATOR_H
