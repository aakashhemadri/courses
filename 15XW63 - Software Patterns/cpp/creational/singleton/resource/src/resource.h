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
