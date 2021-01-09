#include"singleton.h"

Singleton *Singleton::instance(){
	if(!inst){
		inst = new Singleton();
	}
	return inst;
} 
