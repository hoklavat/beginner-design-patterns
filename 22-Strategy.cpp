//22-Strategy

#include <iostream>
using namespace std;

class Strategy{
public:
	virtual ~Strategy(){}
	virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA: public Strategy{
public:
	~ConcreteStrategyA(){}
	
	void algorithmInterface(){
		cout << "Concrete Strategy A" << endl;
	}
};

class ConcreteStrategyB: public Strategy{
public:
	~ConcreteStrategyB(){}
	
	void algorithmInterface(){
		cout << "Concrete Strategy B" << endl;
	}
};

class ConcreteStrategyC: public Strategy{
public:
	~ConcreteStrategyC(){}
	
	void algorithmInterface(){
		cout << "Concrete Strategy C" << endl;
	}
};

class Context{
private:
	Strategy *strategy;
	
public:
	Context(Strategy* const s): strategy(s){}
	
	~Context(){
		delete strategy;
	}
	
	void contextInterface(){
		strategy->algorithmInterface();
	}
};

int main(){
	Context context(new ConcreteStrategyA());
	context.contextInterface();
	
	return 0;
}