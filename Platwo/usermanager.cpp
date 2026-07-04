#include "usermanager.h"
//#include "filemanager.h"
QVector<User> UserManager::users;






bool UserManager::usernameExists(QString username) {
    for (const User &user : users) {
        if (user.username == username)
            return true;
    }

    return false;
}

bool UserManager::phoneExists(QString phone) {
    for (const User &user : users) {
        if (user.phone == phone)
            return true;
    }

    return false;
}

bool UserManager::registerUser(const User &user) {
    if (usernameExists(user.username)){
        return false;
    }
    if (phoneExists(user.phone)){
        return false;
    }
    users.push_back(user);
    save();
    return true;
}

bool UserManager::login(QString username, QString passwordHash) {
    for (const User &user : users) {
        if (user.username == username && user.passwordHash == passwordHash) {
            return true;
        }
    }

    return false;
}

bool UserManager::changePassword(QString phone, QString newPasswordHash){
    for (User &user : users) {
        if (user.phone == phone) {
            user.passwordHash = newPasswordHash;
            save();
            return true;
        }
    }

 return false;
}