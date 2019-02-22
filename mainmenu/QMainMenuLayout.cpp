//
// Created by Aleksey Vishnyakov on 2019-02-19.
//

#include <QPushButton>
#include <iostream>
#include <QObjectCleanupHandler>
#include "QMainMenuLayout.h"
#include "../gameboard/BoardController.h"
#include "../gameboard/BoardLayout.h"
#include "../routing/Router.h"

QMainMenuLayout::QMainMenuLayout(QWidget *parent) :
        QVBoxLayout(parent) {
    setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    auto *startNewGameButton = new QPushButton("Start new game");
    addWidget(startNewGameButton);
    connect(startNewGameButton, &QPushButton::clicked, [=]{
        openNewGame();
    });

    auto *findServerButton = new QPushButton("Search for the servers");
    addWidget(findServerButton);


    auto *startServerButton = new QPushButton("Start server");
    addWidget(startServerButton);
}

void QMainMenuLayout::openNewGame() {
    auto boardController = new BoardController(5, 3);
    Router::getInstance().setBoardScreen(boardController);

}

void QMainMenuLayout::startServer() {

}

void QMainMenuLayout::findServers() {

}

QMainMenuLayout::~QMainMenuLayout() = default;


