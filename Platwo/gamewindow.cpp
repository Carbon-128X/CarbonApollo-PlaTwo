#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include <QPixmap>

GameWindow::GameWindow(GameType game, QWidget *parent): QWidget(parent), ui(new Ui::GameWindow), currentGame(game) {
    ui->setupUi(this);
    loadGameInformation();
}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::loadGameInformation() {
    switch(currentGame) {
    case Boxes:
        ui->gameTitleLabel->setText("Boxes and Dots");
        ui->gameImageLabel->setPixmap( QPixmap(":/images/images/boxes.jpg").scaled( ui->gameImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        break;
     case Morris:
        ui->gameTitleLabel->setText("Nine Men's Morris");
         ui->gameImageLabel->setPixmap( QPixmap(":/images/images/morris.jpg").scaled( ui->gameImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        break;
     case Fanorona:
        ui->gameTitleLabel->setText("Fanorona");
        ui->gameImageLabel->setPixmap(QPixmap(":/images/images/fanorona.jpg").scaled( ui->gameImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        break;
    }
}

void GameWindow::on_backButton_clicked(){
    MainWindow *menu = new MainWindow();
    menu->show();
    close();
}