/*
Pig Esperanto

For each input word:

    Move the first letter to the end.
    Add the letters "an" to the end of any word of three letters or less, and "o" to the end of any longer word.
    Make the new first letter of the word match the case of the old first letter of the word. Make the letter that was moved lowercase if it is not still the first letter. Do not change the capitalization of any other letters.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main (int argc , char* argv[])
{
	int c ;
	int firstLetter;
	int count = 0;
	
	while((c=getchar())!= EOF)
	{
		if(isalpha(c)){
			if (count == 0){
				firstLetter = c; 
			}	
			else if (count == 1){
				if(isupper(firstLetter)){
					firstLetter = tolower(firstLetter);
					c = toupper(c);	
					putchar(c);
				}else putchar(c);
			}else
				putchar(c);	
		
		count++;
		
		}
		else{
			if(count >= 1){
				putchar(firstLetter);	
					if(count <= 3){
						putchar('a');
						putchar('n');
					}else{
						putchar('o');
					}
			}
			
			count = 0;
			if(c == EOF)
				break;
			else
				putchar(c);	
		}	
		
	}
}
