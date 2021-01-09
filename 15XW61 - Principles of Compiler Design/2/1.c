#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Count{
	int digits;
	int consonants;
	int vowels;
	int words;
	int spaces;
	int special_characters;
}Count;

char* input();
Count* parse(char *);
int output(Count *);

int main(){	
	return output(parse(input()));
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

Count* parse(char * exp){
	Count *cnt = malloc(sizeof(Count *));
	int size = strlen(exp);
	char *temp = exp;
	while(exp != exp + strlen(exp) - 1){
		printf("%c",*exp);
		*exp = tolower(*exp);
		if(isdigit((int)*exp)){
			cnt->digits++;
			exp++;
			continue;
		}
		else if(isalpha((char)*exp)){
			if(*exp == 'a' || *exp == 'e' || *exp == 'i' || *exp == 'o' || *exp == 'u'){
				cnt->vowels++;
				exp++;
				continue;
			}
			else {
				cnt->consonants++;
				exp++;
				continue;
			}
		}
		else if(*exp == ' '){	
			cnt->spaces++;
			while(*temp != ' '){
				if(isalpha(*temp)){
					temp++;
					continue;
				}
				else{
					break;
				}
			}
			if(*temp == ' '){
				cnt->words++;
			} 
			temp = exp+1;
			exp++;
			continue;
		}
		else {
			cnt->special_characters++;
			exp++;
		}
	}	
	while(*temp != ' '){
		if(isalpha(*temp)){
			temp++;
			continue;
		}
		else{
			break;
		}
	}
	if(*temp == ' '){
		cnt->words++;
	} 
	return cnt;
}

int output(Count * cnt){
	printf("\nCount of vowels: %d",cnt->vowels);
	printf("\nCount of consonants: %d",cnt->consonants);
	printf("\nCount of digits: %d",cnt->digits);
	printf("\nCount of words: %d",cnt->words);
	printf("\nCount of spaces: %d",cnt->spaces);
	printf("\nCount of special_characters: %d\n",cnt->special_characters);
	return 0;
}
