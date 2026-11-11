#include <bits/stdc++.h>
using namespace std;

class Talkable{
public:
    virtual void talk()=0;
};

class NormalTalk: public Talkable{
public:
    void talk() override{
        cout<<"The robot can talk normally..."<<"\n";
    }
};

class NoTalk: public Talkable{
public:
    void talk() override{
        cout<<"The robot cannot talk normally..."<<"\n";
    }
};

class Walkable{
public:
    virtual void walk()=0;
};

class NormalWalk: public Walkable{
public:
    void walk() override{
        cout<<"The robot can walk normally..."<<"\n";
    }
};

class NoWalk: public Walkable{
public:
    void walk() override{
        cout<<"The robot cannot walk normally..."<<"\n";
    }
};

class Flyable{
public:
    virtual void fly()=0;
};

class NormalFly: public Flyable{
public:
    void fly() override{
        cout<<"The robot can fly normally..."<<"\n";
    }
};

class NoFly: public Flyable{
public:
    void fly() override{
        cout<<"The robot cannot fly normally..."<<"\n";
    }
};

class Robot{
private:
    Flyable* flyCharacter;
    Talkable* talkCharacter;
    Walkable* walkCharacter;
public:
    void setRobotCharacters(Flyable* f,Talkable* t,Walkable* w){
        this->flyCharacter=f;
        this->talkCharacter=t;
        this->walkCharacter=w;
    }
    void exhibitBehaviour(){
        flyCharacter->fly();
        talkCharacter->talk();
        walkCharacter->walk();
    }
};

class RobotFactory{
public:
    static Talkable* createTalkBehaviour(string choice){
        if(choice=="Normal"){
            return new NormalTalk();
        }
        else{
            return new NoTalk();
        }
    }
    
    static Walkable* createWalkBehaviour(string choice){
        if(choice=="Normal"){
            return new NormalWalk();
        }
        else{
            return new NoWalk();
        }
    }
    
    static Flyable* createFlyBehaviour(string choice){
        if(choice=="Normal"){
            return new NormalFly();
        }
        else{
            return new NoFly();
        }
    }
};

int main(){
	string flychoice,talkchoice,walkchoice;
	cin>>flychoice>>talkchoice>>walkchoice;
	
	Talkable* talkbehaviour=RobotFactory:: createTalkBehaviour(talkchoice);
	Walkable* walkbehaviour=RobotFactory:: createWalkBehaviour(walkchoice);
	Flyable* flybehaviour=RobotFactory:: createFlyBehaviour(flychoice);
	
	Robot* robot1= new Robot();
	robot1->setRobotCharacters(flybehaviour,talkbehaviour,walkbehaviour);
	robot1->exhibitBehaviour();
}
