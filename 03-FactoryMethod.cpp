//03-FactoryMethod

#include <iostream>
#include <string>
using namespace std;

class Product{
public:
	virtual ~Product(){}	
	virtual string getName() = 0;
};

class ConcreteProductA: public Product{
public:
	~ConcreteProductA(){}
	
	string getName(){
		return "type A";
	}
};

class ConcreteProductB: public Product{
public:
	~ConcreteProductB(){}
	
	string getName(){
		return "type B";
	}
};

class Creator{
public:
	virtual ~Creator(){}
	
	virtual Product* createProductA() = 0;
	virtual Product* createProductB() = 0;	
	virtual void removeProduct(Product *product) = 0;
};

class ConcreteCreator: public Creator{
public:
	~ConcreteCreator(){}
	
	Product* createProductA(){
		return new ConcreteProductA();
	}
	
	Product* createProductB(){
		return new ConcreteProductB();
	}
	
	void removeProduct(Product *product){
		delete product;
	}
};

int main(){
	Creator *creator = new ConcreteCreator();
	
	Product *p1 = creator->createProductA();
	cout << "Product: " << p1->getName() << endl;
	creator->removeProduct(p1);
	
	Product *p2 = creator->createProductB();
	cout << "Product: " << p2->getName() << endl;
	creator->removeProduct(p2);
	
	delete creator;
	return 0;
}