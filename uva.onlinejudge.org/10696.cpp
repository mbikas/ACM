#include<iostream>
#include<cstdio>
using namespace std;

long greater(long n)
{

	return n-10;
}

long lesser(long n)
{
	if(n<=100) 
		return lesser(lesser(n+11));

    if (n>=101)
		return n-10;


	 
}




int main()
{
 

	long n,p;

	while ( ( scanf("%ld",&n)==1 ) && n!=0 )
	{
		
		if(n>=101)
           p = greater(n);
		else
           p = lesser(n);

		printf("f91(%ld) = %ld\n",n,p);

		            	
	}

 return 0;
}