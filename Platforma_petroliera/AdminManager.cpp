#include "AdminManager.h"
#include <iostream>

AdminManager::AdminManager() {
    // Admin implicit
    accounts.push_back(make_unique<Admin>("admin", "1234"));
}

Account* AdminManager::findAccountByUsername(const string& username) {
    for (const auto& account : accounts) {
        if (account->login(username, "")) { // Compară doar username-ul
            return account.get();
        }
    }
    return nullptr;
}

bool AdminManager::login(const string& username, const string& password, Account*& loggedInAccount) {
    for (const auto& account : accounts) {
        if (account->login(username, password)) {
            loggedInAccount = account.get();
            return true;
        }
    }
    return false;
}

void AdminManager::addUser(const string& username, const string& password) {
    if (findAccountByUsername(username)) {
        cout << "User already exists!" << endl;
        return;
    }
    accounts.push_back(make_unique<User>(username, password));
    cout << "User " << username << " added successfully!" << endl;
}

void AdminManager::removeUser(const string& username) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->login(username, "")) {
            accounts.erase(it);
            cout << "User " << username << " removed successfully!" << endl;
            return;
        }
    }
    cout << "User not found!" << endl;
}

void AdminManager::promoteToAdmin(const string& username) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->login(username, "")) {
            auto user = dynamic_cast<User*>((*it).get());
            if (user) {
                accounts.erase(it);
                accounts.push_back(make_unique<Admin>(username, user->getPassword()));
                cout << "User " << username << " promoted to Admin successfully!" << endl;
            }
            else {
                cout << username << " is already an Admin!" << endl;
            }
            return;
        }
    }
    cout << "User not found!" << endl;
}

void AdminManager::listAccounts() const {
    for (const auto& account : accounts) {
        account->displayRole();
    }
}
