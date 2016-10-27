#include<stdio.h>

int isPrime( unsigned long num);

void main()
{

 int a[10002],i,m,n;
 unsigned long p;
 double x;

 for(i=0;i<=10000;i++)
 {
  p= i*i + i +41 ;

  if(isPrime(p)==1)
	a[i]=1;
  else
	a[i]=0;

 }


 while(scanf("%d %d",&m,&n)==2)
 {
  p=0;

  for(i=m;i<=n;i++)
	{ if(a[i]==1)
	  p++;
	}


  i =n-m+1;

  x= (double)p/i;
  x=x*100;


  	printf("%.2lf\n",x);

 }

}

 int isPrime( unsigned long num){


		  if (num<=1) return 0;         /* 1 is NOT a prime               */
		  if (num==2) return 1;         /* 2 is a prime                   */
		  if (num%2==0) return 0;       /* NO prime is EVEN, except 2     */

		  for (unsigned long i=3;i*i<=num;i+=2)  /* start from 3, jump 2 numbers   */
			 {	if (num%i==0)                       /*  no need to check even numbers */
						return 0;
			 }
			return 1;
	 }