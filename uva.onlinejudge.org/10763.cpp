//10763 Foreign Exchange
#include<stdio.h>
#include<stdlib.h>
#define sz  500005

typedef struct
{
	long s,t;
}node;
node so[sz],ta[sz];
int comp(void const *a,void const *b)
{
	node *A=(node *)a;
	node *B=(node *)b;

	if(A->s > B->s)
		return 1;
	if(A->s < B->s)
		return -1;

	if(A->t > B ->t)
		return 1;

	if(A->t < B ->t)
		return -1;

	return 0;
}




void main()
{
	
	long i,n,flag;
	while(scanf("%ld",&n)==1 && n)
	{
		//total=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&so[i].s,&so[i].t);

			ta[i].s=so[i].t;
			ta[i].t=so[i].s;
		}

		qsort(so,n,sizeof(node),comp);
		qsort(ta,n,sizeof(node),comp);

		flag=1;

		for(i=0;i<n;i++)
		{
			if(so[i].s!=ta[i].s  || so[i].t!=ta[i].t)
			{
				flag=0;
				break;
			}
		}

		if(flag==1)
			printf("YES\n");

		else
			printf("NO\n");
	}

}