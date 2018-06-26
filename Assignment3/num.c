#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct num {
    char* data;
    int length;
};
typedef struct num Num ;


Num* numCreate(char *s)
{
    Num* n1;
    n1 = malloc(sizeof(Num));
    assert(n1);
    n1->data = s;
    n1->length = strlen(s);

    return n1;
}

//removes the zeros from the begining of the number and displays it on stdout 
void numPrint(Num* s)
{
    int i;
    for(i = 0;i<(s->length) && s->data[i] == '0';i++);
    for(;i < (s->length);i++)
    {
        putchar(s->data[i]);
    }
}

int main (int argc , char **argv)
{
    Num* inputNumber;
    Num* outputNumber;

    for(int i = 0 ; i<argc;i++){
        printf("%s \n",argv[i]);
    }
     
    switch(argv[2][0]){
        case 'p':
            /*parsing and printing the input number*/
            inputNumber = numCreate(argv[1]);
            if (inputNumber == 0){
                printf("numCreate reaturned 0 \n");
            }else{
                numPrint(inputNumber);
            }
    }
}