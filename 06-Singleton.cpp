//06-Singleton

#include <iostream>

class Singleton{
private:
	Singleton(){}
	static Singleton *instance;

public:
	Singleton(Singleton const&) = delete; //cannot be copied. same as private declaration.
	Singleton& operator=(Singleton const&) = delete;

	static Singleton* get(){
		if(!instance){
			instance = new Singleton(); //constructed only once.
		}		
		return instance;
	}
	
	static void restart(){
		if(instance){
			delete instance;
		}
	}
	
	void tell(){
		std::cout << "This is Singleton." << std::endl;
	}
};
Singleton* Singleton::instance = nullptr;

int main(){
	Singleton::get()->tell();
	Singleton::restart();
	
	return 0;
}