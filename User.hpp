#ifndef USER_HPP
#define USER_HPP
#include<string>


class User{
protected:
    std::string role,username , password;
    bool hasAuthority;

public:
    User(std::string uname , std:: string pwd){
        username=uname;
        password=pwd;
    }
    virtual int showmenu()=0;

};

#endif