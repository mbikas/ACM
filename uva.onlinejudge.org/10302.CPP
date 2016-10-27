//10302 Summation Of Polynomials
//solved by Bikas CSE SUST
#include<stdio.h>
void main()
{
         unsigned int x;
	 long double  sum;
	 while(scanf("%u",&x)==1 && x>=1 && x<=50000)
	 {
		  sum=.25*x*x*(x+1)*(x+1);
		  printf("%.0Lf\n",sum);
	 }
}