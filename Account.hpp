#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include<vector>
#include<string>

class Account{
protected:
    int accNo, pin;
    double balance;
    bool isDeleted;
    std::vector<std::string> Transaction_History;
public:
    explicit Account(int acc , int pin);
    void withdraw(double amt);
    void deposit(double amt);
    void printStatement();
    int getAccountNumber();
    bool deleted(int i);    

};

#endif