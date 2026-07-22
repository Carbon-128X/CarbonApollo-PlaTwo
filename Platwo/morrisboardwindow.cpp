#include "morrisboardwindow.h"
#include "ui_morrisboardwindow.h"
#include "custommessagebox.h"
MorrisBoardWindow::MorrisBoardWindow( bool timer, int time, const QString &p1Name, const QString &p2Name, const QColor &p1Color, const QColor &p2Color, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MorrisBoardWindow),
    timerEnabled(timer),
    gameTime(time),
    player1Name(p1Name),
    player2Name(p2Name),
    player1Color(p1Color),
    player2Color(p2Color) {
    ui->setupUi(this);

    turnTime = gameTime;
    remainingTime = turnTime;

    turnTimer = new QTimer(this);
    connect( turnTimer, &QTimer::timeout, this, &MorrisBoardWindow::onTimerTick );

    game = new NineMensMorris();
    ui->boardWidget->setGame(game);

    connect(ui->boardWidget,&MorrisBoardWidget::boardChanged,this,&MorrisBoardWindow::refreshGameUI);
    ui->backgroundLabel->setPixmap( QPixmap(":/images/images/454545.png"));
    initializeWindow();
}

MorrisBoardWindow::~MorrisBoardWindow() {
    delete game;
    delete ui;
}
void MorrisBoardWindow::initializeWindow() {
    initializePlayers();
    initializeButtons();
    updateTurn(game->currentPlayer());

    if(timerEnabled){
        updateTimer(gameTime);
    }
    else{
        ui->timerLabel->setText("--:--");
    }
}

void MorrisBoardWindow::initializePlayers() {
    ui->player1NameLabel->setText(player1Name.left(4));
    ui->player2NameLabel->setText(player2Name.left(4));
    ui->player1ColorLabel->setText("꧁                     ꧂");
    ui->player2ColorLabel->setText("꧁                     ꧂");

    ui->player1ColorLabel->setStyleSheet( QString("color:%1;").arg(player1Color.name()));
    ui->player2ColorLabel->setStyleSheet( QString("color:%1;").arg(player2Color.name()));
}

void MorrisBoardWindow::initializeButtons() {
    ui->saveButton->setCursor(Qt::PointingHandCursor);
    ui->restartButton->setCursor(Qt::PointingHandCursor);
    ui->exitButton->setCursor(Qt::PointingHandCursor);

    if(timerEnabled){
        startTurnTimer();
    }
}

void MorrisBoardWindow::updateTurn(int player) {
    ui->currentTurnLabel->setText( QString("Player %1").arg(player));
}

void MorrisBoardWindow::updateTimer(int seconds) {
    int minute = seconds / 60;
    int second = seconds % 60;
    ui->timerLabel->setText(QString("%1:%2").arg(minute,2,10,QChar('0')).arg(second,2,10,QChar('0')));
}

void MorrisBoardWindow::startTurnTimer() {
    if(!timerEnabled){
        return;
    }

    turnTimer->stop();
    remainingTime = turnTime;
    updateTimer(remainingTime);
    turnTimer->start(1000);
}

void MorrisBoardWindow::onTimerTick() {
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


void MorrisBoardWindow::refreshGameUI() {
    updateTurn(game->currentPlayer());
    startTurnTimer();
    ui->boardWidget->update();
    if(game->isGameOver()) {
        turnTimer->stop();
        QString text;

        if(game->winner()==0){
            text="Draw!";
        }
        else{
            text=QString("Winner : Player %1") .arg(game->winner());
        }
        CustomMessageBox::information( this,"Game Over", text);
    }
}

void MorrisBoardWindow::on_restartButton_clicked() {
    turnTimer->stop();
    delete game;

    game = new NineMensMorris();
    ui->boardWidget->setGame(game);
    updateTurn(game->currentPlayer());
    if(timerEnabled){
        startTurnTimer();
    }
    ui->boardWidget->update();
}

void MorrisBoardWindow::on_exitButton_clicked() {
    close();
}

void MorrisBoardWindow::on_saveButton_clicked() {
    CustomMessageBox::information( this,"Save", "Save system will be implemented later.");
}