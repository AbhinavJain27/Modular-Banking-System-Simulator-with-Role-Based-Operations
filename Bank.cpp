#include "Bank.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Roles/Admin.hpp"
#include "Roles/Customer.hpp"
#include "Account.hpp"
#include "User.hpp"
using namespace std;

int Bank::showMenu(){
    int choice;
    cout << "==== Menu ===="<<endl;
    cout << "1. Login"<<endl;
    cout << "2. SignUp"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int Bank::roleType(){
    int choice;
    cout<<"Enter the number that corresponds to your type of role:"<<endl;
    cout << "1. Customer"<<endl;
    cout << "2. Admin"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

User* Bank::perform(){
    int choice=showMenu();
    int choice2=roleType();
    vector<string> roles = {"Customer" , "Admin"};

    string uname , pwd;
    cout<<"Enter your username:"<<endl;
    cin>>uname;
    cout<<"Enter your password:"<<endl;
    cin>>pwd;
    if(choice==1){
        User* entry = authenticate(roles[choice2-1] , uname , pwd);
        if(entry==nullptr) return nullptr;
        return entry;
    }
    if(choice==2){
        addUser(roles[choice2-1] , uname , pwd);
    }
    
    return nullptr;
}

void Bank::startBank(){
    User* user=perform();
    user->performAction();
}

void Bank::addAccount(int accNo , int pin){
    Account* acc = new Account(accNo, pin);
    account_list.push_back(acc);
}

Account* Bank::findAccount(int accNo){
    for(auto account:account_list){
        if(account->getAccountNumber()==accNo){
            if(account->deleted()){
                cout<<"This Account has been deleted.";
                return nullptr;
            }
            return account;
        }
    }

    cout<<"Account not found.";
    return nullptr;
}

User* Bank::findUser(string role, string uname){
    if(role=="Admin"){
        for(auto admin:admin_list){
            if(admin->getUsername()==uname){
                if(admin->deleted()) return nullptr;
                return admin;
            }
        }
    }

    if(role=="Customer"){
        for(auto customer:customer_list){
            if(customer->getUsername()==uname){
                if(customer->deleted()) return nullptr;
                return customer;
            }
        }
    }

    return nullptr;
}

void Bank::addUser(string role ,string uname , string pwd){
    if(findUser(role , uname)!=nullptr){
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

User* Bank::authenticate(string role , string uname , string pwd){
    User* entry = findUser(role, uname);
    if(entry==nullptr) return nullptr;
    if(entry->getPassword()!=pwd){
        cout<<"Incorrect username or password."<<endl;
        return nullptr;
    }
    return entry;
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