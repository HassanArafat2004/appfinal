#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:
    QString username;
    QString password;

    User() {}

    User(QString u, QString p) : username(u), password(p) {}
};

#endif
