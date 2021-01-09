#include"singleton.h"

std::string Singleton::type = "base_class";
Singleton *Singleton::inst = 0;

int main(){
	Singleton::instance()->setValue(123);
	std::cout<<Singleton::instance()<<" "<<Singleton::instance()->getValue()<<std::endl;
	Singleton::instance()->setValue(11);
	std::cout<<Singleton::instance()<<" "<<Singleton::instance()->getValue()<<std::endl;
	//Singleton hello;
	return 0;
}
