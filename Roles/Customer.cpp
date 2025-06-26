#include "Customer.hpp"
#include "Bank.hpp"
#include "Account.hpp"
#include<iostream>
using namespace std;


Customer::Customer(std::string uname , std::string pwd) : User(uname , pwd){
    hasAuthority=false;
    isdeleted=false;
};

int Customer::showmenu(){
    int choice;
    cout << "==== Customer Menu ===="<<endl;
    cout << "1. Open a new account"<<endl;
    cout << "2. View bank balance"<<endl;
    cout << "3. Deposit/Withdraw"<<endl;
    cout << "4. Transfer Money"<<endl;
    cout << "5. View Transaction history"<<endl;
    cout << "6. Delete Account"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    cout<<endl;
    return choice;
}

void Customer::performAction(Bank* bank){
    int choice = showmenu();
    if(choice==1){
        int pin;
        cout<<"Enter the pin for your account"<<endl;
        cin>>pin;
        cout<<endl;
        add_Account(bank , pin , username);
        cout<<endl;
    }

    if(choice==2) {
        viewBB();
        cout<<endl;
    }
    int acc;
    int ok=1;
    Account* account;
    if(choice!=1 && choice!=2){
        cout<<"Enter the account number."<<endl;
        cin>>acc;
        account = trackAccount(acc);
        if(account==nullptr){
            cout<<"This account has been deleted."<<endl;
            ok=0;
        }
    }
    int amt , wOD=0;
    if(ok && (choice==3||choice==4)){
        cout<<"Enter the amount."<<endl;
        cin>>amt;
        cout<<"Do you want to deposit(y/n)"<<endl;
        char resp;
        cin>>resp;
        if(resp=='n')wOD=1;
    }

    if(ok && choice==3){
        balance_change(account , amt , wOD);
    }

    if(ok && choice==4){
        cout<<"Enter the second person's account number."<<endl;
        int acc2;
        cin>>acc2;
        balance_change(account , amt , wOD);
        transferFunds(acc2 , amt , 1-wOD , bank);
    }

    if(ok && choice==5) account->printStatement();

    if(ok && choice==6) account->deleteAccount();

    if(choice<1 && choice>6){
        cout<<"Please enter a valid choice."<<endl;
    }    
    
    cout<<endl;
    returnMenu(bank);
    
}

void Customer::returnMenu(Bank* bank){
    int choice;
    cout<<"1. Do you wish to return to menu?"<<endl;
    cout<<"2. Logout"<<endl;
    cout<<"Enter your choice."<<endl;
    cin>>choice;
    cout<<endl;
    if(choice==1) performAction(bank);
    else if(choice==2) bank->perform(bank);
    else{
        cout<<"Please enter valid number."<<endl;
        returnMenu(bank);
    }
}

void Customer::add_Account(Bank* bank , int pin , string uname){
    bank->addAccount(pin, uname);
    Account* account = new Account(bank->getAccountNumber(0) , pin,uname);
    accounts.push_back(account);
    cout<<endl<<"Account with account number: "<<account->getAccountNumber()<<
                " has been created."<<endl;
}

void Customer::viewBB(){
    for(int i=0 ; i<accounts.size() ; i++){
        cout<<i+1<<". Account with acc. no. "<< accounts[i]->getAccountNumber()<<
        " has balance of "<<accounts[i]->checkBalance()<<endl;
    }
}

void Customer::balance_change(Account* account , int amt, int withOrDep){
    if(withOrDep) account->withdraw(amt);
    else account->deposit(amt);
}

void Customer::transferFunds(int acc2 , int amt , int withOrDep, Bank* bank){
    Account* account = bank->findAccount(acc2);
    if(withOrDep) account->withdraw(amt);
    else account->deposit(amt);
}

Account* Customer::trackAccount(int acc){
    for(auto account:accounts){
        if(account->getAccountNumber()==acc){
            return account;
        }
    }
    cout<<"Account not found"<<endl;
    return nullptr;
}

Customer::~Customer(){
    for(auto account:accounts){
        delete account;
    }
}