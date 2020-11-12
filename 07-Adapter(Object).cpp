//07-Adapter(Object)

#include <iostream>
using namespace std;

class Target{
public:
	virtual ~Target(){}	
	virtual void request() = 0;
};

class Adaptee{	
public:
	void specificRequest(){
		cout << "specific request." << endl;
	}
};

class Adapter: public Target{
private:
	Adaptee *adaptee;
	
public:
	Adapter(): adaptee(){}
	
	~Adapter(){
		delete adaptee;
	}
	
	void request(){
		adaptee->specificRequest();
	}
};

int main(){
	Target *t = new Adapter();
	t->request();
	delete t;
	
	return 0;
}