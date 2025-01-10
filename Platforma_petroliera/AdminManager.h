#ifndef ADMIN_MANAGER_H
#define ADMIN_MANAGER_H

#include "Admin.h"
#include "User.h"
#include <vector>
#include <memory>
#include <string>

class AdminManager {
private:
    std::vector<std::unique_ptr<Account>> accounts;

    Account* findAccountByUsername(const std::string& username);

public:
    AdminManager();

    bool login(const std::string& username, const std::string& password, Account*& loggedInAccount);

    void addUser(const std::string& username, const std::string& password);
    void removeUser(const std::string& username);
    void promoteToAdmin(const std::string& username);

    void listAccounts() const;
};

#endif // ADMIN_MANAGER_H
