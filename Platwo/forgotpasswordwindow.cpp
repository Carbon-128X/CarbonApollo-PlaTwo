#include "forgotpasswordwindow.h"
#include "ui_forgotpasswordwindow.h"
#include "loginwindow.h"
#include "usermanager.h"
#include "security.h"
#include <QMessageBox>
#include <QRegularExpression>
ForgotPasswordWindow::ForgotPasswordWindow(QWidget *parent): QWidget(parent), ui(new Ui::ForgotPasswordWindow){
    ui->setupUi(this);
}

ForgotPasswordWindow::~ForgotPasswordWindow(){
    delete ui;
}
void ForgotPasswordWindow::on_backButton_clicked() {
    LoginWindow *login = new LoginWindow();

    login->show();

    this->close();
}


void ForgotPasswordWindow::on_changePasswordButton_clicked()
{
    QString phone = ui->phoneEdit->text().trimmed();
    QString password = ui->newPasswordEdit->text();
    QString confirm = ui->confirmPasswordEdit->text();

    if(phone.isEmpty() || password.isEmpty() || confirm.isEmpty()){
        QMessageBox::warning(this, "Error", "Please fill all fields.");
        return;
    }

    if(password != confirm){
        QMessageBox::warning(this, "Error", "Passwords do not match.");
        return;
    }

    // اینجا شماره تلفن را چک میکنم
    QRegularExpression phoneRegex("^09\\d{9}$");

    if(!phoneRegex.match(phone).hasMatch()){
        QMessageBox::warning(this, "Error", "Invalid phone number.");
        return;
    }

    // رمز باید قوی باشد پس من هم کاراکتر ها و ععداشو چک میکنم
    QRegularExpression passwordRegex(
        "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&]).{8,}$");

    if(!passwordRegex.match(password).hasMatch()){
        QMessageBox::warning(this,"Weak Password","Password must contain:\n""- At least 8 characters\n""- One uppercase letter\n"
            "- One lowercase letter\n" "- One number\n" "- One special character");
        return;
    }

    QString hash = Security::hashPassword(password);

    if(UserManager::changePassword(phone, hash)){
        QMessageBox::information(this, "Success", "Password changed successfully.");

        LoginWindow *login = new LoginWindow();
        login->show();

        this->close();
    }
    else{
        QMessageBox::warning(this, "Error", "Phone number not found.");
    }
}