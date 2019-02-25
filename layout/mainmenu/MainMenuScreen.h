//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#ifndef XO_ONLINE_MAINMENUSCREEN_H
#define XO_ONLINE_MAINMENUSCREEN_H


#include "../../routing/IScreen.h"

class MainMenuScreen : public IScreen {
public:
    MainMenuScreen();

    QLayout *createLayout() override;
};


#endif //XO_ONLINE_MAINMENUSCREEN_H
