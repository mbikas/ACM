#include<stdio.h>
#include<stdlib.h>
#define sz 100009 

int f=0;



int comp(void const *A, void const *B)
{

	long *a = (long*)A;
	long *b = (long*)B;

	if(*a>*b)
		return 1;
	if(*a<*b)
		return -1;
	else
	{	f=1;
		return 0;
	}

}

void main()
{
	long n,cases=1,i,j,a[105],x,old,p;
	int flag;
	long sum[sz];
	while(scanf("%ld",&n)==1)
	{
		old = 0;
		flag=0;
		f=0;

		for(i=0;i<n;i++)
		{
			scanf("%ld",&x);
			if(x>old)
			{
				old=x;
			}
			else
				flag=1;

			a[i]=x;
		
		}

		if(flag==1)
			printf("Case #%ld: It is not a B2-Sequence.\n\n",cases++);
		else
		{
			p=0;
			for(i=0;i<n;i++)
			{
				for(j=i;j<n;j++)
				{
					sum[p++] = a[i]+a[j];
				}
			}

			//for(i=0;i<p;i++)
			//	printf("%ld ",sum[i]);
			//printf("\n");


			qsort(sum,p,sizeof(sum[0]),comp);

			
			/*
			x=sum[0];
			flag=0;
			for(i=1;i<p;i++)
			{
				if(x==sum[i])
				{
					flag=1;
					break;
				}
				else
					x = sum[i];
			
			}

			for(i=0;i<p;i++)
				printf("%ld ",sum[i]);
			printf("\n");

			if(flag==1)
				printf("Case #%ld: It is not a B2-Sequence.\n\n",cases++);
			else
				printf("Case #%ld: It is a B2-Sequence.\n\n",cases++);
			*/
			if(f==1)
				printf("Case #%ld: It is not a B2-Sequence.\n\n",cases++);
			else
				printf("Case #%ld: It is a B2-Sequence.\n\n",cases++);
		
		}
	
	}



}