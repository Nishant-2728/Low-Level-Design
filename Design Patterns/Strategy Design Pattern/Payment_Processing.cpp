#include <bits/stdc++.h>
using namespace std;

class PaymentStrategy{
public:
    virtual void pay()=0;
};

class CreditCardPayment: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Processing payment using Credit Card...."<<"\n";
    }
};

class GooglePayPayment: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Processing payment using Google Pay...."<<"\n";
    }
};

class PayPalPayment: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Processing payment using PayPal...."<<"\n";
    }
};

class PaymentFactory{
public:
    PaymentStrategy* create(string choice){
        if(choice=="Credit Card"){
            return new CreditCardPayment();
        }
        else if(choice=="Google Pay"){
            return new GooglePayPayment();
        }
        else if(choice=="PayPal"){
            return new PayPalPayment();
        }
    }
};

class PaymentProcessor{
private:
    PaymentStrategy* paymethod;
public:
    PaymentProcessor(PaymentStrategy* p):paymethod(p){
        
    }
    void makePayment(){
        paymethod->pay();
    }
    void setmethod(PaymentStrategy* p){
        this->paymethod=p;
    }
};

int main(){
    PaymentFactory* factory=new PaymentFactory();
    
	string choice;
	getline(cin,choice);
	
	PaymentStrategy* p=factory->create(choice);
	
	PaymentProcessor* processor=new PaymentProcessor(p);
	
	processor->makePayment();
}
