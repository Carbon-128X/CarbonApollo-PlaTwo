#include "widget.h"
#include <QApplication>
#include "usermanager.h"
#include <QFile>
#include <QDebug>
#include <QDir>
int main(int argc, char *argv[])
{

    qDebug() << "ROOT:";
    qDebug() << QDir(":/").entryList(QDir::AllEntries);

    qDebug() << "IMAGES:";
    qDebug() << QDir(":/images").entryList(QDir::AllEntries);

    QApplication a(argc, argv);
    UserManager::load();

    Widget w;
    w.show();

    return a.exec();
}