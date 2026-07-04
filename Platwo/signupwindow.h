#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H
#include <QWidget>

namespace Ui {
class SignupWindow;
}

class SignupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SignupWindow(QWidget *parent = nullptr);
    ~SignupWindow();

private slots:
    void on_backButton_clicked();
    void on_loginButton_clicked();
    void on_signupButton_clicked();

private:
    Ui::SignupWindow *ui;
};

#endif // SIGNUPWINDOW_H