#include<stdio.h>
#include<string.h>

bool finished = false;
#define MAX 105
long num[MAX],target;
void backtrack(char a[],long k,long n);
void con_candidate(char a[],long n,long k,char c[],long *ncan);
void process_solution(char a[],long k,long n);
bool val[101][64002];

void main()
{
	long n,test,i;
	char a[MAX];

	scanf("%ld",&test);
	while(test--)
	{
		finished = false;
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		scanf("%ld",&num[i]);

		memset(val,false,sizeof(val));
		scanf("%ld",&target);
		for(i=0;i<=n;i++)a[i]=0;

		backtrack(a,0,n-1);
		if(!finished)
			printf("NO EXPRESSION\n");
	}
}

void backtrack(char a[],long k,long n)
{
	long i,ncan;
	char c[MAX];

	if(k==n)
	{
		process_solution(a,k,n);		
	}
	else
	{
		k++;
		con_candidate(a,n,k,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			backtrack(a,k,n);
			if(finished)return;
		}
	}
}

void con_candidate(char a[],long n,long k,char c[],long *ncan)
{
	long sum,i;

	
	*ncan =0;

	sum = num[0];
	for(i=1;i<k;i++)
	{
		if(a[i]=='*')sum = sum * num[i];
		else if(a[i]=='+')sum = sum + num[i];
		else if(a[i]=='-')sum = sum - num[i];
		else sum = sum / num[i];
	}
	
	if(val[k][sum]==true)return;
	
	
	if(sum * num[k]>=-32000 && sum * num[k]<=32000)
	{
		c[(*ncan)++] = '*';
		val[k][sum] = true;
	}	
	if(sum + num[k]>=-32000 && sum + num[k]<=32000)
	{
		c[(*ncan)++] = '+';
		val[k][sum] = true;
	}
	if(sum - num[k]>=-32000 && sum - num[k]<=32000)
	{
		c[(*ncan)++] = '-';
		val[k][sum] = true;
	}
	if(  sum%num[k]==0 &&(sum / num[k]>=-32000 && sum / num[k]<=32000)  )
	{
		c[(*ncan)++] = '/';
		val[k][sum] = true;
	}
}

void process_solution(char a[],long k,long n)
{
	long sum,i;

	sum = num[0];
	for(i=1;i<=k;i++)
	{
		if(a[i]=='*')sum = sum * num[i];
		else if(a[i]=='+')sum = sum + num[i];
		else if(a[i]=='-')sum = sum - num[i];
		else sum = sum / num[i];
	}	
	if(sum!=target)
		return;

	printf("%ld",num[0]);
	for(i=1;i<=k;i++)
	printf("%c%ld",a[i],num[i]);
	printf("=%ld\n",target);
	finished = true;
}