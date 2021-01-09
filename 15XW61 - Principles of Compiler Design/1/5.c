#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* input();
char* parse(char *);
int output(char *);

int main(){	
	output(parse(input()));
	return 0;
}

char* input(){
	size_t size;
	printf("Enter the length of the expression: ");
	int len;
	scanf("%d",&len);
	size = len;
	char *input = malloc(sizeof(char)*(size+1));
	printf("Enter the arithmetic expression: ");
	scanf("%*c");
	fgets(input, size, stdin);
	return input;
}

char* parse(char * exp){
	int size = strlen(exp);
	while(exp != '\0'){
		if(isdigit(*exp)){
			
		}
	}
}
