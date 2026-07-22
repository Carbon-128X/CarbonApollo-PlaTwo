#include "morrisboardwindow.h"
#include "ui_morrisboardwindow.h"

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

