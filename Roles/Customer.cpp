#include "Customer.hpp"
#include<iostream>
using namespace std;


Customer::Customer(std::string uname , std::string pwd) : User(uname , pwd){
    hasAuthority=false;
    isdeleted=false;
};

int Customer::showmenu(){
    int choice;
    cout << "==== Customer Menu ===="<<endl;
    cout << "1. View bank balance"<<endl;
    cout << "2. Deposit/Withdraw"<<endl;
    cout << "3. Transfer Money"<<endl;
    cout << "4. View Transaction history"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

string Customer::getUsername(){
    return username;
}

bool Customer::deleted(int i){
    if(i){
        isdeleted=true;
    }
    return isdeleted;
}





