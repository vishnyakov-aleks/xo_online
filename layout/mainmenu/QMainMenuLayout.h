//
// Created by Aleksey Vishnyakov on 2019-02-19.
//

#ifndef XO_ONLINE_MAINMENU_H
#define XO_ONLINE_MAINMENU_H


#include <QMainWindow>
#include <QGridLayout>

class QMainMenuLayout : public QVBoxLayout {
public:
    explicit QMainMenuLayout(QWidget *parent = nullptr);
    ~QMainMenuLayout() override;

private:
    void openNewGame();
    void startServer();
    void findServers();

};


#endif //XO_ONLINE_MAINMENU_H
