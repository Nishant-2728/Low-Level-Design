#include <bits/stdc++.h>
using namespace std;

class depositOnlyAccount{
public:
    virtual void deposit(int amount)=0;
};

class withdrawableAccount: public depositOnlyAccount{
public:
    virtual void withdraw(int amount)=0;
};

class savingsAccount: public withdrawableAccount{
private:
    int balance;
public:
    savingsAccount(){
        balance=0;
    }
    void deposit(int amount){
        balance+=amount;
        cout<<"Deposited Rs "<< amount<<" in the Savings Account.New Balance is "<<balance<<"\n";
    }
    void withdraw(int amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawed Rs "<< amount<<" from the Savings Account.New Balance is "<<balance<<"\n";
        }
        else{
            cout<<"Insufficient balance in the account"<<"\n";
        }
    }
};

class currentAccount: public withdrawableAccount{
private:
    int balance;
public:
    currentAccount(){
        balance=0;
    }
    void deposit(int amount){
        balance+=amount;
        cout<<"Deposited Rs "<< amount<<" in the Current Account.New Balance is "<<balance<<"\n";
    }
    void withdraw(int amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawed Rs "<< amount<<" from the Current Account.New Balance is "<<balance<<"\n";
        }
        else{
            cout<<"Insufficient balance in the account"<<"\n";
        }
    }
};

class fixedDepositAccount: public depositOnlyAccount{
private:
    int balance;
public:
    fixedDepositAccount(){
        balance=0;
    }
    void deposit(int amount){
        balance+=amount;
        cout<<"Deposited Rs "<< amount<<" in the Fixed Deposit Account.New Balance is "<<balance<<"\n";
    }
};

class BankClient{
private:
    vector<withdrawableAccount*>withdrawableAccounts;
    vector<depositOnlyAccount*>depositOnlyAccounts;
public:
    BankClient(vector<withdrawableAccount*>w,vector<depositOnlyAccount*>d){
        this->withdrawableAccounts=w;
        this->depositOnlyAccounts=d;
    }
    void processTransactions(){
        for(withdrawableAccount* acc: withdrawableAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(depositOnlyAccount* acc: depositOnlyAccounts){
            acc->deposit(5000);
        }
    }
};

int main(){
	vector<withdrawableAccount*>withdrawableAccounts;
	withdrawableAccounts.push_back(new savingsAccount());
	withdrawableAccounts.push_back(new currentAccount());
	
	vector<depositOnlyAccount*>depositOnlyAccounts;
	depositOnlyAccounts.push_back(new fixedDepositAccount());
	
	BankClient* client= new BankClient(withdrawableAccounts,depositOnlyAccounts);
	client->processTransactions();
}
