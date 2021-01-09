#include<iostream>
#include<string>

std::string Singleton::type = "resource_base_class";
Resource *Resource::inst = 0;

Resource *Resource::instance(){
	if(!inst){
		inst = new Resource();
	}
	return inst;
}
