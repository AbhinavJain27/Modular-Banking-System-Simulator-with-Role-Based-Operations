#include "Customer.hpp"
#include "Bank.hpp"
#include "Account.hpp"
#include<iostream>
using namespace std;


Customer::Customer(std::string uname , std::string pwd) : User(uname , pwd){
    hasAuthority=false;
    isdeleted=false;
};

int Customer::showmenu(){
    int choice;
    cout << "==== Customer Menu ===="<<endl;
    cout << "1. Open a new account"<<endl;
    cout << "2. View bank balance"<<endl;
    cout << "3. Deposit/Withdraw"<<endl;
    cout << "4. Transfer Money"<<endl;
    cout << "5. View Transaction history"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    cout<<endl;
    return choice;
}

void Customer::performAction(Bank* bank){
    int choice = showmenu();
    if(choice==1){
        int pin;
        cout<<"Enter the pin for your account"<<endl;
        cin>>pin;
        cout<<endl;
        add_Account(bank , pin);
        returnMenu(bank);
    }
}

void Customer::returnMenu(Bank* bank){
    int choice;
    cout<<"1. Do you wish to return to menu?"<<endl;
    cout<<"2. Logout"<<endl;
    cout<<"Enter your choice."<<endl;
    cin>>choice;
    cout<<endl;
    if(choice==1) performAction(bank);
}

void Customer::add_Account(Bank* bank , int pin){
    bank->addAccount(pin);
    Account* account = new Account(bank->getAccountNumber(0) , pin);
    accounts.push_back(account);
}

Customer::~Customer(){
    for(auto account:accounts){
        delete account;
    }
}





