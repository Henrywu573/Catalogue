/*E35 Count vowels in a string*/
#include<stdio.h>
#include<string.h>
int count_vowels (char *str); 
	  
int main() 
{ 
	char str[100]; 
	printf("Enter a string :");
    gets(str);
	printf("%d\n",countVowels(str));
} 
int countVowels(char *str) 
{ 
    if(*str == '\0') 
		return 0;
	switch(*str) 
    { 
	    case 'A': case 'a':
		case 'E': case 'e': 
		case 'I': case 'i': 
		case 'O': case 'o': 
		case 'U': case 'u': 
             return 1 + countVowels(str+1); 
		default:  
             return countVowels(str+1); 
    } 
}

