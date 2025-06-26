#ifndef BANK_HPP
#define BANK_HPP
#include <vector>
#include <string>

class Account;
class Admin;
class Customer;
class User;

class Bank{
protected:
    std:: vector<Account*> account_list;  
    std:: vector<Admin*> admin_list; 
    std:: vector<Customer*> customer_list;
    int last_used_account_number=100000;

public:
    //basic functions
    int showMenu();
    int roleType();
    void perform(Bank* bank);

    //addition and deletion of accounts
    int getAccountNumber(int i);
    void addAccount(int pin , std::string uname);
    Account* findAccount(int accNo);

    //addition and deletion of users
    void addUser(std::string role , std:: string uname , std:: string pwd);
    User* findUser(std:: string role,std::string uname);

    //authenticate
    User* authenticate(std:: string role , std:: string uname , std:: string pwd);

    ~Bank(); /*deletion becomes necessary to avoid ram leakage; stack variables can not
            be used because they get deleted at the end of the function therefore
            only choice is to use the object creation method which strictly requires deletion */
    
};

#endif