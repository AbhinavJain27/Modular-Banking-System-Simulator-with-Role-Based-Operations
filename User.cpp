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

bool User::deleted(int i){
    if(i){
        isdeleted=true;
    }
    return isdeleted;
}