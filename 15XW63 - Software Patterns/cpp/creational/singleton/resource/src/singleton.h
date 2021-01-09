#include<iostream>
#include<string>

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
