#include <bits/stdc++.h>
using namespace std;

class PaymentStrategy{
public:
    virtual void pay()=0;
};

class GooglePayPayment: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Processing payment using Google Pay..."<<"\n";
    }
};

class PayPalPayment: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Processing payment using PayPal..."<<"\n";
    }
};

class CreditCardPayment: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Processing payment using Credit Card..."<<"\n";
    }
};

class StripePayment: public PaymentStrategy{
public:
    void pay() override{
        cout<<"Processing payment using Stripe..."<<"\n";
    }
};

class PaymentProcessor{
private:
    PaymentStrategy* payMethod;
public:
    void setPaymentStrategy(PaymentStrategy* strategy){
        this->payMethod=strategy;
    }
    void processPayment(){
        payMethod->pay();
    }
};

class PaymentFactory{
public:
    static PaymentStrategy* create(string choice){
        PaymentStrategy* strategy;
        if(choice=="Google Pay"){
            strategy= new GooglePayPayment();
        }
        else if(choice=="PayPal"){
            strategy= new PayPalPayment();
        }
        else if(choice=="Credit Card"){
            strategy= new CreditCardPayment();
        }
        else{
            strategy= new StripePayment();
        }
        return strategy;
    }
};

int main(){
	string choice;
	getline(cin,choice);
	
	PaymentStrategy* method1=PaymentFactory::create(choice);
	
	PaymentProcessor* newProcessor= new PaymentProcessor();
	newProcessor->setPaymentStrategy(method1);
	newProcessor->processPayment();
	
	getline(cin,choice);
	
	PaymentStrategy* method2=PaymentFactory::create(choice);
	
	newProcessor->setPaymentStrategy(method2);
	newProcessor->processPayment();
	
}
