//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#ifndef XO_ONLINE_ISCREEN_H
#define XO_ONLINE_ISCREEN_H

#include <QWidget>

class IScreen {
public:
    IScreen() = default;
    virtual QLayout* createLayout() = 0;

    int widgetWidth = 0;
    int widgetHeight = 0;

};
#endif //XO_ONLINE_ISCREEN_H
