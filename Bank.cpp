#include "Bank.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Roles/Admin.hpp"
#include "Roles/Customer.hpp"
#include "Account.hpp"
using namespace std;

void Bank::addAccount(int accNo , int pin){
    Account* acc = new Account(accNo, pin);
    account_list.push_back(acc);
}

int Bank::findAccount(int accNo){
    for(int i=0 ; i<account_list.size() ; i++){
        if(account_list[i]->getAccountNumber()==accNo){
            if(account_list[i]->deleted(0)){
                cout<<"Your Account has been deleted.";
                return -1;
            }
            return i;
        }
    }

    cout<<"Account not found.";
    return -1;
}

void Bank::deleteAccount(int accNo){
    int accId=findAccount(accNo);
    if(accId!=-1){
        account_list[accId]->deleted(1);
    }

    cout<<"Your Account has been deleted.";
}


//now user management functions will come

int Bank::findUser(string role, string uname){
    if(role=="Admin"){
        for(int i=0 ; i<admin_list.size();i++){
            if(admin_list[i]->getUsername()==uname){
                if(admin_list[i]->deleted(0)){
                    return -1;
                }
                return i;
            }
        }

        return -1;
    }
}

void Bank::addUser(string role ,string uname , string pwd){
    if(findUser(role , uname)!=-1){
        cout<<"Please choose another username.";
        return;
    }
    if(role=="Admin"){
        Admin* adm=new Admin(uname , pwd);
        admin_list.push_back(adm);
        cout<<"User created succesfully.";
        return;
    }
    if(role=="Customer"){
        Customer* cus = new Customer(uname , pwd);
        customer_list.push_back(cus);
        cout<<"User created succesfully.";
        return;
    }
    
}

void Bank::deleteUser(string role , string uname){
    int uindex = findUser(role,uname);
    if(uindex==-1){
        cout<<"User not found";
    }
    if(role=="Admin"){
        admin_list[uindex]->deleted(1);
    }
    else if(role=="Customer"){
        customer_list[uindex]->deleted(1);
    }
    cout<<"User deleted successfully.";
        return;
}

Bank::~Bank(){
    for(auto account:account_list){
        delete account;
    }

    for(auto admin:admin_list){
        delete admin;
    }
    
    for(auto customer:customer_list){
        delete customer;
    }
}