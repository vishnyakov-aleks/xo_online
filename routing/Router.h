//
// Created by Aleksey Vishnyakov on 2019-02-22.
//

#ifndef XO_ONLINE_ROUTER_H
#define XO_ONLINE_ROUTER_H


#include <QWidget>
#include <QPropertyAnimation>
#include "../gameboard/BoardController.h"

class Router
{
private:
    Router() = default;
    Router( const Router&);
    Router& operator=( Router& ) = delete;
    QPropertyAnimation* propertyAnimation;
    QWidget * rootWidget;
    void clearOldLayout();
    void replaceWithAnimResize(QLayout * layout, int newWidth, int newHeight);
public:
    static Router& getInstance() {
        static Router  instance;
        return instance;
    }

    void init(QWidget *qWidget);


    /* SCREENS */
    void setMainMenuScreen();
    void setBoardScreen(BoardController * controller);

};

#endif //XO_ONLINE_ROUTER_H
