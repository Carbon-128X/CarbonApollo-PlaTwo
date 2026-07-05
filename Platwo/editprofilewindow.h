#ifndef EDITPROFILEWINDOW_H
#define EDITPROFILEWINDOW_H

#include <QWidget>

namespace Ui {
class editprofilewindow;
}

class editprofilewindow : public QWidget
{
    Q_OBJECT

public:
    explicit editprofilewindow(QWidget *parent = nullptr);
    ~editprofilewindow();

private:
    Ui::editprofilewindow *ui;
};

#endif // EDITPROFILEWINDOW_H
