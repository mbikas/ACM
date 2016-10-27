#include<stdio.h>
#include<stdlib.h>
#define sz 10005
long a[sz],b[sz],c[sz],pro[sz];
long r1[sz],r2[sz],r3[sz];


int comp(void const *a,void const *b)
{
	long *A=(long *)a;
	long *B=(long *)b;

	return *A-*B;

}
void main()
{
	long i,test,cases=1,temp;

	scanf("%ld",&test);

	while(test--)
	{
		

		for(i=1;i<sz;i++)
			pro[i]=0;

		scanf("%ld",&a[0]);

		for(i=1;i<=a[0];i++)
		{
			scanf("%ld",&temp);
			a[i]=temp;
			pro[temp]+=1;
		}


		scanf("%ld",&b[0]);

		for(i=1;i<=b[0];i++)
		{
			scanf("%ld",&temp);
			b[i]=temp;
			pro[temp]+=2;
		}

		scanf("%ld",&c[0]);

		for(i=1;i<=c[0];i++)
		{
			scanf("%ld",&temp);
			c[i]=temp;
			pro[temp]+=4;
		}

		temp=0;

		
		r1[0]=r2[0]=r3[0]=0;
		for(i=1;i<=a[0];i++)
		{
			if(pro[a[i]]==1)
			{
				r1[0]++;

				r1[r1[0]]=a[i];
			}
		}

		for(i=1;i<=b[0];i++)
		{
			if(pro[b[i]]==2)
			{
				r2[0]++;

				r2[r2[0]]=b[i];
			}
		}
		
		for(i=1;i<=c[0];i++)
		{
			if(pro[c[i]]==4)
			{
				r3[0]++;

				r3[r3[0]]=c[i];
			}
		}

		printf("Case #%ld:\n",cases++);
		
		if(r1[0]>=r2[0]  && r1[0]>=r3[0])
		{
			printf("1");

			qsort(r1+1,r1[0],sizeof(r1[0]),comp);

			printf(" %ld",r1[0]);

			for(i=1;i<=r1[0];i++)
				printf(" %ld",r1[i]);

			printf("\n");
		}

		if(r2[0]>=r1[0]  && r2[0]>=r3[0])
		{
			printf("2");

			qsort(r2+1,r2[0],sizeof(r2[0]),comp);

			printf(" %ld",r2[0]);

			for(i=1;i<=r2[0];i++)
				printf(" %ld",r2[i]);

			printf("\n");
		}

		if(r3[0]>=r2[0]  && r3[0]>=r1[0])
		{
			printf("3");

			qsort(r3+1,r3[0],sizeof(r3[0]),comp);
			printf(" %ld",r3[0]);

			for(i=1;i<=r3[0];i++)
				printf(" %ld",r3[i]);

			printf("\n");
		}


	}
}