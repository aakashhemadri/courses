#include<stdio.h>#include<stdlib.h>structthreeNum{intn1,n2,n3;};intmain(){intn;structthreeNumnum;FILE*fptr;if((fptr=fopen("C:\\program.bin","wb"))==NULL){printf("Error!openingfile");fwrite(&num,sizeof(structthreeNum),1,fptr);}fclose(fptr);return0;}