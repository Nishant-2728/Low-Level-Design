#include <bits/stdc++.h>
using namespace std;

class Database{
public:
    virtual void save(string data)=0;
};

class MySQLDatabase: public Database{ // Low-level module
public:
    void save(string data) override{
        cout<<"Executing SQL Query: INSERT INTO users VALUES('"<<data<<"');"<<"\n";
    }
};

class MongoDBDatabase: public Database{ //Low-level module
public:
    void save(string data) override{
        cout<<"Executing MongoDB function: db.users.insert({name: '"<<data<<"'})"<<"\n";
    }
};

class UserService{ //High-level module
private:
    Database* db; //Dependecy injection
public:
    UserService(Database* database): db(database){}
    void storeUser(string user){
        db->save(user);
    }
};

int main(){
	MySQLDatabase* mysql= new MySQLDatabase();
	MongoDBDatabase* mongodb= new MongoDBDatabase();
	
	UserService* service1= new UserService(mysql);
	service1->storeUser("Aditya");
}
