#include<stdio.h>
#include<stdlib.h>

int parse(char * str, int size){
	if(size == 0){
		return 1;
	}
	else if( str[0] == 'a' ){
		int i = 0;
		for(i = 0; i<size+1 ; i++){
			if(str[i] == 'a'){
				continue;
			}
			else if(str[i] == 'b'){
				break;
			}
			else{
				return 0;
			}
		}
		for(i = i+1; i<size+1; i++){
			if(str[i] == 'b'){
				continue;
			}
			else {
				return 0;
			}
		}
	}
	else 
		return 0;
	return 1;
}	

int main(){
	char *str;
	int length;
	while(1){
		printf("Check if string is \'a*\' or \'a*b+\':\n");
		printf("Enter length of string: ");
		scanf("%d",&length);
		str = malloc((length+1) * sizeof(char));
		printf("Now enter the string: ");
		scanf("%s",str);
		if(parse(str, length)){
			printf("Valid string\n");
		}
		else{
			printf("Invalid string\n");
		}
		char ch;
		printf("Would you like to check another string?(y/n): \n");
		scanf("%*c%c",&ch);
		if(ch != 'y' || ch != 'Y'){
			return 0;
		}
	}
}
