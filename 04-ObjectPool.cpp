//04-ObjectPool

#include <string>
#include <iostream>
#include <list>

class Resource{
private:	
	int value;
	
public:
	Resource(){
		value = 0;
	}
	
	void reset(){
		value = 0;
	}
	
	int getValue(){
		return value;
	}
	
	void setValue(int number){
		value = number;
	}
};


class ObjectPool{
private:
	std::list<Resource*> resources;
	static ObjectPool* instance;
	ObjectPool(){} //private constructor
	
public:
	static ObjectPool* getInstance(){
		if(instance == 0){
			instance = new ObjectPool;
		}
		return instance;
	}

	Resource* getResource(){
		if(resources.empty()){
			std::cout << "Creating new." << std::endl;
			return new Resource;
		}
		else{
			std::cout << "Reusing existing." << std::endl;
			Resource* resource = resources.front();
			resources.pop_front();
			return resource;
		}
	}

	void returnResource(Resource* object){
		object->reset();
		resources.push_back(object);
	}
};
ObjectPool* ObjectPool::instance = 0;

int main(){
	ObjectPool* pool = ObjectPool::getInstance();	
	
	//create new resources in the pool.
	Resource* one;
	one = pool->getResource();
	one->setValue(10);
	std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
	
	Resource* two;
	two = pool->getResource();
	two->setValue(20);
	std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
	
	pool->returnResource(one);
	pool->returnResource(two);
	
	//reuse existing resources in the pool.
	one = pool->getResource();
	std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
	
	two = pool->getResource();
	std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

	return 0;
}