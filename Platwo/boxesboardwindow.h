#ifndef BOXESBOARDWINDOW_H
#define BOXESBOARDWINDOW_H
#include <QTimer>
#include <QWidget>
#include "logic/dotsAndBoxes.h"

namespace Ui {
class BoxesBoardWindow;
}

class BoxesBoardWindow : public QWidget {
    Q_OBJECT

public:
    explicit BoxesBoardWindow( int boardSize, bool timerEnabled, int gameTime, QWidget *parent = nullptr );
    ~BoxesBoardWindow();


private:

    Ui::BoxesBoardWindow *ui;
    DotsAndBoxes *game = nullptr;
    void initializeWindow();
    void initializePlayers();
    void initializeButtons();

    void updateTurn(int player);
    void updateScores(int p1,int p2);
    void updateTimer(int seconds);
    int boardSize;
    bool timerEnabled;
    int gameTime;

    QTimer *turnTimer = nullptr;
    int turnTime = 0;
    int remainingTime = 0;
    void startTurnTimer();
private slots:
    void on_exitButton_clicked();
    void on_restartButton_clicked();
    void on_saveButton_clicked();
    void refreshGameUI();
    void onTimerTick();


};

#endif