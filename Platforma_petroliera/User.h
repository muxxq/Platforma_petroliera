#ifndef USER_H
#define USER_H

#include "Account.h"
#include <iostream>

class User : public Account {
public:
    User(const std::string& user, const std::string& pass);
    bool login(const std::string& user, const std::string& pass) override;
    void displayRole() const override;
};

#endif // USER_H
