						//Acm369 Combinations
						//Solved By Bikas Cse Sust

#include<stdio.h>

void main()
{
 int m,n,k,p;  // long
 double result;

 while(scanf("%d %d",&n,&m)==2 && (m!=0 || n!=0))    //%ld
 {
	 if(m>n-m)
	  {
		k=m;
		p=n-m;
	  }
	 else
	  {
		k=n-m;
		p=m;
	  }

	 result=1;

	 while(k<n)
	  {
		result*= (k+1);
		result=result/p;
		if(p>1)
		p--;

		k++;
	  }

	  printf("%d things taken %d at a time is %.0lf exactly.\n",n,m,result);    //%ld
    

 }
}
