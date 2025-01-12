#ifndef ADMIN_H
#define ADMIN_H

#include "Account.h"
#include <iostream>

class Admin : public Account {
public:
    Admin(const string& user, const string& pass);
    bool login(const string& user, const string& pass) override;
    void displayRole() const override;
    void manageSystem(); // Additional admin-specific functionality
};

#endif // ADMIN_H
