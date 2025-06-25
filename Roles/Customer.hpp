#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include "User.hpp"
#include<string>


class Customer : public User{
public:
    Customer(std::string uname , std::string pwd);
    int showmenu() override;
    void performAction() override;    
};


#endif