#include <bits/stdc++.h>
using namespace std;

class Car{ 
protected:
    int speed;
public:
    Car(){
        speed=0;
    }
    void accelerate(){
        cout<<"Accelerating"<<"\n";
        speed+=20;
    }
    //Postcondition: Speed must reduce after brake
    virtual void brake(){
        speed-=20;
        cout<<"Applying brakes..."<<"\n";
        cout<<"Current speed is "<<speed<<"\n";
    }
};

class HybridCar: public Car{ 
private:
    int charge;
public:
    HybridCar(): Car(){
        charge=0;
    }
    void brake() override{
        speed-=20;
        charge+=10;
        cout<<"Applying brakes..."<<"\n";
        cout<<"Current speed is "<<speed<<"\n";
        cout<<"Current battery percentage is "<<charge<<"\n";
    }
};

int main(){
	Car* car= new HybridCar();
	car->accelerate();
	car->accelerate();
	car->accelerate();
	car->brake();
}
