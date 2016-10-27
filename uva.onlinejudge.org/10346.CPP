//Acm 10346 Peter's Smokes
//solved by Bikas CSE SUST
#include<stdio.h>
void main()
{
        unsigned long n,k,rem,div;
        double total;
	while(scanf("%lu%lu",&n,&k)==2)
	{
		  total=n;
		  rem=0;
		  div=n;
		  while(div>=k)
		  {
			 total+=div/k;
                         rem=div%k;
			 div=(div)/k+rem;
                         
		  }
		  printf("%.0lf\n",total);
		        
	}
}