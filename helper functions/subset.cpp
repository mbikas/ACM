#include<stdio.h>
#define MAX 20

void process_solution(int n,int k,int a[]);
void con_can(int n,int k,int a[],int c[],int *ncandidate);
void subset(int n,int k,int a[]);

void main()
{

	int i,n,a[MAX];

	while(scanf("%d",&n)==1)
	{

		for(i=0;i<=n;i++)a[i]=1;
		subset(n,0,a);
	
	}
}




void subset(int n,int k,int a[])
{
	int i,c[MAX],ncandidate;
  
	if(k>=1)
	{
		if(k==1)
			printf("%d ",a[k]);	
		process_solution(n,k,a);
	}
  	if(n==k)return;
  
	k++;
	con_can(n,k,a,c,&ncandidate);
	for(i=0;i<ncandidate;i++)
	{
		a[k]=c[i];
		subset(n,k,a);
	}
}

void con_can(int n,int k,int a[],int c[],int *ncandidate)
{  
	int i;
	*ncandidate=0;

	if(k==1)
	{
		for(i=1;i<=n;i++)
			c[(*ncandidate)++]=i;
		return; 
	
	}
	for(i=a[k-1]+1;i<=n;i++)
		c[(*ncandidate)++]=i;
}

void process_solution(int n,int k,int a[])
{
  int i;

  printf("{");
  for(i=1;i<k;i++)
    printf("%d,",a[i]);
  if(k>0) 
	  printf("%d",a[k]);
  printf("}\n");
}
