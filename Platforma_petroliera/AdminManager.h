#ifndef ADMIN_MANAGER_H
#define ADMIN_MANAGER_H

#include "Admin.h"
#include "User.h"
#include <vector>
#include <memory>
#include <string>

class AdminManager {
private:
    vector<unique_ptr<Account>> accounts;

    Account* findAccountByUsername(const string& username);

public:
    AdminManager();

    bool login(const string& username, const string& password, Account*& loggedInAccount);

    void addUser(const string& username, const string& password);
    void removeUser(const string& username);
    void promoteToAdmin(const string& username);

    void listAccounts() const;
};

#endif // ADMIN_MANAGER_H
