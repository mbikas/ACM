#include<stdio.h>
#include<math.h>
#define large 10000.00
//#define large 100000.00lf
#define MAX 15
double get_distance(double x1,double y1,double x2,double y2)
{
	return (  sqrt( ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)))  );
}

typedef struct{
	double x,y;
}POINT;
POINT point[10];

double dis[MAX][MAX],min=0;
int ans[MAX];

is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
void backtrack(int a[], int k,int n);





void main()
{
	int N,i,j;
	int a[MAX];
	long cases=1;

	while(scanf("%d",&N)==1 && N!=0)
	{
		for(i=0;i<N;i++)
			scanf("%lf %lf",&point[i].x ,&point[i].y);

		for(i=0;i<=N;i++)
			for(j=i;j<=N;j++)
				dis[i][j] = large;

		for(i=0;i<N-1;i++)
		{	for(j=i+1;j<N;j++)
			{
				dis[i][j] = dis[j][i] = 16 + get_distance(point[i].x,point[i].y,point[j].x,point[j].y);
				//printf("%lf\n",dis[i][j]);
			}		
		}

		min = large;
		for(i=0;i<=N;i++)
			a[i]=0;
		backtrack(a,0,N);

		printf("**********************************************************\n");
		printf("Network #%ld\n",cases++);

		for(i=2;i<=N;i++)
		{
			if(ans[i-1]<ans[i])
			printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",point[ans[i-1]].x,point[ans[i-1]].y,point[ans[i]].x,point[ans[i]].y,dis[ans[i-1]][ans[i]]);
			else
			printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",point[ans[i-1]].x,point[ans[i-1]].y,point[ans[i]].x,point[ans[i]].y,dis[ans[i]][ans[i-1]]);
		}
		printf("Number of feet of cable required is %.2lf.\n",min);
		
	}
}



void process_solution(int a[], int k)
{
        int i;    
		double sum1=0;
		
		for (i=2;i<=k;i++)
		{	
			if(a[i-1]<a[i])
			    sum1 += dis[a[i-1]][a[i]];
			else
				sum1 += dis[a[i]][a[i-1]];
		}


		//printf("sum1 = %lf\n",sum1);

		if(sum1<min)
		{	min = sum1;
		    for(i=1;i<=k;i++)
				ans[i] = a[i];
		}
				
        //for (i=1;i<=k;i++) 
		//printf("%d ",a[i]);		
		//    printf("\n");
		
}

is_a_solution(int a[], int k, int n)
{
        return (k == n);
}

void backtrack(int a[], int k,int n)
{
        int c[MAX];        
        int ncandidates;             
        int i;                       

        if (is_a_solution(a,k,n))
                process_solution(a,k);

        else {
                k = k+1;				
                construct_candidates(a,k,n,c,&ncandidates);
                
				for (i=0; i<ncandidates; i++) 
				{
                        a[k] = c[i];
                        backtrack(a,k,n);
                        //if (finished) return;   
                }
        }
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	int i;
	bool taken[MAX];

	*ncandidates =0;
	if(k==1)
	{
		c[(*ncandidates)++] = 0;
		return;	
	}
	//if(k==n)
	//{
	
		//sum1 = dis[0][a[1]];
		//for(i=2;i<k;i++)
		//	sum1 += dis[a[i-1]][a[i]];
	//}

	for(i=0;i<=n;i++)
		taken[i]=false;
	for(i=0;i<k;i++)
	  taken[a[i]] = true;

	for(i=0;i<n;i++)
	{
		if(taken[i]==false)
		{	
			
			c[(*ncandidates)++] = i;
		}
	}

}
