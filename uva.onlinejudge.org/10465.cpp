#include<stdio.h>

void main()
{

	long m,n,p,t,x,sum,i,j,temp,rem,rem1,q,f,min,ans;
	
	while(scanf("%ld %ld %ld",&m,&n,&t)==3)
	{

		min = 10001;
		if(n<m)
		{
			temp = m;
			m = n;
			n = temp;		
		}

		p = t / m;
		rem = t - p * m;
	
		if(rem==0)
		{	printf("%ld\n",p);
			continue;
		}	


		sum = p;
		f=0;
		for(i= p-1 ;i>=0;i--)
		{
			x = i * m;
			q = t - x;

			if(q%n==0)
			{
				j = q / n;
				f=1;
				sum = i + j;
				break;
			}			
		}

		if(f==1)
		{	printf("%ld\n",sum);
		    continue;
		}

		q = t / n;
		min = rem;
		ans  = p;
		for(i=p;i>=0;i--)
		{
			for(j = q;j>=0;j--)
			{
				x = i*m + j * n;
				if(x<t)
				{
					rem1 = t - x;
					if(rem1<min)
					{
						min = rem1;
						ans = i+j;			
					}			
				}		
			}
		}

		printf("%ld %ld\n",ans,min);



	
	}
}
