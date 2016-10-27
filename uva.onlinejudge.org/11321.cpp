#include<stdio.h>
#include<stdlib.h>
#define sz 10005
typedef struct{
	int org;
	int mod;
}NUM;
NUM num[sz];
int comp(const void* A, const void* B);

int main()
{
	int n,m,i;

	while(scanf("%d %d",&n,&m)==2)
	{
		printf("%d %d\n",n,m);
		if(n==0 && m==0)break;

		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i].org);
			num[i].mod = num[i].org%m;		
		}
		qsort(num,n,sizeof(NUM),comp);

		
		for(i=0;i<n;i++)
		printf("%d\n",num[i].org);
	
	}

	return 0;
}


int comp(const void* A, const void* B)
{
	NUM *a=(NUM*)A;
	NUM *b=(NUM*)B;
	
	int n1,n2;
	
	if(a->mod < b->mod) return(-1);
	if(a->mod > b->mod) return(1);

	n1 = a->org;
	n2 = b->org;

	if(n1%2==0 && n2%2!=0)return 1;
	if(n1%2!=0 && n2%2==0)return -1;

	if(n1%2==0 && n2%2==0)
	{
		if(n1<n2)return -1;
		if(n1>n2)return 1;
		return 0;
	
	}
	if(n1%2!=0 && n2%2!=0)
	{
		if(n1<n2)return 1;
		if(n1>n2)return -1;
		return 0;
	}
	
	return (0);

}