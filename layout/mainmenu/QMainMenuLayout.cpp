//
// Created by Aleksey Vishnyakov on 2019-02-19.
//

#include <QPushButton>
#include "QMainMenuLayout.h"
#include "../../routing/Router.h"
#include "../boardsettings/BoardSettingsScreen.h"

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
    Router::getInstance().replaceScreen(new BoardSettingsScreen());

}

void QMainMenuLayout::startServer() {

}

void QMainMenuLayout::findServers() {

}

QMainMenuLayout::~QMainMenuLayout() = default;


