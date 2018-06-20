#include<stdio.h>
#include<stdlib.h>

/*
void transpose() encrypts blocks of characters of size n with jth i/p = to ith o/p 
(where, j = (a*i+b)%n)
*/
void transpose(char* messageBlock, char* encryptedBlock, int n, int a, int b )
{
    for(int i = 0;i < n; i++){
        int j = ((a*i+b)%n);
        encryptedBlock[i] = messageBlock[j];
    }
}

//display() functions outputs the encrypteBlock to stdout
void display(char* encryptedBlock , int size)
{
    for (int i = 0;i < size;i++){
        putchar(encryptedBlock[i]);
    }
}

int main (int argc , char **argv)
{
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    char* messageBlock = malloc(n) ;
    char* encryptedBlock = malloc(n);

    int c;
    int i = 0;
    while((c = getchar()) != EOF) //reads a single character from stdin till EOF
    {
        messageBlock[i++] = c;
        /*
        When a block of text of size n has been read it is encrypted by transpose
        and then displayed in stdout
        */
        if (i == n){
            transpose(messageBlock,encryptedBlock,n,a,b);
            display(encryptedBlock , n);
            i = 0; //to restart the count for the block 
        }   
    }
    //for padding the message with '\0'
    if (i > 0){
        for(;i < n;i++){
            messageBlock[i] = '\0';            
        }
        transpose(messageBlock,encryptedBlock,n,a,b);
        display(encryptedBlock , n);
    }
    
}

