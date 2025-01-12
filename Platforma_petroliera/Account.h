#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    string username;
    string password;

public:
    Account(const string& user, const string& pass);
    virtual bool login(const string& user, const string& pass) = 0;
    virtual void displayRole() const = 0;
    string getPassword() const { return password; }
    virtual ~Account() = default;
};

#endif // ACCOUNT_H
