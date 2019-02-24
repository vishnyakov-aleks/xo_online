//
// Created by Aleksey Vishnyakov on 2019-02-24.
//

#ifndef XO_ONLINE_GAMESETTINGSLAYOUT_H
#define XO_ONLINE_GAMESETTINGSLAYOUT_H


#include <QVBoxLayout>

class BoardSettingsLayout : public QVBoxLayout {
public:
    explicit BoardSettingsLayout(QWidget *parent = nullptr);

    ~BoardSettingsLayout() override;
};


#endif //XO_ONLINE_GAMESETTINGSLAYOUT_H
