#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* input();
char** parse(char *);
int output(char **);

int main(){	
	return output(parse(input()));
}

char* input(){
	size_t size;
	printf("Enter the length of the string: ");
	int len;
	scanf("%d",&len);
	size = len;
	char *input = malloc(sizeof(char)*(size+2));
	printf("Enter the string: ");
	scanf("%*c");
	input = fgets(input, size + 2, stdin);
	printf("!! String entered: %s",input);
	return input;
}

char** parse(char * exp){
	char **result = malloc(sizeof(char *));
	int size = strlen(exp);
	char *temp = exp;
	int len = 0;
	for(int i = 0 ; i<strlen(exp) ; i++){
		printf("%c ",*exp);
		if(*exp == ';'){
			while(temp != exp){
				len++;
				result = realloc(result, sizeof(char *) * len);
				result[len-1] = malloc((exp-temp+1)*sizeof(char));
				*exp = '\0';
				result[len-1] = temp;
				exp++;
			}
			printf("%s",result[i]);
		}
		else {
			exp++;
		}
	} 
	return result;
}

int output(char **array){
	for(int i = 0 ; i<sizeof(array)/sizeof(array[0]) ; i++){
		printf("%s\n",array[i]);
	}
	return 0;
}
