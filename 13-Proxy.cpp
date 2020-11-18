//13-Proxy

#include <iostream>
using namespace std;

class Subject{
public:
	virtual ~Subject(){}
	virtual void request() = 0;
};

class RealSubject: public Subject{
public:
	void request(){
		cout << "Real Subject request" << endl;
	}
};

class Proxy: public Subject{
private:
	RealSubject *subject;
	
public:
	Proxy(){
		subject = new RealSubject();
	}
	
	~Proxy(){
		delete subject;
	}
	
	void request(){
		subject->request();
	}
};

int main(){
	Proxy *proxy = new Proxy();
	proxy->request();
	
	delete proxy;
	return 0;
}