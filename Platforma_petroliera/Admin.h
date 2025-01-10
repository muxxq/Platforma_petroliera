#ifndef ADMIN_H
#define ADMIN_H

#include "Account.h"
#include <iostream>

class Admin : public Account {
public:
    Admin(const std::string& user, const std::string& pass);
    bool login(const std::string& user, const std::string& pass) override;
    void displayRole() const override;
    void manageSystem(); // Additional admin-specific functionality
};

#endif // ADMIN_H
