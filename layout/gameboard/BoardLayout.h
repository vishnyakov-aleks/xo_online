//
// Created by Aleksey Vishnyakov on 2019-02-21.
//

#ifndef XO_ONLINE_BOARDWIDGET_H
#define XO_ONLINE_BOARDWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "BoardController.h"

class BoardLayout: public QGridLayout {
public:
    explicit BoardLayout(QWidget *parent = nullptr);
    ~BoardLayout() override;

    void setController(BoardController *controller);

private:
    BoardController * controller;
    void onCellClicked(unsigned int i, QPushButton *btn);
};


#endif //XO_ONLINE_BOARDWIDGET_H
