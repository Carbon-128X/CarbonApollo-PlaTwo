#include "morrisboardwindow.h"
#include "ui_morrisboardwindow.h"

MorrisBoardWindow::MorrisBoardWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MorrisBoardWindow)
{
    ui->setupUi(this);
}

MorrisBoardWindow::~MorrisBoardWindow()
{
    delete ui;
}
