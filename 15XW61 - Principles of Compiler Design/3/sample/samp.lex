%{
#include <stdio.h>
int vowelCount = 0,consonantCount = 0;
%}

vowels [aeiouAEIOU]
consonants [bcdfghjklmnpqrstvwxyz]

%%

{vowels} {vowelCount++;}
{consonants} {consonantCount++;}
"\n" {printf("The vowel count : %d\nThe consonant count : %d",vowelCount,consonantCount);}

%%
int yywrap(void){}

int main(){
	yylex();
	return 0;
}
