#include "widget.h"
#include <QApplication>
#include "usermanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserManager::load();

    Widget w;
    w.show();

    return a.exec();
}