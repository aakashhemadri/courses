#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Assuming that identifiers relational and arithmetic operators are seperated by spaces.
char *encrypt(char *dest, char *str, int size){
	char word[50];
	while(str[0] == '\0'){
		sscanf(str,"%s",word);
		str += strlen(word)+1;
		if(strcmp(word,"+") == 0 || strcmp(word,"-") == 0 || strcmp(word,"*") == 0 || \
		strcmp(word,"/") == 0 || strcmp(word,"=") == 0){		
			dest = (char *)realloc(dest, strlen(dest) + strlen("AOP") + 1);
			strcat(dest,"AOP");
			continue;
		}
		if(strcmp(word,"!=") == 0 || strcmp(word,">") == 0 || strcmp(word,"<") == 0 || \
		strcmp(word,">=") == 0 || strcmp(word,"==") == 0 ){
			dest = (char *)realloc(dest, strlen(dest) + strlen("ROP") + 1);
			strcat(dest,"ROP");
			continue;
		}
		switch(word[0]){
			case '&':
			case '!':
			case '#':
			case '$':
			case '%':
			case '^':
			case '@':
			case '(':
			case ')':
			case '{':
			case '}':
			case '[':
			case ']':
			case ':':
			case ';':
			case ',':
			case '.':
			case '?':
			case '/':
			case '|':
			case '`':
			case '~':
			case '\\':
				dest = (char *)realloc(dest, strlen(dest) + strlen(word) + 1);
				strcat(dest,word);
				break;
			default:
				dest = (char *)realloc(dest, strlen(dest) + strlen("identifier") + 1);
				strcat(dest,"identifier");
				break;				
		}
	}
	return dest;	
}

int main(){
	int length;
	printf("Enter the length of the string: ");
	scanf("%d",&length);
	char *str = (char *)malloc((length+1)*sizeof(char));
	printf("Enter the string: ");
	scanf("%s",str);
	printf("Old String:\n%s\n", str);
	char *dest = (char *)malloc(sizeof(char));
	printf("New String:\n%s\n", encrypt(dest, str, strlen(str)));
}
