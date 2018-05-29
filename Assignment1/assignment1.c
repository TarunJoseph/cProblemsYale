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
