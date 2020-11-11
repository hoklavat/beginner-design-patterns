//05-Prototype

#include <iostream>
#include <string>
using namespace std;

class Prototype{
public:
	virtual ~Prototype(){}
	virtual Prototype* clone() = 0;
	virtual string type() = 0;
};

class ConcretePrototypeA: public Prototype{
public:
	~ConcretePrototypeA(){}
	
	//implementation of clone method in concrete class.
	Prototype* clone(){
		return new ConcretePrototypeA();
	}
	
	string type(){
		return "type A";
	}
};

class ConcretePrototypeB: public Prototype{
public:
	~ConcretePrototypeB() {}
	
	Prototype* clone(){
		return new ConcretePrototypeB();
	}
	
	string type(){
		return "type B";
	}
};

class Client{
private:
	static Prototype* types[2];
	static int n_types;
	
public:
	static void init(){
		types[0] = new ConcretePrototypeA();
		types[1] = new ConcretePrototypeB();
	}
	
	static void remove(){
		delete types[0];
		delete types[1];
	}
	
	static Prototype* make(const int index){
		if (index >= n_types){
			return nullptr;
		}		
		return types[index]->clone();
	}
};
int Client::n_types = 2;
Prototype* Client::types[2];


int main(){
	Client::init();
	
	Prototype *prototype1 = Client::make(0);
	cout << "Prototype: " << prototype1->type() << endl;
	delete prototype1;
	
	Prototype *prototype2 = Client::make(1);
	cout << "Prototype: " << prototype2->type() << endl;
	delete prototype2;
	
	Client::remove();
	
	return 0;
}