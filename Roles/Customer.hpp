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
    
    void add_Account(Bank* bank , int pin , std::string uname); 
    void viewBB();
    void balance_change(Account* account , int amt , int withOrDep);
    void transferFunds(int acc2, int amt , int withOrDep , Bank* bank);
    Account* trackAccount(int acc);
    ~Customer(); 
};


#endif