#ifndef EDITPROFILEWINDOW_H
#define EDITPROFILEWINDOW_H
#include <QWidget>

namespace Ui {
class EditProfileWindow;
}

class EditProfileWindow : public QWidget {
    Q_OBJECT

public:
    explicit EditProfileWindow(QWidget *parent = nullptr);
    ~EditProfileWindow();

private slots:
    void on_saveButton_clicked();
    void on_backButton_clicked();

private:
   Ui::EditProfileWindow *ui;
   void loadUserData();
   bool validateInput();

};

#endif // EDITPROFILEWINDOW_H