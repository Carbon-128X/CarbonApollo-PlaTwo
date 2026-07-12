#include "custommessagebox.h"
#include <QMessageBox>

void CustomMessageBox::warning(QWidget *parent,const QString &title, const QString &text){
    QMessageBox msg(parent);
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowTitle(title);
    msg.setText(text);
    msg.setStyleSheet(
        "QMessageBox{"
        "background-color:#1A1A1A;"
        "}"
        "QLabel{"
        "color:white;"
        "font-size:12pt;"
        "}"
        "QPushButton{"
        "background-color:#3A86FF;"
        "color:white;"
        "border-radius:8px;"
        "padding:6px;"
        "min-width:90px;"
        "}"
        "QPushButton:hover{"
        "background-color:#5A9CFF;"
        "}"
        );

    msg.exec();
}

void CustomMessageBox::information(QWidget *parent, const QString &title, const QString &text){
    QMessageBox msg(parent);
    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle(title);
    msg.setText(text);
    msg.setStyleSheet(
        "QMessageBox{"
        "background-color:#1A1A1A;"
        "}"
        "QLabel{"
        "color:white;"
        "font-size:12pt;"
        "}"
        "QPushButton{"
        "background-color:#3A86FF;"
        "color:white;"
        "border-radius:8px;"
        "padding:6px;"
        "min-width:90px;"
        "}"
        "QPushButton:hover{"
        "background-color:#5A9CFF;"
        "}"
        );

    msg.exec();
}

void CustomMessageBox::question(QWidget *parent, const QString &title, const QString &text){
    QMessageBox msg(parent);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowTitle(title);
    msg.setText(text);
    msg.setStyleSheet(
        "QMessageBox{"
        "background-color:#1A1A1A;"
        "}"
        "QLabel{"
        "color:white;"
        "font-size:12pt;"
        "}"
        "QPushButton{"
        "background-color:#3A86FF;"
        "color:white;"
        "border-radius:8px;"
        "padding:6px;"
        "min-width:90px;"
        "}"
        "QPushButton:hover{"
        "background-color:#5A9CFF;"
        "}"
        );

    msg.exec();
}