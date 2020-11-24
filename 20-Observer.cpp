//20-Observer

#include <iostream>
#include <vector>
using namespace std;

class Subject;

class Observer{
public:
	virtual ~Observer(){}	
	virtual int getState() = 0;
	virtual void update(Subject *subject) = 0;
};

class ConcreteObserver: public Observer{
private:
	int observer_state;
	
public:
	ConcreteObserver(const int state): observer_state(state){}	
	~ConcreteObserver(){}
	
	int getState(){
		return observer_state;
	}
	
	void update(Subject *subject);
};

class Subject{
private:
	vector<Observer*> observers;
	
public:
	virtual ~Subject(){}
	
	void attach(Observer *observer){
		observers.push_back(observer);
	}
	
	void detach(const int index){
		observers.erase(observers.begin() + index);
	}
	
	void notify(){
		for (unsigned int i = 0; i < observers.size(); i++){
			observers.at(i)->update(this);
		}
	}
	
	virtual int getState() = 0;
	virtual void setState(const int s) = 0;
};

class ConcreteSubject: public Subject{
private:
	int subject_state;
	
public:
	~ConcreteSubject(){}
	
	int getState(){
		return subject_state;
	}
	
	void setState(const int s){
		subject_state = s;
	}
};

void ConcreteObserver::update(Subject *subject){
	observer_state = subject->getState();
	cout << "Observer state updated." << endl;
}

int main(){
	ConcreteObserver observer1(1);
	ConcreteObserver observer2(2);
	
	cout << "Observer 1 state: " << observer1.getState() << endl;
	cout << "Observer 2 state: " << observer2.getState() << endl;
	
	Subject *subject = new ConcreteSubject();
	subject->attach(&observer1);
	subject->attach(&observer2);
	
	subject->setState(10);
	subject->notify();
	
	cout << "Observer 1 state: " << observer1.getState() << endl;
	cout << "Observer 2 state: " << observer2.getState() << endl;

	delete subject;	
	return 0;
}