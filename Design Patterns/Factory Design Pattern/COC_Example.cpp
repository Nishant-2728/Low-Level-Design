#include <bits/stdc++.h>
using namespace std;

class Troop{
protected:
    int damage,firepower;
public:
    Troop(int d,int f):damage(d),firepower(f){
        
    }
    virtual void attack()=0;
};

class HogRider:public Troop{
public:
    HogRider(int d,int h):Troop(d,h){}
    
    void attack() override{
        cout<<"The Hog Rider has a damage and firepower of "<<damage<<" and "<<firepower<<"\n";
    }
};

class Archer:public Troop{
public:
    Archer(int d,int h):Troop(d,h){}
    
    void attack() override{
        cout<<"The Archer has a damage and firepower of "<<damage<<" and "<<firepower<<"\n";
    }
};

class Barbarian:public Troop{
public:
    Barbarian(int d,int h):Troop(d,h){}
    
    void attack() override{
        cout<<"The Barbarian has a damage and firepower of "<<damage<<" and "<<firepower<<"\n";
    }
};

class Wizard:public Troop{
public:
    Wizard(int d,int h):Troop(d,h){}
    
    void attack() override{
        cout<<"The Wizard has a damage and firepower of "<<damage<<" and "<<firepower<<"\n";
    }
};

class TroopFactory{
public:
    static Troop* createTroop(string type){
        if(type=="Barbarian"){
            return new Barbarian(10,20);
        }
        else if(type=="Archer"){
            return new Archer(30,25);
        }
        else if(type=="Hog Rider"){
            return new HogRider(35,55);
        }
        else if(type=="Wizard"){
            return new Wizard(50,60);
        }
    }
};

int main() {
	string choice;
	getline(cin,choice);
	
	Troop* troop1=TroopFactory::createTroop(choice);
	troop1->attack();
}
