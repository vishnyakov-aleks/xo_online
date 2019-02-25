//
// Created by Aleksey Vishnyakov on 2019-02-25.
//

#ifndef XO_ONLINE_BOARDSETTINGSCONTROLLER_H
#define XO_ONLINE_BOARDSETTINGSCONTROLLER_H


class BoardSettingsController {
public:
    explicit BoardSettingsController(bool isLocalGame);

    void startGame(unsigned int linesCount, unsigned int cellsToWin);

private:
    bool isLocalGame;
};


#endif //XO_ONLINE_BOARDSETTINGSCONTROLLER_H
