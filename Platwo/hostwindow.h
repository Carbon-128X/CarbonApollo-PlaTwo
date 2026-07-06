#ifndef HOSTWINDOW_H
#define HOSTWINDOW_H
#include <QWidget>
#include "gamewindow.h"

namespace Ui {
class HostWindow;
}

class HostWindow : public QWidget {
    Q_OBJECT

public:
    explicit HostWindow(GameWindow::GameType game, QWidget *parent = nullptr);
    ~HostWindow();

private slots:
    void on_timeLimitCheck_clicked(bool checked);
    void on_createRoomButton_clicked();
    void on_backButton_clicked();

private:
    Ui::HostWindow *ui;
    GameWindow::GameType currentGame;
    void initializeWindow();
    bool validateInput();
    QString getLocalIP();
};

#endif // HOSTWINDOW_H