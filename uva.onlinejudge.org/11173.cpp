#include<stdio.h>


void main()
{
	long test,a,b;


	scanf("%ld",&test);


	while(test--)
	{
		scanf("%ld %ld",&a,&b);
		printf("%ld\n",(b^(b>>1)));
	
	}


}