#include<stdio.h>
#include<math.h>

#define NMAX 15
int a[10];
long row,col,count;
//bool finished=false;

void costruct_candidate(int a[],int k,int n,int c[],int *ncandidate);
void backtrack(int k);
bool is_solution(int a[],int k,int n);
void process_solution(int a[],int k,int n);

void main()
{
	long f,test;

	scanf("%ld",&test);

	while(test--)
	{
		if(f==1)printf("\n");
		else f=1;

		scanf("%ld %ld",&row,&col);

		count=0;
`		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		backtrack(0);	
	
	
	}

}

void costruct_candidate(int a[],int k,int n,int c[],int *ncandidate)
{
	int i,j;
	bool legal;

	if((k+1)==col)
	{
		legal=true;
		for(j=0;j<k;j++)
		{
			if(abs(k-j)==abs(row-1-a[j]))
			{
				legal=false;
				break;
			}
			if((row-1)==a[j])
			{
				legal=false;
				break;
			}
		}
		if(legal)
			c[(*ncandidate)++]=row-1;
		return;
	}

	for(i=0;i<n;i++)
	{
		legal=true;
		for(j=0;j<k;j++)
		{
			if(abs(k-j)==abs(i-a[j]))
			{
				legal=false;
				break;
			}
			if(i==a[j])
			{
				legal=false;
				break;
			}
		}
		if(legal)
		{	c[(*ncandidate)++]=i;
		//printf("i = %ld k = %ld\n",i,k);
		}
	}







}

void backtrack(int k)
{

	int i,c[NMAX],ncandidate=0;

	if(is_solution(a,k,8))
	{
		process_solution(a,k,8);
		return;
	}

	costruct_candidate(a,k,8,c,&ncandidate);

	for(i=0;i< ncandidate;i++)
	{
		a[k]=c[i];
		backtrack(k+1);	
		//if(finished)return;
	}
}


bool is_solution(int a[],int k,int n)
{
	return (k==n);
}
void process_solution(int a[],int k,int n)
{
	int i;

	printf("%2ld     ",++count);

	for(i=0;i<k;i++)
		printf("%2d",a[i]+1);
	printf("\n");
}

