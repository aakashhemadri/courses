#include<iostream>
#include<string>
#include"resource.h"
#include"singleton.h"
#include"user.h"

int main(){
	Singleton::instance()->setValue(123);
	std::cout<<Singleton::instance()<<" "<<Singleton::instance()->getValue()<<std::endl;
	Singleton::instance()->setValue(11);
	std::cout<<Singleton::instance()<<" "<<Singleton::instance()->getValue()<<std::endl;
	//Singleton hello;
	return 0;
}
