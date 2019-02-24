//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include "BoardSettingsLayout.h"
#include "../../routing/Router.h"
#include "../../routing/BoardScreen.h"


BoardSettingsLayout::BoardSettingsLayout(QWidget *parent) : QVBoxLayout(parent) {
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

        Router::getInstance().replaceScreen(new BoardScreen(linesCount, cellsToWin));
    });
    addWidget(startNewGameButton);
}

BoardSettingsLayout::~BoardSettingsLayout() = default;
