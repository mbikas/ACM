#include<stdio.h>
#include<string.h>

#define sz 11
int path[6][6];
void get_link();
void backtrack(int a[],int k);
void construct_candidate(int a[],int k,int c[],int *ncandidates);
//int total = 0;

void main()
{
	int a[sz];

	memset(a,0,sizeof(a));
	get_link();
	backtrack(a,0);

	//printf("%d\n",total);

}

void get_link()
{
	memset(path,0,sizeof(path));
	path[1][2]=1;	path[2][1]=1;
	path[1][5]=1;	path[5][1]=1;
	path[1][3]=1;	path[3][1]=1;
	path[2][3]=1;	path[3][2]=1;
	path[2][5]=1;	path[5][2]=1;
	path[3][4]=1;	path[4][3]=1;
	path[3][5]=1;	path[5][3]=1;
	path[4][5]=1;	path[5][4]=1;
}

void backtrack(int a[],int k)
{
	int c[sz],i,ncandidates;
	if(k==9)
	{
		for(i=1;i<=9;i++)
		printf("%d",a[i]);
		printf("\n");
		//total++;
	}
	else
	{
		k = k+1;
		construct_candidate(a,k,c,&ncandidates);
		for(i=0;i<ncandidates;i++)
		{  a[k]=c[i];
		   backtrack(a,k);
		}
	}
}


void construct_candidate(int a[],int k,int c[],int *ncandidates)
{
	int i;
	bool flag[6][6];

	*ncandidates = 0;	
	if(k==1)
	{	c[(*ncandidates)++] = 1;
	    return;
	}

	memset(flag,false,sizeof(flag));

	for(i=2;i<k;i++)
	{
		flag[a[i-1]][a[i]] = true;
		flag[a[i]][a[i-1]] = true;	
	}

	for(i=1;i<=5;i++)
	{
		if(path[a[k-1]][i]==1)
		{
			if(flag[a[k-1]][i]==false)
			 c[(*ncandidates)++] = i;		
		}
	
	}


}