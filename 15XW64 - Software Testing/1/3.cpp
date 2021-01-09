#include <iostream>
using namespace std;

int triangle(int a, int b, int c){
	if(a > 0 && b > 0 && c > 0 && a <= 100 && b <= 100 && c <= 1000){
		if(a == b && b == c){
			std::cout<<"Equilateral\n";
			return 1;
		}
		if(a != b && b != c && a != c){
			std::cout<<"Scalene\n";
			return 1;
		}
		if(( a != b && b == c ) ||  (a != c && c == b)  || (b !=  a && a == c) || (b != c && c == a) || (c != a && a == b) || (c != b && b == a)){
			std::cout<<"Isoceles\n";
			return 1;
		}
		if(a + b < c || a + c < b || b + c < a){
			std::cout<<"Not a triangle\n";
			return 1;
		}
		
	}
	else{
		std::cout<<"Invalid Input\n";
		return 0;
	}
}
int main() {
	if(triangle(3,3,3) && triangle(3,4,5) && triangle(3,7,3)){
		std::cout<<"All tests passed successfully\n";
	}
	else{
		std::cout<<"Some Tests failed!!\n";
	}
	return 0;
}
