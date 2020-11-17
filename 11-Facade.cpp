//11-Facade

#include <iostream>
using namespace std;

class SubsystemA{
public:
	void suboperation(){
		cout << "Subsystem A method" << endl;
	}
};

class SubsystemB{
public:
	void suboperation(){
		cout << "Subsystem B method" << endl;
	}
};

class SubsystemC{
public:
	void suboperation(){
		cout << "Subsystem C method" << endl;
	}
};

class Facade{
private:
	SubsystemA *subsystemA;
	SubsystemB *subsystemB;
	SubsystemC *subsystemC;
	
public:
	Facade(): subsystemA(), subsystemB(), subsystemC() {}
	
	void operation1(){
		subsystemA->suboperation();
		subsystemB->suboperation();
	}
	
	void operation2(){
		subsystemC->suboperation();
	}
};

int main(){
	Facade *facade = new Facade();
	
	facade->operation1();
	facade->operation2();
	delete facade;
	
	return 0;
}