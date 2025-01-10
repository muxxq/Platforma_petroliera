#include "AdminManager.h"
#include <iostream>

AdminManager::AdminManager() {
    // Admin implicit
    accounts.push_back(std::make_unique<Admin>("admin", "1234"));
}

Account* AdminManager::findAccountByUsername(const std::string& username) {
    for (const auto& account : accounts) {
        if (account->login(username, "")) { // Compară doar username-ul
            return account.get();
        }
    }
    return nullptr;
}

bool AdminManager::login(const std::string& username, const std::string& password, Account*& loggedInAccount) {
    for (const auto& account : accounts) {
        if (account->login(username, password)) {
            loggedInAccount = account.get();
            return true;
        }
    }
    return false;
}

void AdminManager::addUser(const std::string& username, const std::string& password) {
    if (findAccountByUsername(username)) {
        std::cout << "User already exists!" << std::endl;
        return;
    }
    accounts.push_back(std::make_unique<User>(username, password));
    std::cout << "User " << username << " added successfully!" << std::endl;
}

void AdminManager::removeUser(const std::string& username) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->login(username, "")) {
            accounts.erase(it);
            std::cout << "User " << username << " removed successfully!" << std::endl;
            return;
        }
    }
    std::cout << "User not found!" << std::endl;
}

void AdminManager::promoteToAdmin(const std::string& username) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->login(username, "")) {
            auto user = dynamic_cast<User*>((*it).get());
            if (user) {
                accounts.erase(it);
                accounts.push_back(std::make_unique<Admin>(username, user->getPassword()));
                std::cout << "User " << username << " promoted to Admin successfully!" << std::endl;
            }
            else {
                std::cout << username << " is already an Admin!" << std::endl;
            }
            return;
        }
    }
    std::cout << "User not found!" << std::endl;
}

void AdminManager::listAccounts() const {
    for (const auto& account : accounts) {
        account->displayRole();
    }
}
