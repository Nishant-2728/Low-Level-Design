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

class BasicWheatBurger: public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Burger with bun,patty and ketchup!"<<"\n";
    }
};

class StandardWheatBurger: public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard WheatBurger with bun,patty and ketchup!"<<"\n";
    }
};

class PremiumWheatBurger: public Burger{
public:
    void prepare() override{
        cout<<"Preparing Premium Wheat Burger with gourmet bun,patty,cheese,mayonaisse and ketchup!"<<"\n";
    }
};

class BurgerFactory{
public:
    virtual Burger* createBurger(string& type){}
};

class SinghBurger: public BurgerFactory{
public:
    Burger* createBurger(string& type) override{
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

class KingBurger: public BurgerFactory{
public:
    Burger* createBurger(string& type) override{
        if(type=="basic"){
            return new BasicWheatBurger();
        }
        else if(type=="standard"){
            return new StandardWheatBurger();
        }
        else if(type=="premium"){
            return new PremiumWheatBurger();
        }
        else{
            cout<<"Invalid burger type!"<<"\n";
            return nullptr;
        }
    }
};

int main(){
	string type="basic";
	
	BurgerFactory* Factory1= new KingBurger();
	
	Burger* burger= Factory1->createBurger(type);
	burger->prepare();
}
