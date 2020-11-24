//21-State

#include <iostream>
using namespace std;

class State{
public:
	virtual ~State(){}
	virtual void handle() = 0;
};

class ConcreteStateA: public State{
public:
	~ConcreteStateA(){}
	
	void handle(){
		cout << "State A handled." << endl;
	}
};

class ConcreteStateB: public State{
public:
	~ConcreteStateB(){}
	
	void handle(){
		cout << "State B handled." << endl;
	}
};

class Context{
private:
	State *state;
	
public:
	Context(): state(){}
	
	~Context(){
		delete state;
	}
	
	void setState(State* const s){
		if(state){
			delete state;
		}
		state = s;
	}
	
	void request(){
		state->handle();
	}
};

int main(){
	Context *context = new Context();
	
	context->setState(new ConcreteStateA());
	context->request();
	
	context->setState(new ConcreteStateB());
	context->request();
	
	delete context;
	return 0;
}