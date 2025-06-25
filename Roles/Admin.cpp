#include "Admin.hpp"
#include<iostream>
using namespace std;


Admin::Admin(std::string uname , std::string pwd) : User(uname , pwd){
    hasAuthority=true;
    isdeleted=false;
};

int Admin::showmenu(){
    int choice;
    cout << "==== Admin Menu ===="<<endl;
    cout << "1. View All Users"<<endl;
    cout << "2. Reset Account"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

void Admin:: performAction(){
    
}





