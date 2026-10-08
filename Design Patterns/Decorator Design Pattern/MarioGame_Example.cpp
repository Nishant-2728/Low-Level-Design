#include <bits/stdc++.h>
using namespace std;

class Character{
public:
    virtual string getAbilities() const=0;
    virtual ~Character(){}
};

class Mario: public Character{
public:
    string getAbilities() const override{
        return "Mario";
    }
};

class CharacterDecorator: public Character{
protected:
    Character* character;
public:
    CharacterDecorator(Character* c){
        this->character=c;
    }
};

class HeightUp: public CharacterDecorator{
public:
    HeightUp(Character* c): CharacterDecorator(c){}
    
    string getAbilities() const override{
        return character->getAbilities()+" with height up";
    }
};

class GunPowerUp: public CharacterDecorator{
public:
    GunPowerUp(Character* c): CharacterDecorator(c){}
    
    string getAbilities() const override{
        return character->getAbilities()+" with gun";
    }
};

class StarPowerUp: public CharacterDecorator{
public:
    StarPowerUp(Character* c): CharacterDecorator(c){}
    
    string getAbilities() const override{
        return character->getAbilities()+" with Star power for limited time";
    }
    
    ~StarPowerUp(){
        cout<<"Destroying StarPowerUp"<<"\n";
    }
};

int main() {
	Character* mario= new Mario();
	cout<<"Basic Character: "<<mario->getAbilities()<<"\n";
	
	mario= new HeightUp(mario);
	cout<<"After Height Up: "<<mario->getAbilities()<<"\n";
	
	mario= new GunPowerUp(mario);
	cout<<"After GunPower Up: "<<mario->getAbilities()<<"\n";
	
	mario= new StarPowerUp(mario);
	cout<<"After Star Power Up: "<<mario->getAbilities()<<"\n";
}
