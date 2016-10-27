/*Topological Sort by chormen*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define sz 105
#define NULL 0
#define INF 10000000L

struct node{
	int vert;
	node *forw;
};

int ans[sz],len;
node *strt, *ptr, *last;

int vert, edges, ntime, Flag;

int start[sz], finish[sz], par[sz];
int mat[sz][sz];               
char color[sz];

void DFS_Visit(int und)
{
     int index, vnd, key;

	color[und] = 'g';

	start[und] = ntime = ntime + 1;

	for(index = 1; index <= mat[und][0]; index++)
	{
		vnd = mat[und][index];

		if(color[vnd] == 'w')
		{
			par[vnd] = und;

			DFS_Visit(vnd);
		}

		if(color[vnd] == 'g')
          	Flag = 0;
	}

	color[und] = 'b';

	finish[und] = ntime = ntime + 1;

	ptr->vert = und;
	ptr->forw = new(node);
	ptr = ptr->forw;
}


void DFS(void)
{
     int und;

	for(und = 1; und <= vert; und++)
	{
		color[und] = 'w';
		par[und] = NULL; 
	}

	ntime = 0;

	for(und = 1; und <= vert; und++)
	{
		if(color[und] == 'w')
          	DFS_Visit(und);
	}
}

void PrintFunction(node *ptr)
{
	if(ptr->forw == NULL)
		return;

	PrintFunction(ptr->forw);

	ans[len++]=ptr->vert;
	//printf("%d\t", ptr->vert);

	return;
}

void TopologicalSort(void)
{
	strt->forw = new(node);
	ptr = strt->forw;

	DFS();

	if(!Flag)
	{
		//printf("Topologic Sort is not possible\n");
        return;
	}

	ptr->vert = -INF;
	ptr->forw = NULL;

	ptr = strt->forw;

	PrintFunction(strt->forw);
	//printf("\n\n");

	return;
}

int main()
{
	int ind, jnd, knd, index,i;

	strt = new(node);
	strt->vert = 0;

	while(scanf("%d %d", &vert, &edges)==2)
     {
		if(vert==0 && edges==0)break;

        Flag = 1;
		strt->vert = 0;
		
		for(i=0;i<=vert;i++)mat[i][0]=0;
				

		memset(mat, 0, sizeof(mat));

		len=0;
		for(knd = 1; knd <= edges; knd++)
		{
			scanf("%d %d", &ind, &jnd);

			index = mat[ind][0]+= 1;
			mat[ind][index] = jnd; 
		}

		TopologicalSort();

		printf("%d",ans[0]);
		for(i=1;i<len;i++)printf(" %d",ans[i]);
		printf("\n");
     
     }
	return 0;
}