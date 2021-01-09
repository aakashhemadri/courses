/**
* Using following NFA check whether the input string abbba is valid or not.
* ->q0-e->(q1)
*   |\<-a-//
*   |     /
*   |    V
*    \->q2<--b
*        \--/
*/

#include<regex>
#include<iostream>
#include<string>

int main(){
	std::cout<<"Enter the string that you'd like to enter into the NFA(a/b): ";
	std::string input;
	std::cin>>input;
	std::cout<<"This is the input string: "<<input<<std::endl;	
	return 0;
}


/*
int main(){
std::cout<<"Enter the string you'd like to match the NFA: ";
std::string str;
std::cin>>str;
std::regex reg("(a((b*|(a|b))a)*");
try {
	if(std::regex_match (str,reg)){
		std::cout<<"String Matched!\n";
	}
	else {
		std::cout<<"String does not match!\n";
	}
} catch (std::regex_error &e){
		std::cerr<<e.code();
	}
}
*/
