#include <bits/stdc++.h>
using namespace std;

class Burger{
public:
    virtual void prepare()=0;
    virtual ~Burger(){}
};

class BasicBurger: public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Burger with bun,patty and ketchup!"<<"\n";
    }
};

class StandardBurger: public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard Burger with bun,patty and ketchup!"<<"\n";
    }
};

class PremiumBurger: public Burger{
public:
    void prepare() override{
        cout<<"Preparing Premium Burger with gourmet bun,patty,cheese,mayonaisse and ketchup!"<<"\n";
    }
};

class BurgerFactory{
public:
    Burger* createBurger(string& type){
        if(type=="basic"){
            return new BasicBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();
        }
        else if(type=="premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"Invalid burger type!"<<"\n";
            return nullptr;
        }
    }
};

int main(){
	string type="standard";
	
	BurgerFactory* Factory1= new BurgerFactory();
	
	Burger* burger= Factory1->createBurger(type);
	burger->prepare();
}
