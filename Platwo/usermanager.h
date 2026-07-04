#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <QVector>
#include "user.h"

class UserManager
{
public:
    static QVector<User> users;
    static void load();
    static void save();
    static bool registerUser(const User &user);
    static bool login(QString username,QString passwordHash);
    static bool phoneExists(QString phone);
    static bool usernameExists(QString username);
    static bool changePassword(QString phone,QString newPasswordHash);
};

#endif