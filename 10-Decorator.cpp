//10-Decorator

#include <iostream>
using namespace std;

class Component{
public:
	virtual ~Component(){}	
	virtual void operation() = 0;
};

class ConcreteComponent: public Component{
public:
	~ConcreteComponent(){}
	
	void operation(){
		cout << "Concrete Component operation" << endl;
	}
};

class Decorator: public Component{
private:
	Component *component;
	
public:
	~Decorator(){}	
	Decorator(Component *c): component(c){}
	
	virtual void operation(){
		component->operation();
	}
};

class ConcreteDecoratorA: public Decorator{
public:
	ConcreteDecoratorA(Component *c): Decorator(c){}
	
	void operation(){
		Decorator::operation();
		cout << "Decorator A" << endl;
	}
};

class ConcreteDecoratorB: public Decorator{
public:
	ConcreteDecoratorB(Component *c): Decorator(c){}
	
	void operation(){
		Decorator::operation();
		cout << "Decorator B" << endl;
	}
};

int main(){
	ConcreteComponent *cc = new ConcreteComponent();
	ConcreteDecoratorB *db = new ConcreteDecoratorB(cc);
	ConcreteDecoratorA *da = new ConcreteDecoratorA(db);
	
	Component *component = da;
	component->operation();
	
	delete da;
	delete db;
	delete cc;
	
	return 0;
}