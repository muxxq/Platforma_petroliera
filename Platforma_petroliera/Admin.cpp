#include "Admin.h"

Admin::Admin(const string& user, const string& pass)
    : Account(user, pass) {}

bool Admin::login(const string& user, const string& pass) {
    return (username == user && password == pass);
}

void Admin::displayRole() const {
    cout << "Logged in as Admin: " << username << endl;
}

void Admin::manageSystem() {
    cout << "Admin is managing the system..." << endl;
}
