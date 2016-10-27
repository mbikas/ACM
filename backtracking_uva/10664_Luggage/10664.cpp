#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 1000
#define MAX 22


int comp(void const *A, void const *B)
{
	long *a = (long*)A;
	long *b = (long*)B;
	return (*b-*a);
}
int num[25];
bool possible=false,finished = false;
int weight = 0;

void backtrack(int a[],int k,int n,int sum);
void con_candidate(int a[],int k,int n,int sum,int c[],int *ncan);


void main()
{

	char str[sz],*p;
	int test,n,sum,a[MAX];

	scanf("%d",&test);

	while(test--)
	{
			scanf(" %[^\n]",str);

			weight = 0;
			sum=0;
			n=0;
			p = strtok(str," ");
			while(p)
			{
					//printf("%s ",p);
					sscanf(p,"%d",&num[n]);
					p=strtok(NULL," ");
					
					weight += num[n];
					n++;
			}
			//printf("weight = %d\n",weight);

			if(weight%2 != 0)
			{	
				printf("NO\n");
				continue;
			}

			

			qsort(num,n,sizeof(num[0]),comp);

			//for(int j=0;j<n;j++)printf("%d ",num[j]);
			//printf("\n");

			possible = false;
			finished = false;
			memset(a,0,sizeof(a));
			weight = weight/2;
			backtrack(a,0,n,sum);
			if(!finished)
				printf("NO\n");
	
	}
}

void backtrack(int a[],int k,int n,int sum)
{
	int i,c[MAX],ncan,sum1;

	if(k>n)
		return;

    if(sum==weight)
	{
		printf("YES\n");
		//for(i=1;i<=k;i++)printf("%d ",num[a[i]]);
		//printf("\n");
		finished = true;
		return;	
	}
	else
	{
		k++;
		con_candidate(a,k,n,sum,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			sum1 = sum + num[a[k]];
			backtrack(a,k,n,sum1);
			if(finished)return;
		}
	}
}

void con_candidate(int a[],int k,int n,int sum,int c[],int *ncan)
{
	bool choice[MAX];
	int i;

	*ncan = 0;

	if(sum>weight)return;

	memset(choice,true,sizeof(choice));

	for(i=1;i<k;i++)
		choice[a[i]] = false;

	for(i=0;i<n;i++)
	{
		if(choice[i])
			c[(*ncan)++] = i;	
	}

}
