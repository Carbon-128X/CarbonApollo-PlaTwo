#include "editprofilewindow.h"
#include "ui_editprofilewindow.h"

editprofilewindow::editprofilewindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editprofilewindow)
{
    ui->setupUi(this);
}

editprofilewindow::~editprofilewindow()
{
    delete ui;
}
