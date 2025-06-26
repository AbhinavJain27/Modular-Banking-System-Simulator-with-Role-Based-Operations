#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <vector>
#include "User.hpp"
#include<string>

class Account;


class Customer : public User{
private:
    std::vector<Account*> accounts;
public:
    Customer(std::string uname , std::string pwd);
    int showmenu() override;
    void performAction(Bank* bank) override;  
    void returnMenu(Bank* bank) override;
    
    void add_Account(Bank* bank , int pin); 
    ~Customer(); 
};


#endif