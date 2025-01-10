#include "User.h"

User::User(const std::string& user, const std::string& pass)
    : Account(user, pass) {}

bool User::login(const std::string& user, const std::string& pass) {
    return (username == user && password == pass);
}

void User::displayRole() const {
    std::cout << "Logged in as User: " << username << std::endl;
}
