nclude <iostream>
using namespace std;

int quadraticSolution(int a, int b, int c){
	if(a >= 0 && a <= 100 && b >= 0 && b <=100 && c >= 0 && c <=100){
		if((b^2 - 4*a*c) > 0){
			std::cout<<"Real roots\n";
			return 1;
		}
		if((b^2 - 4*a*c) == 0){
			std::cout<<"Equal roots\n";
			return 1;
		}
		if((b^2 - 4*a*c) > 0){
			std::cout<<"Imaginary roots\n";
			return 1;
		}
		
	}
	else{
		std::cout<<"Invalid Input\n";
		return 0;
	}
}
int main() {
	if(quadraticSolution(1,2,1) && quadraticSolution(-1,50,5)){
		std::cout<<"All tests passed successfully\n";
	}
	else{
		std::cout<<"Some Tests failed!!\n";
	}
	return 0;
}
