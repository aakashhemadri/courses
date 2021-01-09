#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char keywords[][2020] = {"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","continue","for","signed","void","do","if","static","while","default","goto","sizeof","volatile","const","float","short","unisgned"};

int main(){
	int size;
	printf("Enter the size of the word to be entered: ");
	scanf("%d",&size);
	char *input = (char *)malloc(sizeof(char)*(size+1));
	printf("Enter the word: ");
	scanf("%s",input);
	for( int i = 0; i<32 ; i++){
		if(strcmp(keywords[i],input) == 0){
			printf("Entered word is a C keyword.\n");
			return 0;
		}
	}
printf("Entered word is *not* a C keyword!\n");
	return 0;
}
