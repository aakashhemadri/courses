#include<iostream>
#include<stack>
#include<string>

int main(){
std::stack<char> expression;
std::string str;
std::cout<<"Enter the string: ";
std::cin>>str;
for(std::string::iterator it = str.begin(); it != str.end() ; it++){
		
		expression.push(*it);
	}
}
