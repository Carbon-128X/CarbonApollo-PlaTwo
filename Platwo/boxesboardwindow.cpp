#include "boxesboardwindow.h"
#include "ui_boxesboardwindow.h"
#include "custommessagebox.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>
BoxesBoardWindow::BoxesBoardWindow( int board, bool timer, int time,
     const QString &p1Name, const QString &p2Name,
     const QColor &p1Color, const QColor &p2Color,
     QWidget *parent) : QWidget(parent), ui(new Ui::BoxesBoardWindow), boardSize(board), timerEnabled(timer), gameTime(time),
     player1Name(p1Name),
     player2Name(p2Name),
     player1Color(p1Color),
     player2Color(p2Color)
{
    ui->setupUi(this);
    turnTime = gameTime;
    remainingTime = turnTime;
    turnTimer = new QTimer(this);
    connect( turnTimer, &QTimer::timeout, this, &BoxesBoardWindow::onTimerTick );
    ui->backgroundLabel->setPixmap( QPixmap(":/images/images/454545.png"));
    ui->backgroundLabel->setScaledContents(true);

    //---------------------------------

    ui->backgroundLabel->lower();
    ui->boardWidget->raise();
    game = new DotsAndBoxes(boardSize, boardSize);

    //------------------------------------------------

    ui->boardWidget->setGame(game);
    connect( ui->boardWidget, &BoardWidget::boardChanged, this, &BoxesBoardWindow::refreshGameUI );
    initializeWindow();
}

BoxesBoardWindow::~BoxesBoardWindow() {
    if(turnTimer){
        turnTimer->stop();
    }
    delete game;
    delete ui;
}

void BoxesBoardWindow::initializeWindow() {
    initializePlayers();
    initializeButtons();
    updateTurn(game->currentPlayer());

    updateScores( game->score(1), game->score(2));

    if(timerEnabled){
        updateTimer(gameTime);
    }
    else{
        ui->timerLabel->setText("--:--");
    }
}

void BoxesBoardWindow::initializePlayers() {
    QString hostName = player1Name.left(4);
    QString guestName = player2Name.left(4);
    ui->player1NameLabel->setText(hostName);
    ui->player2NameLabel->setText(guestName);
    ui->player1ColorLabel->setText("꧁                     ꧂");
    ui->player2ColorLabel->setText("꧁                     ꧂ ");
    ui->player1ColorLabel->setStyleSheet(QString("color:%1;").arg(player1Color.name()));
    ui->player2ColorLabel->setStyleSheet( QString("color:%1;").arg(player2Color.name()));
    ui->player1ScoreLabel->setText( QString("Score : %1").arg(game->score(1)));
    ui->player2ScoreLabel->setText( QString("Score : %1").arg(game->score(2)));
    ui->boardWidget->setPlayers( hostName, guestName, player1Color, player2Color);
}

void BoxesBoardWindow::initializeButtons() {
    ui->saveButton->setCursor(Qt::PointingHandCursor);
    ui->restartButton->setCursor(Qt::PointingHandCursor);
    ui->exitButton->setCursor(Qt::PointingHandCursor);
    startTurnTimer();
}

void BoxesBoardWindow::updateTurn(int player) {
    ui->currentTurnLabel->setText( QString("Player %1").arg(player));
}

void BoxesBoardWindow::updateScores(int p1,int p2) {
    ui->player1ScoreLabel->setText( QString("Score : %1").arg(p1));
    ui->player2ScoreLabel->setText( QString("Score : %1").arg(p2));
}

void BoxesBoardWindow::updateTimer(int seconds) {
    int minute = seconds / 60;
    int second = seconds % 60;
    ui->timerLabel->setText( QString("%1:%2").arg(minute,2,10,QChar('0')).arg(second,2,10,QChar('0')) );
}

void BoxesBoardWindow::on_saveButton_clicked() {
    CustomMessageBox::information( this, "Save", "Save system will be implemented later.");
}

void BoxesBoardWindow::on_restartButton_clicked() {
    //auto result = CustomMessageBox::question(this,"Restart", "Restart current game?");
   // if(result==CustomMessageBox::Yes) {
        delete game;
       game = new DotsAndBoxes(boardSize, boardSize);
        ui->boardWidget->setGame(game);
        startTurnTimer();
        updateTurn(game->currentPlayer());
        updateScores( game->score(1), game->score(2));

        if(timerEnabled){
            updateTimer(gameTime);
        }
        else{
            ui->timerLabel->setText("--:--");
        }
   // }
}

void BoxesBoardWindow::on_exitButton_clicked() {
    close();
}

void BoxesBoardWindow::refreshGameUI() {
    updateTurn(game->currentPlayer());
    updateScores(game->score(1), game->score(2));
    startTurnTimer();
    ui->boardWidget->update();

    if(game->isGameOver()) {
        QString text;
        int winner = game->winner();
        if(winner == 0) {
            text = "Game Finished!\n\nDraw!";
        }
        else {
            text = QString("Game Finished!\n\nWinner : Player %1").arg(winner);
        }
        turnTimer->stop();
        CustomMessageBox::information( this, "Game Over", text );
    }
}
void BoxesBoardWindow::startTurnTimer() {
    if(!timerEnabled){
        return;
    }
    turnTimer->stop();
    remainingTime = turnTime;
    updateTimer(remainingTime);
    turnTimer->start(1000);
}

void BoxesBoardWindow::onTimerTick() {
    remainingTime--;
    updateTimer(remainingTime);
    if(remainingTime <= 0) {
        turnTimer->stop();
        game->forceNextPlayer();
        updateTurn(game->currentPlayer());
        startTurnTimer();
        ui->boardWidget->update();
    }
}
