#include <bits/stdc++.h>
using namespace std;

class PaymentStrategy{
public:
    virtual void pay()=0;
};

class GooglePay: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Payment done using Google Pay..."<<"\n";
    }
};

class UPI: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Payment done using UPI..."<<"\n";
    }
};

class Stripe: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Payment done using Stripe..."<<"\n";
    }
};

class CreditCard: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Payment done using Credit Card..."<<"\n";
    }
};

class PaymentProcessor{
private:
    PaymentStrategy* paymethod;
public:
    PaymentProcessor(PaymentStrategy* p){
        this->paymethod=p;
    }
    void makePayment(){
        paymethod->pay();
    }
    void setPaymentStrategy(PaymentStrategy* p1){
        this->paymethod=p1;
    }
};

int main(){
    PaymentStrategy* strategy1= new GooglePay();
    PaymentStrategy* strategy2= new UPI();
    
	PaymentProcessor* processor=new PaymentProcessor(strategy1);
	processor->makePayment();
	
	processor->setPaymentStrategy(strategy2);
	processor->makePayment();
}
