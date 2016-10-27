#include<stdio.h>

void main()
{
 int a[1000001];

 long i,n;
 long sum;



 for(i=1;i<=1000000;i++)
  a[i]=0;


 for(i=1;i<=1000000;i++)
 {
  sum=i;
  n=i;

  while(n>0)
	{
	 sum+= (n%10);
	 n=n/10;
	}



  if(sum>1000000)
	break;
  else
	a[sum]=1;


 }

 for(i=1;i<=1000000;i++)
 {
  if(a[i]==0)
	printf("%ld\n",i);

 }




}