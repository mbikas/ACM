//Acm 10127 The One
//solved by Bikas CSE SUST
#include <stdio.h>

int main(void)
{
	long long int n,num,one,k;

	while (scanf ("%lld",&n)==1)
	{
		num=1;
		one=1;
		while(1)
		{
			k=num%n;
			if (k)
			{
         	num=k;
				num=num*10+1;
            one++;
			}
			else
         	break;
		}
		printf ("%lld\n",one);
	}
   return 0;
}