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

class GarlicBread{
public:
    virtual void prepare()=0;
    virtual ~GarlicBread(){}
};

class BasicGarlicBread: public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Basic Garlic Bread with butter and garlic!"<<"\n";
    }
};

class CheeseGarlicBread: public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Cheese Garlic Bread with extra cheese, butter and garlic!"<<"\n";
    }
};

class BasicWheatGarlicBread: public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Garlic Bread with butter and garlic!"<<"\n";
    }
};

class CheeseWheatGarlicBread: public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Cheese Wheat Garlic Bread with extra cheese, butter and garlic!"<<"\n";
    }
};


class BurgerFactory{
public:
    virtual Burger* createBurger(string& type){}
    virtual GarlicBread* createGarlicBread(string& type){}
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
    
    GarlicBread* createGarlicBread(string& type) override{
        if(type=="basic"){
            return new BasicGarlicBread();
        }
        else if(type=="cheese"){
            return new CheeseGarlicBread();
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
    
    GarlicBread* createGarlicBread(string& type) override{
        if(type=="basic"){
            return new BasicWheatGarlicBread();
        }
        else if(type=="cheese"){
            return new CheeseWheatGarlicBread();
        }
        else{
            cout<<"Invalid burger type!"<<"\n";
            return nullptr;
        }
    }
};

int main(){
	string type1="basic";
	string type2="cheese";
	
	BurgerFactory* Factory1= new KingBurger();
	
	Burger* burger= Factory1->createBurger(type1);
	GarlicBread* gb= Factory1->createGarlicBread(type2);
	
	burger->prepare();
	gb->prepare();
}
