#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char keywords[][20] = {"auto","double","int","struct","break","else", \
"long","switch","case","enum","register","typedef","char","extern",\
"return","union","continue","for","signed","void","do","if","static",\
"while","default","goto","sizeof","volatile","const","float","short","unisgned"};

const char * filename = "5_input.txt";

int main(){
	int size;
	printf("Reading file... \"5_input.txt\"\n");
	FILE *fp = fopen(filename, "r");
	if(fp == NULL){
		printf("File does not exist!\n");
		return 0;
		}
	char buf;
	int line = 1;
	while((buf = fgetc(fp)) != EOF){
		if(buf == '\n'){
			line++;
			continue;
		}
		if(buf == ' '){
			
		}
	}
	/*
	while(fscanf(fp,"%s",buf) != EOF){
		buf[20]='\0';
		if(strcmp(keywords[i],buf) == 0){
			printf("Entered word is a C keyword.\n");
			break;
		}
		if(buf
	}*/
}
