#include "User.h"

User::User(const string& user, const string& pass)
    : Account(user, pass) {}

bool User::login(const string& user, const string& pass) {
    return (username == user && password == pass);
}

void User::displayRole() const {
    cout << "Logged in as User: " << username << endl;
}
