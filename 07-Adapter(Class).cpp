//07-Adapter(Class)

#include <iostream>
using namespace std;

class Target{
public:
	virtual ~Target(){}	
	virtual void request() = 0;
};

class Adaptee{
public:
	~Adaptee(){}
	
	void specificRequest(){
		cout << "specific request." << endl;
	}
};

class Adapter: public Target, private Adaptee{
public:
	virtual void request(){
		specificRequest();
	}
};

int main(){
	Target *t = new Adapter();
	t->request();
	delete t;
	
	return 0;
}