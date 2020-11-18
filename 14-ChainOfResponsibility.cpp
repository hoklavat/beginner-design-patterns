//14-ChainOfResponsibility

#include <iostream>
using namespace std;

class Handler{
private:
	Handler *successor;
	
public:
	virtual ~Handler(){}
	
	virtual void setHandler(Handler *s){
		successor = s;
	}
	
	virtual void handleRequest(){
		if(successor != 0){
			successor->handleRequest();
		}
	}
};

class ConcreteHandler1: public Handler{
public:
	~ConcreteHandler1(){}
	
	bool canHandle(){
		return false;
	}
	
	virtual void handleRequest(){
		if(canHandle()){
			cout << "Handled by Concrete Handler 1" << endl;
		}
		else{
			cout << "Cannot be handled by Handler 1" << endl;
			Handler::handleRequest();
		}
	}
};

class ConcreteHandler2: public Handler{
public:
	~ConcreteHandler2(){}
	
	bool canHandle(){
		return true;
	}
	
	virtual void handleRequest(){
		if(canHandle()){
			cout << "Handled by Handler 2" << endl;
		}
		else{
			cout << "Cannot be handled by Handler 2" << endl;
			Handler::handleRequest();
		}
	}
};

int main(){
	ConcreteHandler1 handler1;
	ConcreteHandler2 handler2;
	
	handler1.setHandler(&handler2);
	handler1.handleRequest();
	
	return 0;
}