//15-Command

#include <iostream>
using namespace std;

class Receiver{
public:
	void action(){
		cout << "Receiver: execute action" << endl;
	}
};

class Command{
protected:
	Command(){}
	
public:
	virtual ~Command(){}
	virtual void execute() = 0;
};

class ConcreteCommand: public Command{
private:
	Receiver *receiver;
	
public:
	ConcreteCommand(Receiver *r): receiver(r){}
	
	~ConcreteCommand(){
		if (receiver){
			delete receiver;
		}
	}
	
	void execute(){
		receiver->action();
	}
};

class Invoker{
private:
	Command *command;
	
public:
	void set(Command *c){
		command = c;
	}
	
	void confirm(){
		if (command){
			command->execute();	
		}
	}
};

int main(){
	ConcreteCommand command(new Receiver());
	
	Invoker invoker;
	invoker.set(&command);
	invoker.confirm();
	
	return 0;
}