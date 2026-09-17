#include <bits/stdc++.h>
using namespace std;

class BankAccount{ 
protected:
    double balance;
public:
    BankAccount(double b){
        if(b<0){
            throw invalid_argument("Balance cannot be negative");
        }
        this->balance=b;
    }
    //History Constraint: Withdrawal of money should be allowed
    virtual void withdraw(double amount){
        if(balance<amount){
            throw runtime_error("Insufficient balance");
        }
        balance-=amount;
        cout<<"Amount withdrawn.Remaining balance is "<<balance<<"\n";
    }
};

class FixedDepositAccount: public BankAccount{ 
public:
    FixedDepositAccount(double b): BankAccount(b){}
    
    void withdraw(double amount) override{
        throw runtime_error("Withdraw not allowed in FD Account"); // Violated history constraint
    }
};

int main(){
	BankAccount* bankAccount= new BankAccount(500);
	bankAccount->withdraw(400);
}
