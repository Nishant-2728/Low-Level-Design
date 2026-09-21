#include <bits/stdc++.h>
using namespace std;

class WalkableRobot{
public:
    virtual void walk()=0;
    virtual ~WalkableRobot(){}
};

class NormalWalk: public WalkableRobot{
public:
    void walk() override{
        cout<<"Walking normally..."<<"\n";
    }
};

class NoWalk: public WalkableRobot{
public:
    void walk() override{
        cout<<"Cannot walk..."<<"\n";
    }
};

class TalkableRobot{
public:
    virtual void talk()=0;
    virtual ~TalkableRobot(){}
};

class NormalTalk: public TalkableRobot{
public:
    void talk() override{
        cout<<"Talking normally..."<<"\n";
    }
};

class NoTalk: public TalkableRobot{
public:
    void talk() override{
        cout<<"Cannot talk..."<<"\n";
    }
};

class FlyableRobot{
public:
    virtual void fly()=0;
    virtual ~FlyableRobot(){}
};

class NormalFly: public FlyableRobot{
public:
    void fly() override{
        cout<<"Flying normally..."<<"\n";
    }
};

class NoFly: public FlyableRobot{
public:
    void fly() override{
        cout<<"Cannot fly..."<<"\n";
    }
};

class Robot{
protected:
    WalkableRobot* walkbehaviour;
    TalkableRobot* talkbehaviour;
    FlyableRobot* flybehaviour;
public:
    Robot(WalkableRobot*w, TalkableRobot* t,FlyableRobot* f){
        this->walkbehaviour=w;
        this->talkbehaviour=t;
        this->flybehaviour=f;
    }
    void walk(){
        walkbehaviour->walk();
    }
    void talk(){
        talkbehaviour->talk();
    }
    void fly(){
        flybehaviour->fly();
    }
    virtual void projection()=0;
};

class CompanionRobot: public Robot{
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f): Robot(w,t,f){}
    void projection() override{
        cout<<"Displaying friendly companion features..."<<"\n";
    }
};

class WorkerRobot: public Robot{
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f): Robot(w,t,f){}
    void projection() override{
        cout<<"Displaying worker efficiency stats..."<<"\n";
    }
};

int main(){
	Robot* robot1= new CompanionRobot(new NormalWalk(), new NormalTalk(),new NoFly());
	robot1->walk();
	robot1->talk();
	robot1->fly();
	robot1->projection();
	cout<<"------------------------------------------"<<"\n";
	Robot* robot2= new WorkerRobot(new NoWalk(), new NoTalk(),new NormalFly());
	robot2->walk();
	robot2->talk();
	robot2->fly();
	robot2->projection();
}
