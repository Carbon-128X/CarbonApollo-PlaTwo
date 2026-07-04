#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"

MainMenuWindow::MainMenuWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuWindow)
{
    ui->setupUi(this);
}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
}
