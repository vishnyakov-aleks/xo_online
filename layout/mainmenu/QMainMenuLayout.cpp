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
    connect(findServerButton, &QPushButton::clicked, [=] {
        findServers();
    });
    addWidget(findServerButton);


    auto *startServerButton = new QPushButton("Start server");
    connect(startServerButton, &QPushButton::clicked, [=] {
        startServer();
    });
    addWidget(startServerButton);
}

void QMainMenuLayout::openNewGame() {
    Router::getInstance().navigateTo(new BoardSettingsScreen(true));

}

void QMainMenuLayout::startServer() {
    Router::getInstance().navigateTo(new BoardSettingsScreen(false));
}

void QMainMenuLayout::findServers() {

}

QMainMenuLayout::~QMainMenuLayout() = default;


