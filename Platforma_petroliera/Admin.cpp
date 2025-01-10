#include "Admin.h"

Admin::Admin(const std::string& user, const std::string& pass)
    : Account(user, pass) {}

bool Admin::login(const std::string& user, const std::string& pass) {
    return (username == user && password == pass);
}

void Admin::displayRole() const {
    std::cout << "Logged in as Admin: " << username << std::endl;
}

void Admin::manageSystem() {
    std::cout << "Admin is managing the system..." << std::endl;
}
