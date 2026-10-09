#include <bits/stdc++.h>
using namespace std;

class Command{
public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual ~Command(){}
};

class Light{
public:
    void on(){
        cout<<"Light is ON"<<"\n";
    }
    
    void off(){
        cout<<"Light is OFF"<<"\n";
    }
};

class Fan{
public:
    void on(){
        cout<<"Fan is ON"<<"\n";
    }
    
    void off(){
        cout<<"Fan is OFF"<<"\n";
    }
};

class LightCommand: public Command{
private:
    Light* light;
public:
    LightCommand(Light* l){
        this->light=l;
    }
    
    void execute() override{
        light->on();
    }
    
    void undo() override{
        light->off();
    }
};

class FanCommand: public Command{
private:
    Fan* fan;
public:
    FanCommand(Fan* f){
        this->fan=f;
    }
    
    void execute() override{
        fan->on();
    }
    
    void undo() override{
        fan->off();
    }
};

class RemoteController{
private:
    static const int numButtons=4;
    Command* buttons[numButtons];
    bool isButtonPressed[numButtons];
    
public:
    RemoteController(){
        for(int i=0;i<numButtons;i++){
            buttons[i]=nullptr;
            isButtonPressed[i]=false;
        }
    }
    
    void setCommand(int idx, Command* cmd){
        if(idx>=0 && idx<numButtons){
            if(buttons[idx]!=nullptr){
                delete buttons[idx];
            }
            buttons[idx]=cmd;
            isButtonPressed[idx]=false;
        }
    }
    
    void pressButton(int idx){
        if(idx>=0 && idx<numButtons && buttons[idx]!=nullptr){
            if(isButtonPressed[idx]==false){
                buttons[idx]->execute();
            }
            else{
                buttons[idx]->undo();
            }
            isButtonPressed[idx]=!isButtonPressed[idx];
        }
        else{
            cout<<"No command assigned at button "<<idx<<"\n";
        }
    }
    
    ~RemoteController(){
        for(int i=0;i<numButtons;i++){
            if(buttons[i]!=nullptr){
                delete buttons[i];
            }
        }
    }
};

int main(){
	Light* livingRoomLight= new Light();
	Fan* ceilingFan= new Fan();
	
	RemoteController* remote= new RemoteController();
	
	remote->setCommand(0,new LightCommand(livingRoomLight));
	remote->setCommand(1,new FanCommand(ceilingFan));
    
    cout<<"---Toggling Light Button 0---"<<"\n";
    remote->pressButton(0);
    remote->pressButton(0);
    
    cout<<"---Toggling Fan Button 1---"<<"\n";
    remote->pressButton(1);
    remote->pressButton(1);
    
    cout<<"---Pressing unassigned button 2---"<<"\n";
    remote->pressButton(2);
    
    delete remote;
    delete livingRoomLight;
    delete ceilingFan;
}
