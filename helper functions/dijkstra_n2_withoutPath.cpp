#include<stdio.h>
#include<string.h>
#define sz 105
#define NONE -1
int weight[sz][sz],length[105],count[sz];

void dijkstra(int start, int node_num, int length[], int weight[sz][sz])
{
   int i, j, min;

   //Initial single source state.
   for(i = 0; i < node_num; i++)
   {
      length[i] = NONE;
      count[i] = 0;
   }   

   for(i = 0, length[start] = 0; i < node_num; i++)
   {
      //Extract min. Complexity: O(n).
      for(j = 0, min = NONE; j < node_num; j++)
      {
         if (length[j] != NONE && count[j] == 0 && (min == NONE || length[j] < length[min])) min = j;
      }

      //Relax the adjacent node of the present minimal weighted node 'min'.
      for(j = 0, count[min] = 1; j < node_num; j++)
      {
         if (weight[min][j] != NONE && (length[j] == NONE || length[j] > (length[min] + weight[min][j]))) length[j] = length[min] + weight[min][j];
      }
   }

	return;
}


int main()
{
	int test,cases=1,i,source,des,start,end,vertex,edges,cost;

	scanf("%d",&test);

	while(test--)
	{
		scanf("%d %d %d %d",&vertex,&edges,&start,&end);
		memset(weight,-1,sizeof(weight));
		for(i=0;i<edges;i++)
		{
			scanf("%d %d %d",&source,&des,&cost);
			weight[source][des]=cost;
			weight[des][source]=cost;
		}
		dijkstra(start,vertex,length,weight);

	
        if(length[end]==-1)
			printf("Case #%d: unreachable\n",cases++);
		else
			printf("Case #%d: %d\n",cases++,length[end]);
	}


	

	return 0;
}