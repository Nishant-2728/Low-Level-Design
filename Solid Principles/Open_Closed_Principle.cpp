#include <bits/stdc++.h>
using namespace std;

class Product{
public:
    string name;
    int price;
    
    Product(string name,int price): name(name),price(price){
        
    }
};

class ShoppingCart{
private:
    vector<Product*>products;
    
public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    
    const vector<Product*>&getProducts(){
        return products;
    }
    
    double calcTotalPrice(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }
};

class InvoicePrinter{
private:
    ShoppingCart* cart;
    
public:
    InvoicePrinter(ShoppingCart* cart):cart(cart){
        
    }
    
    void printInvoice(){
        for(auto p: cart->getProducts()){
            cout<<p->name<<" -$"<<p->price<<"\n";
        }
        cout<<"Total: $"<<cart->calcTotalPrice()<<"\n";
    }
};

class DBStorage{
private:
    ShoppingCart* cart;
    
public:
   virtual void save(ShoppingCart* cart)=0;
};

class SQLStorage: public DBStorage{
public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving Shopping Cart to SQL DB..."<<"\n";
    }
};

class MongoStorage: public DBStorage{
public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving Shopping Cart to Mongo DB..."<<"\n";
    }
};

class FileStorage: public DBStorage{
public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving Shopping Cart to a file..."<<"\n";
    }
};


int main(){
	ShoppingCart* cart= new ShoppingCart();
	
	cart->addProduct(new Product("Laptop",1500));
	cart->addProduct(new Product("Mouse",100));
	
	InvoicePrinter* printer= new InvoicePrinter(cart);
	printer->printInvoice();
	
	DBStorage* sql= new SQLStorage();
	DBStorage* mongo= new MongoStorage();
	DBStorage* file= new FileStorage();
	
	sql->save(cart);
	mongo->save(cart);
	file->save(cart);
}
