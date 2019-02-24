//
// Created by Aleksey Vishnyakov on 2019-02-21.
//

#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include "BoardLayout.h"
#include "../../routing/Router.h"
#include "../../routing/MainMenuScreen.h"


BoardLayout::BoardLayout(QWidget *parent) : QGridLayout(parent) {

}

void BoardLayout::setController(BoardController *controller) {
    this->controller = controller;

    for (unsigned int i = 0; i < controller->lineWidth; i++) {
        setRowStretch(i, 0);
        setColumnStretch(i, 0);
    }


    for (unsigned int i = 0; i < controller->boardSize; i++) {
        auto *btn = new QPushButton(parentWidget());
        btn->setText(" ");
        btn->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding);
        addWidget(btn);
        connect(btn, &QPushButton::clicked, [this, btn, i](){
            onCellClicked(i, btn);
        });
    }
}

void BoardLayout::onCellClicked(unsigned int i, QPushButton *btn) {
    if (!btn->isEnabled()) {
        return;
    }

    btn->setEnabled(false);
    char playerSymbol;
    unsigned int playerRan = controller->playerRun;

    if (controller->playerRun == 2) {
        playerSymbol = 'O';
        controller->playerRun = 1;
    } else {
        playerSymbol = 'X';
        controller->playerRun = 2;
    }

    btn->setText(QString(playerSymbol));

    auto hasWin = controller->validate(i, playerSymbol);

    if (hasWin) {
        int result = QMessageBox::information(parentWidget(), "Game over", ("Player " +  QString::number(playerRan) + " WIN"),
                                              QMessageBox::Ok, QMessageBox::Ok );
        if (result == QMessageBox::Ok) {
            Router::getInstance().replaceScreen(new MainMenuScreen());
            return;
        }
    } else if (controller->cellFilledCount == controller->boardSize) {
        int result = QMessageBox::information(parentWidget(), "Game over", ("Nobody won..."), QMessageBox::Ok, QMessageBox::Ok );
        if (result == QMessageBox::Ok) {
            Router::getInstance().replaceScreen(new MainMenuScreen());
            return;
        }
    }

}

BoardLayout::~BoardLayout() {
    delete controller;
}



