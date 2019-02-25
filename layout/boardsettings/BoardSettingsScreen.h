//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#ifndef XO_ONLINE_BOARDSETTINGSSCREEN_H
#define XO_ONLINE_BOARDSETTINGSSCREEN_H


#include "../../routing/IScreen.h"

class BoardSettingsScreen : public IScreen {
public:
    explicit BoardSettingsScreen(bool isLocalGame);
    QLayout *createLayout() override;

private:
    bool isLocalGame;
};


#endif //XO_ONLINE_BOARDSETTINGSSCREEN_H
