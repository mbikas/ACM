#include<stdio.h>
#include<math.h>
#define MAX 10
#define large 5000.00

typedef struct{
	double x;
	double y;
}POINT;
POINT point[10];
double dis[MAX][MAX],min;
int ans[MAX];

void backtrack(int a[],int k,int n);
void con_candidate(int a[],int k,int n,int c[],int *ncandidates);
void process_solution(int a[],int k,int n);
double get_distance(double x1,double y1,double x2,double y2)
{
	return ( sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );
}

void main()
{
	//freopen("129.in","r",stdin);
	//freopen("out1.txt","w",stdout);

	int i,j,n,a[MAX];
	long cases=1;
	

	while(scanf("%d",&n)==1 && n!=0)
	{

		for(i=0;i<n;i++)
			scanf("%lf %lf",&point[i].x,&point[i].y);

		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				dis[i][j]=large;

		for(i=0;i<n-1;i++)
		{	for(j=i+1;j<n;j++)
			{	dis[i][j] = dis[j][i] = (double)(16 + get_distance(point[i].x,point[i].y,point[j].x,point[j].y) );		
				//printf("%lf\n",dis[i][j]);
			}
		}
		
		
		min = large;
		for(i=0;i<=n;i++)a[i]=i;
		backtrack(a,0,n);

		printf("**********************************************************\n");
		printf("Network #%ld\n",cases++);

		for(i=1;i<n;i++)
		printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",point[ans[i]].x,point[ans[i]].y,point[ans[i+1]].x,point[ans[i+1]].y,dis[ans[i]][ans[i+1]]);

		printf("Number of feet of cable required is %.2lf.\n",min);

		
	}
}

void backtrack(int a[],int k,int n)
{
	int i,c[MAX],ncandidates;

	if(k==n)
	{
		process_solution(a,k,n);	
	}
	else
	{
		k=k+1;
		con_candidate(a,k,n,c,&ncandidates);
		for(i=0;i<ncandidates;i++)
		{
			a[k]  = c[i];
			backtrack(a,k,n);			
		}
	}
}

void con_candidate(int a[],int k,int n,int c[],int *ncandidates)
{

	int i;
	bool taken[MAX];

	*ncandidates = 0;

	/*
	if(k==1)
	{
		c[(*ncandidates)++]=0;
		return;
	}
	*/

	for(i=0;i<n;i++)taken[i]=false;
	for(i=1;i<k;i++)taken[a[i]]=true;

	for(i=0;i<n;i++)
	{
		if(taken[i]==false)
		{
			c[(*ncandidates)++]=i;		
		}	
	}
}

void process_solution(int a[],int k,int n)
{
	double sum;
	int i;

	sum = 0.0;
	for(i=2;i<=k;i++)
		sum += dis[a[i-1]][a[i]];

	if(sum<min)
	{
		min = sum;
		for(i=1;i<=k;i++)ans[i] = a[i];
	}
}