#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "User.hpp"
#include<string>


class Admin : public User{
public:
    Admin(std::string uname , std::string pwd);
    int showmenu() override;
    string getUsername() override;
    bool deleted(int i) override;
};


#endif