#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    std::string username;
    std::string password;

public:
    Account(const std::string& user, const std::string& pass);
    virtual bool login(const std::string& user, const std::string& pass) = 0;
    virtual void displayRole() const = 0;
    std::string getPassword() const { return password; }
    virtual ~Account() = default;
};

#endif // ACCOUNT_H
