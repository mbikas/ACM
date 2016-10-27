#include<stdio.h>
#include<math.h>



void main()
{

	long t,max=0,i,total=1,nodiv;
	long  m,n,k,x,j,number;
	scanf("%ld",&t);

	for(i=0;i<t;i++)
	{
		scanf("%ld %ld",&m,&n);

		max=0;

		for(k=m;k<=n;k++)
		 {
			x=k;
			total=1;

			for(j=2;j<=sqrt(n)+1;j++)
			{
			  nodiv=1;
			  while(!(x%j))
				{  nodiv++;
					x/=j;
				}
			  total*=nodiv;
			}

			if(x!=1)
			  total*=2;
			if(total>max)
			  {
				 max=total;
				 number=k;
			  }
		  }
		  printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",m,n,number,max);
		}


 }


