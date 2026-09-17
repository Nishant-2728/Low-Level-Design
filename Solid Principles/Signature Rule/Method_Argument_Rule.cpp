#include <bits/stdc++.h>
using namespace std;

class Parent{
public:
    virtual void print(string msg){
        cout<<"Parent: "<<msg<<"\n";
    }
};

class Child: public Parent{
public:
    void print(string msg) override{
        cout<<"Child: "<<msg<<"\n";
    }
};

class Client{
private:
    Parent* p;
public:
    Client(Parent* p){
        this->p=p;
    }
    void printMsg(){
        p->print("hello");
    }
};

int main(){
	Parent* parent= new Parent();
	Parent* child= new Child();
	
	Client* client =new Client(child);
	client->printMsg();
}
