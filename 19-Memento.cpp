//19-Memento

#include <iostream>
#include <vector>
using namespace std;

class Memento{
private:
	int state;
	
private:
	Memento(const int s): state(s){}
	friend class Originator;
	
	void setState(const int s){
		state = s;
	}
	
	int getState(){
		return state;
	}
};

class Originator{
private:
	int state;
	
public:
	void setState(const int s){
		cout << "Set state to " << s << "." << endl;
		state = s;
	}
	
	int getState(){
		return state;
	}
	
	Memento *createMemento(){
		return new Memento(state);
	}
	
	void setMemento(Memento* const m){
		state = m->getState();
	}
};

class CareTaker{
private:
	Originator *originator;
	vector<Memento*> history;
	
public:
	CareTaker(Originator* const o): originator(o){}
	
	~CareTaker(){
		for (unsigned int i = 0; i < history.size(); i++)
		{
			delete history.at(i);
		}
		history.clear();
	}
	
	void save(){
		cout << "Save state." << endl;
		history.push_back(originator->createMemento());
	}
	
	void undo(){
		if (history.empty()){
			cout << "Unable to undo state." << endl;
			return;
		}
		
		Memento *m = history.back();
		originator->setMemento(m);
		cout << "Undo state." << endl;
		
		history.pop_back();
		delete m;
	}
};

int main(){
	Originator *originator = new Originator();
	CareTaker *caretaker = new CareTaker(originator);
	
	originator->setState(1);
	caretaker->save();
	
	originator->setState(2);
	caretaker->save();
	
	originator->setState(3);
	caretaker->undo();
	
	cout << "Actual state is " << originator->getState() << "." << endl;
	
	delete originator;
	delete caretaker;
	
	return 0;
}