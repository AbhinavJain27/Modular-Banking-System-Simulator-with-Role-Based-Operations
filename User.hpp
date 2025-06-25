#ifndef USER_HPP
#define USER_HPP
#include<string>


class User{
protected:
    std::string username , password;
    bool hasAuthority,isdeleted;

public:
    User(std::string uname , std:: string pwd);
    virtual int showmenu()=0;
    string getUsername();
    bool deleted(int i);
    string getPassword();

};

#endif