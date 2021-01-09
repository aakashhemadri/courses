#include<iostream>
#include<string>

std::string Singleton::type = "base_class";
Singleton *Singleton::inst = 0;

Singleton *Singleton::instance(){
	if(!inst){
		inst = new Singleton();
	}
	return inst;
}
