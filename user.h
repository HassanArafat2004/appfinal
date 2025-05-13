#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:
    QString username;
    QString password;
    QString email;

    User(const QString& u, const QString& p, const QString& e = "");
    virtual ~User();
};

#endif
