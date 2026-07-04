#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QVector>
#include "user.h"

class FileManager{
public:
    static void saveUsers(const QVector<User> &users);
    static QVector<User> loadUsers();
};

#endif // FILEMANAGER_H
