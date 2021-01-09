/*Qn:
1.Write a C program that reads a C program file and perform the following and write it in another file.
	a.Should ignore redundant spaces, tabs and new lines.
	b.ignore comments	*/

#include <stdio.h>
#include <stdlib.h>

/*char* checkLine(char *line,int length){
	printf("%s\n",line);
	return line;
}*/

int main(){
	FILE *ptr,*writePtr;
	char *line = NULL;
	char *writeLine = NULL;
	size_t length = 0;
	ssize_t read;
	int readLength;
	char readChar,writeChar,next;
	ptr = fopen("readfile.c","r");
	writePtr = fopen("writefile.c","w");

	while((readChar = getc(ptr)) != EOF ){
		if(readChar == '/'){
			readChar = getc(ptr);
			if( readChar != EOF && readChar == '/' ){
				while( readChar != EOF && readChar != '\n' ){
					readChar = getc(ptr);
				}
			}
			else if(readChar == '*'){
				readChar = getc(ptr);
				while( readChar != EOF ){
					while( readChar != '*')
						readChar = getc(ptr);
					if( (next = getc(ptr)) == '/' ){
						readChar = getc(ptr);
						break;
					}
				}
			}
		}
		if(readChar != ' ' && readChar != '\t' && readChar != '\n'){
			printf("%c",readChar);
			fprintf(writePtr,"%c",readChar);
		}
	}

	/*while( (read = getline(&line,&length,ptr)) != -1 ){
		readLength = read - 1;
		writeLine = checkLine(line,readLength)
		printf("%s",writeLine);
	}*/
	fclose(ptr);
	return 0;
}
