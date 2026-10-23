#include <bits/stdc++.h>
using namespace std;

class PowerSupply{
public:
    void providePower(){
        cout<<"Power Supply: Providing power..."<<"\n";
    }
};

class CoolingSystem{
public:
    void startFans(){
        cout<<"Cooling System: Fans started..."<<"\n";
    }
};

class CPU{
public:
    void initialize(){
        cout<<"CPU: Initialization started..."<<"\n";
    }
};

class Memory{
public:
    void selfTest(){
        cout<<"Memory: Self-test passed..."<<"\n";
    }
};

class HardDrive{
public:
    void spinUp(){
        cout<<"Hard Drive: Spinning up..."<<"\n";
    }
};

class BIOS{
public:
    void boot(CPU* cpu,Memory* mem){
        cout<<"BIOS: Booting CPU and Memory checks..."<<"\n";
        cpu->initialize();
        mem->selfTest();
    }
};

class OperatingSystem{
public:
    void load(){
        cout<<"Operating system: Loading into memory..."<<"\n";
    }
};

class ComputerFacade{
private:
    PowerSupply* p;
    CoolingSystem* c;
    CPU* cpu;
    Memory* mem;
    HardDrive* hd;
    BIOS* bios;
    OperatingSystem* os;
public:
    void startComputer(){
        cout<<"----Starting Computer----"<<"\n";
        p->providePower();
        c->startFans();
        bios->boot(cpu,mem);
        hd->spinUp();
        os->load();
        cout<<"Computer Booted Successfully!"<<"\n";
    }
};

int main(){
	ComputerFacade* compfac;
	compfac->startComputer();
}
