//23-TemplateMethod

#include <iostream>
using namespace std;

class AbstractClass{
public:
	virtual ~AbstractClass(){}	
	virtual void primitiveOperation1() = 0;
	virtual void primitiveOperation2() = 0;
	
	void templateMethod(){
		primitiveOperation1();
		primitiveOperation2();
	}	
};

class ConcreteClass: public AbstractClass{
public:
	~ConcreteClass(){}
	
	void primitiveOperation1(){
		cout << "Primitive operation 1" << endl;
	}
	
	void primitiveOperation2(){
		cout << "Primitive operation 2" << endl;
	}
};

int main(){
	AbstractClass *tm = new ConcreteClass;
	tm->templateMethod();	
	delete tm;
	
	return 0;
}