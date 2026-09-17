#include <bits/stdc++.h>
using namespace std;

class BankAccount{ // Invariant: Balance cannot be negative
protected:
    double balance;
public:
    BankAccount(double b){
        if(b<0){
            throw invalid_argument("Balance cannot be negative");
        }
        this->balance=b;
    }
    virtual void withdraw(double amount){
        if(balance<amount){
            throw runtime_error("Insufficient balance");
        }
        balance-=amount;
        cout<<"Amount withdrawn.Remaining balance is "<<balance<<"\n";
    }
};

class CheatAccount: public BankAccount{ // Breaks the class invariant
public:
    CheatAccount(double b): BankAccount(b){}
    
    void withdraw(double amount) override{
        balance-=amount;
        cout<<"Amount withdrawn.Remaining balance is "<<balance<<"\n";
    }
};

int main(){
	BankAccount* bankAccount= new BankAccount(500);
	bankAccount->withdraw(400);
}
