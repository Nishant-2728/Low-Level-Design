#include <bits/stdc++.h>
using namespace std;

class User{ 
public:
    //Precondition: Password must be atleast 8 characters long
    virtual void setPassword(string passwd){
        if(passwd.length()<8){
            throw invalid_argument("Password must be atleast 8 characters long");
        }
        cout<<"Password set successfully"<<"\n";
    }
};

class AdminUser: public User{ 
public:
    //Precondition: Password must be atleast 6 characters long
    void setPassword(string passwd) override{
        if(passwd.length()<6){
            throw invalid_argument("Password must be atleast 6 characters long");
        }
        cout<<"Password set successfully"<<"\n";
    }
};

int main(){
	User* user= new AdminUser();
	user->setPassword("Admin1");
}
