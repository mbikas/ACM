//Acm 10079 Pizza Cutting
//solved by Bikas CSE SUST

#include<stdio.h>
long double m;
long long int n;
void main()
{  
  
  while(scanf("%lld",&n)==1&&n>=0)
  {
      if(n%2==0)
	m=((n/2)*(n+1))+1;
      else
	m=(((n+1)/2)*n)+1;

        
      
        
	 printf("%.0Lf\n",m);

  }
}