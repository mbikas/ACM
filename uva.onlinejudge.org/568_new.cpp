#include<stdio.h>

typedef struct{
	long num;
}fact;
fact fac[10005];

void main()
{   
	long int sum,i;
	int rem,n;
	
	fac[0].num=1;
	for(i=1;i<=10000;i++)
	{
	  sum = ( i * fac[i-1].num)%1000000;
	  

	  rem=  (int) (sum%10);
	  while(rem==0)
	  {
		sum = sum/10;
		rem = (int)( sum%10);
	  }
	  fac[i].num=(long)sum;	
	}

	while(scanf("%d",&n)==1)
	{
		//printf("%ld\n",fac[n].num);
		rem = (int)(fac[n].num%10);
		printf("%5d -> %d\n",n,rem);
	}


}
    