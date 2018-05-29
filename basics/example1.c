/*Test for overflow of data types and conversion from string to integer*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char** argv )
{
	char c ;
	int i;
	long l;
	long long ll;

	if(argc != 2){
		fprintf(stderr,"Usage : %s \n",argv[0]);
		return 1 ;
	}

	c = atoi(argv[1]);
	i = atoi(argv[1]);
	l = atol(argv[1]);
	ll = atoll(argv[1]);

	printf("char : %d ,int : %d, long: %ld, long long:%lld \n ",c,i,l,ll);
	return 0 ;
}
