#include "usermanager.h"
#include "filemanager.h"
QVector<User> UserManager::users;
User UserManager::currentUser;

void UserManager::load() {
    users = FileManager::loadUsers();
}

void UserManager::save() {
    FileManager::saveUsers(users);
}

bool UserManager::usernameExists(QString username) {
    for(const User &user : users) {
        if(user.username == username){
            return true;
        }
    }

 return false;
}

bool UserManager::phoneExists(QString phone) {
    for(const User &user : users) {
        if(user.phone == phone){
            return true;
        }
    }

    return false;
}

bool UserManager::emailExists(QString email) {
    for(const User &user : users) {
        if(user.email == email){
            return true;
        }
    }

 return false;
}

// این قسمتو واسه ادیت پروفایل اضافع کردم

bool UserManager::usernameExistsExceptCurrent(QString username) {
    for(const User &user : users) {
        if(user.username == username && user.username != currentUser.username){
            return true;
        }
    }

 return false;
}

bool UserManager::phoneExistsExceptCurrent(QString phone) {
    for(const User &user : users) {
        if(user.phone == phone && user.username != currentUser.username){
            return true;
        }
    }

 return false;
}

bool UserManager::emailExistsExceptCurrent(QString email){
    for(const User &user : users) {
        if(user.email == email && user.username != currentUser.username){
            return true;
        }
    }

 return false;
}

bool UserManager::registerUser(const User &user) {
    load();
    if(usernameExists(user.username)){
        return false;
    }
    if(phoneExists(user.phone)){
        return false;
    }
    if(emailExists(user.email)){
        return false;
    }
        users.push_back(user);
        save();
        return true;
}

bool UserManager::login(QString username, QString passwordHash) {
    load();
   for(const User &user : users) {
        if(user.username == username && user.passwordHash == passwordHash){
            currentUser = user;
            return true;
        }
    }
 return false;
}

bool UserManager::changePassword(QString phone, QString newPasswordHash) {
    load();
    for(User &user : users) {
        if(user.phone == phone) {
            user.passwordHash = newPasswordHash;
            save();
            return true;
        }
    }

 return false;
}

User* UserManager::findUser(QString username) {
    for(User &user : users) {
        if(user.username == username){
            return &user;
        }
    }

 return nullptr;
}

bool UserManager::updateUser(const User &newUser) {
    load();
     for(User &user : users){
        if(user.username == currentUser.username){
            user = newUser;
            currentUser = newUser;
            save();
            return true;
        }
    }

 return false;
}