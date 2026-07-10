#ifndef GUESTWINDOW_H
#define GUESTWINDOW_H
#include <QWidget>
#include "gamewindow.h"
#include "videobackgroundwidget.h"
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

    VideoBackgroundWidget *videoBackground;
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // GUESTWINDOW_H