#include "Account.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Account::Account(int acc , int pin, string uname){
    accNo=acc;
    this->pin=pin;
    username=uname;
    balance=0;
    isDeleted=false;
    Transaction_History.push_back("Account created.");
}

void Account::withdraw(double amt){
    if(balance>=amt){
        balance-=amt;
        cout<<to_string(amt) + " rupees withdrawn."<<endl;
        Transaction_History.push_back(to_string(amt) + " rupees withdrawn.");
    }

    else cout<<"Balance insufficient";
}

void Account::deposit(double amt){
    balance+=amt;
    cout<<to_string(amt) + " rupees deposited."<<endl;
    Transaction_History.push_back(to_string(amt) + " rupees deposited.");    
}

void Account::printStatement(){
    int n=Transaction_History.size();
    for(int i=n-1 ; i>max(0,n-6) ; i--){
        cout<<Transaction_History[i]<<endl;
    }
}

int Account::getAccountNumber(){
    return accNo;
}

string Account::getUsername(){ return username;}

bool Account::deleted(){
    return isDeleted;
}

double Account::checkBalance(){
    return balance;
}

void Account::deleteAccount(){
    isDeleted=true;
}