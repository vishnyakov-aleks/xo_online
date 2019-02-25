//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#ifndef XO_ONLINE_BOARDSCREEN_H
#define XO_ONLINE_BOARDSCREEN_H


#include "../../routing/IScreen.h"

class BoardScreen : public IScreen {
public:
    BoardScreen(unsigned int linesCount, unsigned int cellsToWin);
    QLayout *createLayout() override;

private:
    unsigned int linesCount;
    unsigned int cellsToWin;
};


#endif //XO_ONLINE_BOARDSCREEN_H
