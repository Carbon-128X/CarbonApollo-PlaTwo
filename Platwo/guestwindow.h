#ifndef GUESTWINDOW_H
#define GUESTWINDOW_H
#include <QWidget>
#include "gamewindow.h"

namespace Ui {
class GuestWindow;
}

class GuestWindow : public QWidget {
    Q_OBJECT

public:
    explicit GuestWindow(GameWindow::GameType game, QWidget *parent = nullptr);
    ~GuestWindow();

private slots:
    void on_joinRoomButton_clicked();
    void on_backButton_clicked();

private:
    Ui::GuestWindow *ui;
    GameWindow::GameType currentGame;
    void initializeWindow();
    bool validateInput();
};

#endif // GUESTWINDOW_H