#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget {
    Q_OBJECT
public:
    enum GameType {
        Boxes,
        Morris,
        Fanorona
    };
    explicit GameWindow(GameType game, QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void on_backButton_clicked();
private:
    Ui::GameWindow *ui;
    GameType currentGame;
    void loadGameInformation();
};

#endif // GAMEWINDOW_H