#include<iostream>
using namespace std;

class shape {
public:
	virtual void area() = 0;

};

class circle :public shape{

	int radious;

public:

	circle():radious(10){}

	void area() {
		cout << "Area of a circle is: " << 3.14 * radious * radious << '\n';
	}
};

class rectangle :public shape {
	int length, width;
public:
	rectangle() :length(4), width(3) {}

	void area() {
		cout << "Area of Rectangle: " << length * width << '\n';
	}
};

int main() {

	shape* c = new circle();
	shape* r=new rectangle();
	c->area();
	r->area();
	return 0;
}
