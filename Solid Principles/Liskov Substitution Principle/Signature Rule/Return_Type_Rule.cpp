#include <bits/stdc++.h>
using namespace std;

class Animal{
    
};

class Dog: public Animal{
    
};

class Parent{
public:
    virtual Animal* getAnimal(){
        cout<<"Parent: Returning Animal instance"<<"\n";
        return new Animal();
    }
};

class Child: public Parent{
public:
    Dog* getAnimal() override{
        cout<<"Child: Returning Dog instance"<<"\n";
        return new Dog();
    }
};

class Client{
private:
    Parent* p;
public:
    Client(Parent* p){
        this->p=p;
    }
    void takeAnimal(){
        p->getAnimal();
    }
};

int main(){
	Parent* parent= new Parent();
	Parent* child= new Child();
	
	Client* client =new Client(child);
	client->takeAnimal();
}
