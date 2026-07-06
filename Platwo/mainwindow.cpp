#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custommessagebox.h"
#include "editprofilewindow.h"
#include "usermanager.h"
#include "gamewindow.h"
#include <QApplication>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    selectedGame = None;
    ui->gameTitle->setText("Welcome, " + UserManager::currentUser.name + "!");
    ui->gameDescription->setText("Choose one of the games from the menu.");
    QPixmap logo(":/images/images/capollo.jpg");
    ui->gameImage->setPixmap(logo.scaled( ui->gameImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->gameImage->setAlignment(Qt::AlignCenter);
    ui->startGameButton->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showBoxes() {
    selectedGame = Boxes;
    ui->gameTitle->setText("Boxes and Dots");
    ui->gameDescription->setText( "Connect dots to complete boxes and earn more points than your opponent.");
    QPixmap image(":/images/images/boxes.jpg");
    ui->gameImage->setPixmap( image.scaled( ui->gameImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->startGameButton->setEnabled(true);
}

void MainWindow::showMorris() {
    selectedGame = Morris;
    ui->gameTitle->setText("Nine Men's Morris");
    ui->gameDescription->setText( "Create mills and capture your opponent's pieces to win.");
    QPixmap image(":/images/images/morris.jpg");
    ui->gameImage->setPixmap( image.scaled( ui->gameImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->startGameButton->setEnabled(true);
}

void MainWindow::showFanorona() {
    selectedGame = Fanorona;
    ui->gameTitle->setText("Fanorona");
    ui->gameDescription->setText( "Traditional strategy game from Madagascar with unique capture rules.");
    QPixmap image(":/images/images/fanorona.jpg");
    ui->gameImage->setPixmap( image.scaled( ui->gameImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->startGameButton->setEnabled(true);
}

void MainWindow::on_boxesButton_clicked() {
    showBoxes();
}

void MainWindow::on_morrisButton_clicked() {
    showMorris();
}

void MainWindow::on_fanoronaButton_clicked() {
    showFanorona();
}

void MainWindow::on_startGameButton_clicked() {
    if(selectedGame == None) {
        CustomMessageBox::warning( this, "Game", "Please select a game first.");
        return;
    }
    GameWindow *gameWindow = nullptr;

    switch(selectedGame) {
    case Boxes:
        gameWindow = new GameWindow(GameWindow::Boxes);
        break;
    case Morris:
        gameWindow = new GameWindow(GameWindow::Morris);
        break;
    case Fanorona:
        gameWindow = new GameWindow(GameWindow::Fanorona);
        break;
    default:
        return;
    }
    gameWindow->show();
    close();
}

void MainWindow::on_profileButton_clicked() {
    EditProfileWindow *edit = new EditProfileWindow();
    edit->show();
    close();
}

void MainWindow::on_exitButton_clicked() {
    QApplication::quit();
}