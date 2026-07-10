#include "hostwindow.h"
#include "ui_hostwindow.h"
#include "gamewindow.h"
#include <QIntValidator>
#include "boxesboardwindow.h"

HostWindow::HostWindow(GameWindow::GameType game, QWidget *parent): QWidget(parent),ui(new Ui::HostWindow),currentGame(game){
    ui->setupUi(this);

    videoBackground = new VideoBackgroundWidget(this);
    videoBackground->setGeometry(rect());
    videoBackground->lower();
    videoBackground->setVideo(":/images/images/Background.mp4");

    initializeWindow();
}

HostWindow::~HostWindow() {
    delete ui;
}

void HostWindow::initializeWindow() {
    ui->statusLabel->hide();
    ui->timeEdit->setEnabled(false);
    ui->timeEdit->setText("120");
    ui->portEdit->setPlaceholderText("e.g. 5000");
    ui->portEdit->setValidator(new QIntValidator(1024,65535,this));
    ui->timeEdit->setValidator( new QIntValidator(1,99999,this));
    if(currentGame != GameWindow::Boxes) {
        ui->boardSizeLabel->hide();
        ui->boardSizeCombo->hide();
    }
    ui->ipValueLabel->setText("--------");
}

bool HostWindow::validateInput() {
    if(ui->portEdit->text().trimmed().isEmpty()) {
        ui->statusLabel->show();
        ui->statusLabel->setText("Enter a valid port.");
        return false;
    }

    if(ui->timeLimitCheck->isChecked()) {
        if(ui->timeEdit->text().trimmed().isEmpty()) {
            ui->statusLabel->show();
            ui->statusLabel->setText("Enter game time.");
            return false;
        }
    }

 return true;
}

QString HostWindow::getLocalIP() {
    // بعداً با QNetworkInterface جایگزین می‌شود.
    return "127.0.0.1";
}

void HostWindow::on_timeLimitCheck_clicked(bool checked) {
    ui->timeEdit->setEnabled(checked);
}

void HostWindow::on_createRoomButton_clicked() {
    if(!validateInput()){
        return;
    }
    //اندازه زمین گیم
    int boardSize = 6;

    if(currentGame == GameWindow::Boxes){
        boardSize = ui->boardSizeCombo->currentText().split(" ").first().toInt();
    }

    // تایمر
    bool timerEnabled = ui->timeLimitCheck->isChecked();
    int gameTime = 120;

    if(timerEnabled){
        gameTime = ui->timeEdit->text().toInt();
    }
    //-----------------------------------
    BoxesBoardWindow *board = new BoxesBoardWindow( boardSize, timerEnabled, gameTime);
    board->show();
    this->close();

}

void HostWindow::on_backButton_clicked() {
    GameWindow *game = new GameWindow(currentGame);
    game->show();
    close();
}

int HostWindow::getBoardSize() const {
    return boardSize;
}

int HostWindow::getGameTime() const {
    return gameTime;
}

bool HostWindow::hasTimer() const {
    return timerEnabled;
}

void HostWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    if(videoBackground)
        videoBackground->setGeometry(rect());
}