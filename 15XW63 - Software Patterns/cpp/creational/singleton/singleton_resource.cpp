#include<iostream>
#include<string>

class Resource{
	public:
		static Singleton *instance();
		static void setType(std::string t){
			type t;
			delete inst;
			inst = 0;
		}
		virtual void setValue(int in){
			value = in;
		}
		virtual int getValue(){
			return value;
		}
	protected:
		int value;
		Resource(){
			std::cout<<":resource: "<<inst;
		}	
	private:
		static std::string type;
		static Resource *inst;
};

std::string Singleton::type = "resource_base_class";
Resource *Resource::inst = 0;

Resource *Resource::instance(){
	if(!inst){
		inst = new Resource();
	}
	return inst;
}

class Singleton {
	public:
		static Singleton *instance();
		static void setType(std::string t){
			type = t;
			delete inst;
			inst = 0;
		}
		virtual void setValue(int in){
			value = in;
		}
		virtual int getValue(){
			return value;
		}
	protected:
		int value;
		Singleton(){
			std::cout<<":ctor: ";
		}
	private:
		static std::string type;
		static Singleton *inst;
};

std::string Singleton::type = "base_class";
Singleton *Singleton::inst = 0;

Singleton *Singleton::instance(){
	if(!inst){
		inst = new Singleton();
	}
	return inst;
} 

class User{

}

int main(){
	Singleton::instance()->setValue(123);
	std::cout<<Singleton::instance()<<" "<<Singleton::instance()->getValue()<<std::endl;
	Singleton::instance()->setValue(11);
	std::cout<<Singleton::instance()<<" "<<Singleton::instance()->getValue()<<std::endl;
	//Singleton hello;
	return 0;
}
