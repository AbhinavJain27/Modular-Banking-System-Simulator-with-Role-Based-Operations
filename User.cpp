#include "User.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

User::User(string uname , string pwd): username(uname) , password(pwd){
    isdeleted=false;
    hasAuthority=false;
}

string User::getUsername(){
    return username;
}

string User::getPassword(){
    return password;
}

bool User::deleted(){
    return isdeleted;
}

void User::changePassword(string uname , string newpwd){
    if(uname==username){
        password=newpwd;
    }
    else cout<<"User not found."<<endl;
}

void User::deleteUser(){
    isdeleted=true;
}