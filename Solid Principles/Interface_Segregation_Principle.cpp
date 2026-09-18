#include <bits/stdc++.h>
using namespace std;

class TwoDimensionalShape{
public:
    virtual double area()=0;
};

class ThreeDimensionalShape{
public:
    virtual double area()=0;
    virtual double volume()=0;
};

class Square: public TwoDimensionalShape{
private:
    double side;
public:
    Square(double s):side(s){}
    double area() override{
        return side*side;
    }
};

class Rectangle: public TwoDimensionalShape{
private:
    double length,width;
public:
    Rectangle(double l,double w):length(l),width(w){}
    double area() override{
        return length*width;
    }
};

class Cube: public ThreeDimensionalShape{
private:
    double edge;
public:
    Cube(double s):edge(s){}
    double area() override{
        return 6*edge*edge;
    }
    double volume() override{
        return edge*edge*edge;
    }
};

int main(){
	TwoDimensionalShape* square= new Square(4);
	TwoDimensionalShape* rectangle= new Rectangle(3,5);
	ThreeDimensionalShape* cube= new Cube(6);
	
	cout<<"Square area is "<<square->area()<<"\n";
	cout<<"Rectangle area is "<<rectangle->area()<<"\n";
	cout<<"Cube area is "<<cube->area()<<"\n";
	cout<<"Cube volume is "<<cube->volume()<<"\n";
}
