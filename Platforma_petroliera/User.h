#ifndef USER_H
#define USER_H

#include "Account.h"
#include <iostream>

class User : public Account {
public:
    User(const string& user, const string& pass);
    bool login(const string& user, const string& pass) override;
    void displayRole() const override;
};

#endif // USER_H
