#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include<vector>
#include<string>

class Account{
protected:
    std::string username;
    int accNo, pin;
    double balance;
    bool isDeleted;
    std::vector<std::string> Transaction_History;
public:
    explicit Account(int acc , int pin ,std::string uname);

    int getAccountNumber();
    std::string getUsername();

    void withdraw(double amt);
    void deposit(double amt);
    double checkBalance(); 
    void printStatement();
    
    bool deleted(); 
    void deleteAccount(); 
     

};

#endif