#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>

int used[10000],a[10000],N=0,k,num[10000]; 
bool finished;
int is_solution(int n)
{
	return n==k+1;
}

void process_solution(int n)
{
	int i,sum=num[a[1]];
	for (i=2;i<=k;i++)
	{
		sum=sum+num[a[i]];
	}

	if(sum%k==0)
	{
		printf("Yes\n");
		printf("%d",num[a[1]]); 
		for (i=2;i<=k;i++)
		{
			printf(" %d",num[a[i]]);
		}
		printf("\n");
		finished=true;
	}
	
	
}

void backtrack(int k) 
{ 
	int i; 
	if(is_solution(k))
		process_solution(k);
	else 
	{ 
		for (i=1;i<=N;i++) 
		{ 
			if (used[i]==0 && i>a[k-1]) 
			{ 
				used[i]=1; 
				a[k]=i; 
				backtrack(k+1); 
				if(finished)return;
				a[k]=0; 
				used[i]=0; 
			} 
		} 
	} 
} 

int main() 
{ 
	//freopen("in.txt","rt",stdin);
	int n,i; 
	
	while(scanf("%d",&n)==1 && n)
	{ 
		N=2*n-1;		
		for(i=0;i<N;i++)
		{ 
			scanf("%d",&num[i+1]);
			used[i]=0; 
		} 
		used[N]=0; 
		k=n;
		a[0]=-1; 
		finished=false;
		backtrack (1); 	
		if(!finished)
			printf("No\n");
	}
	return 0;
}