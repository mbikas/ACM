#include<stdio.h>

long GCD(long a,long b);


void main()
{

	long a,b,p;


	while(scanf("%ld %ld",&a,&b)==2)
	{
		p = GCD(a,b);
		printf("%ld\n",p);

	}
}


long  Gcd(long a ,long b) 
{ 
        if(b==0) 
                return a; 
        else 
             return Gcd(b,a%b); 
} 

