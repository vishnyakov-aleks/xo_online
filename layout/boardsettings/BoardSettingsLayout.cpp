//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include "BoardSettingsLayout.h"
#include "../../routing/Router.h"


BoardSettingsLayout::BoardSettingsLayout(QWidget *parent) : QVBoxLayout(parent) {

}

void BoardSettingsLayout::setController(BoardSettingsController *controller) {
    this->controller = controller;

    addWidget(new QLabel("Enter lines count"));

    auto *linesCountField = new QLineEdit();
    linesCountField->setValidator(new QIntValidator(0, 99, this));
    addWidget(linesCountField);

    addWidget(new QLabel("Enter cells to win"));

    auto *cellsToWinField = new QLineEdit();
    cellsToWinField->setValidator(new QIntValidator(0, 10, this));
    addWidget(cellsToWinField);


    auto *startNewGameButton = new QPushButton("Start game");
    connect(startNewGameButton, &QPushButton::clicked, [=] {
        unsigned int linesCount = linesCountField->text().toUInt();
        unsigned int cellsToWin = cellsToWinField->text().toUInt();

        if (linesCount < 3 || cellsToWin < 2 || cellsToWin > linesCount)
            return;

        controller->startGame(linesCount, cellsToWin);
    });
    addWidget(startNewGameButton);

    auto *backButton = new QPushButton("<- Go back");
    connect(backButton, &QPushButton::clicked, [=] {
        Router::getInstance().goBack();
    });
    addWidget(backButton);
}

BoardSettingsLayout::~BoardSettingsLayout() = default;
