#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custommessagebox.h"
#include <QPixmap>
#include <QMessageBox>
#include "editprofilewindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    selectedGame = None;
    ui->gameTitle->setText("Welcome to PLATWO");
    ui->gameDescription->setText( "Choose one of the games from the menu.");
    ui->gameImage->clear();
    ui->startGameButton->setEnabled(false);
}
MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::showBoxes(){
    selectedGame = Boxes;
    ui->gameTitle->setText("Boxes and Dots");
    ui->gameDescription->setText("Connect dots to complete boxes and earn more points than your opponent.");

 QPixmap image(":/images/images/boxes.jpg");

 ui->gameImage->setPixmap( image.scaled( ui->gameImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

 ui->startGameButton->setEnabled(true);
}

void MainWindow::showMorris(){
    selectedGame = Morris;
    ui->gameTitle->setText("Nine Men's Morris");
    ui->gameDescription->setText( "Create mills and capture your opponent's pieces to win.");
    QPixmap image(":/images/images/morris.jpg");
    ui->gameImage->setPixmap( image.scaled( ui->gameImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->startGameButton->setEnabled(true);
}


void MainWindow::showFanorona(){
    selectedGame = Fanorona;
    ui->gameTitle->setText("Fanorona");
    ui->gameDescription->setText("Traditional strategy game from Madagascar with unique capture rules.");
    QPixmap image(":/images/images/fanorona.jpg");

    ui->gameImage->setPixmap(image.scaled( ui->gameImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->startGameButton->setEnabled(true);
}


void MainWindow::on_boxesButton_clicked(){
    showBoxes();
}

void MainWindow::on_morrisButton_clicked(){
    showMorris();
}

void MainWindow::on_fanoronaButton_clicked(){
    showFanorona();
}

void MainWindow::on_startGameButton_clicked(){
    switch(selectedGame) {
    case Boxes:
        CustomMessageBox::information(this,"Game","Boxes and Dots will start.");
     break;

    case Morris:

        CustomMessageBox::information( this, "Game", "Nine Men's Morris will start.");
        break;

    case Fanorona:

        CustomMessageBox::information(this, "Game", "Fanorona will start.");
     break;

    default:

        CustomMessageBox::warning(this, "Game", "Please select a game first.");
     break;
    }
}

void MainWindow::on_profileButton_clicked()
{
    editprofilewindow *edit = new editprofilewindow();

    edit->show();

    close();
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}