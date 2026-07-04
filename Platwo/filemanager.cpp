#include "filemanager.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

void FileManager::saveUsers(const QVector<User> &users){
    QJsonArray array;
    for(const User &user : users){
        array.append(user.toJson());
    }
    QJsonDocument document(array);
    QFile file("users.json");

    if(file.open(QIODevice::WriteOnly)){

        file.write(document.toJson());
        file.close();
    }
}

QVector<User> FileManager::loadUsers(){
    QVector<User> users;
    QFile file("users.json");

    if(!file.exists()){
        return users;
    }

    if(file.open(QIODevice::ReadOnly)){
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument document = QJsonDocument::fromJson(data);
        QJsonArray array = document.array();

        for(const QJsonValue &value : array){
            users.push_back(User::fromJson(value.toObject()));
        }
    }

    return users;
}