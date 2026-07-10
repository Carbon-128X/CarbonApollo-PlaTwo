#include "guestwindow.h"
#include "ui_guestwindow.h"
#include "gamewindow.h"
#include <QIntValidator>

GuestWindow::GuestWindow(GameWindow::GameType game, QWidget *parent) : QWidget(parent), ui(new Ui::GuestWindow), currentGame(game) {
    ui->setupUi(this);

    videoBackground = new VideoBackgroundWidget(this);
    videoBackground->setGeometry(rect());
    videoBackground->lower();
    videoBackground->setVideo(":/images/images/Background.mp4");

    initializeWindow();
}

GuestWindow::~GuestWindow( ){
    delete ui;
}

void GuestWindow::initializeWindow() {
    ui->statusLabel->hide();
    ui->ipEdit->setPlaceholderText("192.168.1.10");
    ui->portEdit->setPlaceholderText("5000");
    ui->portEdit->setValidator( new QIntValidator(1024,65535,this));
}

bool GuestWindow::validateInput() {
    if(ui->ipEdit->text().trimmed().isEmpty()) {
        ui->statusLabel->show();
        ui->statusLabel->setText("Enter server IP.");
     return false;
    }

    if(ui->portEdit->text().trimmed().isEmpty()) {
        ui->statusLabel->show();
        ui->statusLabel->setText("Enter server port.");
        return false;
    }

 return true;
}

void GuestWindow::on_joinRoomButton_clicked() {
    if(!validateInput()){
        return;
    }

    ui->statusLabel->show();
    ui->statusLabel->setText("Connecting...");
    QString ip = ui->ipEdit->text();
    int port = ui->portEdit->text().toInt();
    Q_UNUSED(ip)
    Q_UNUSED(port)

    //اینجا واسه قسمت سرور و این هاستQTcpSocket

    ui->statusLabel->setText("Connected successfully.");

    /*
    اینجا بعدا صفحه و قسمت هر بازی باز میشه
    */
}

void GuestWindow::on_backButton_clicked() {
    GameWindow *game = new GameWindow(currentGame);
    game->show();
    close();
}

void GuestWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    if(videoBackground)
        videoBackground->setGeometry(rect());
}