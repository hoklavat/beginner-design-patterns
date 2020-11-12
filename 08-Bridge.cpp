//08-Bridge

#include <iostream>
using namespace std;

class Implementor{
public:
	virtual ~Implementor(){}	
	virtual void action() = 0;
};

class ConcreteImplementorA: public Implementor{
public:
	~ConcreteImplementorA(){};
	
	void action(){
		cout << "Concrete Implementor A" << endl;
	}
};

class ConcreteImplementorB: public Implementor{
public:
	~ConcreteImplementorB(){}
	
	void action(){
		cout << "Concrete Implementor B" << endl;
	}
};

class Abstraction{
public:
	virtual ~Abstraction(){}	
	virtual void operation() = 0;
};

class RefinedAbstraction: public Abstraction{
private:
	Implementor *implementor;
	
public:	
	RefinedAbstraction(Implementor *impl): implementor(impl){}
	~RefinedAbstraction(){}	
	
	void operation(){
		implementor->action();
	}
};

int main(){
	Implementor *ia = new ConcreteImplementorA;
	Implementor *ib = new ConcreteImplementorB;
	
	Abstraction *abstract1 = new RefinedAbstraction(ia);
	abstract1->operation();
	
	Abstraction *abstract2 = new RefinedAbstraction(ib);
	abstract2->operation();
	
	delete abstract1;
	delete abstract2;
	
	delete ia;
	delete ib;
	
	return 0;
}