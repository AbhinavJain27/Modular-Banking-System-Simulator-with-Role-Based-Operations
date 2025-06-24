#ifndef USER_HPP
#define USER_HPP
#include<string>


class User{
protected:
    std::string username , password;
    bool hasAuthority,isdeleted;

public:
    User(std::string uname , std:: string pwd){
        username=uname;
        password=pwd;
    }
    virtual int showmenu()=0;
    virtual string getUsername()=0;
    virtual bool deleted(int i)=0;

};

#endif