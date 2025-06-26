#ifndef USER_HPP
#define USER_HPP
#include<string>

class Bank;
class Account;

class User{
protected:
    std::string username , password;
    bool hasAuthority,isdeleted;

public:
    User(std::string uname , std:: string pwd);
    virtual int showmenu()=0;
    virtual void performAction(Bank* bank)=0;
    virtual void returnMenu(Bank* bank)=0;

    std::string getUsername();

    bool deleted();
    void deleteUser();

    std::string getPassword();
    void changePassword(std::string uname , std:: string newpwd);
    

};

#endif