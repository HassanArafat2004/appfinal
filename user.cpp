#include "user.h"

User::User(const QString& u, const QString& p, const QString& e) 
    : username(u), password(p), email(e) 
{
}

User::~User() 
{
} 
