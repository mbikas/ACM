//kruskal                           
//Solved by bikas Cse2/2

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct{
  char c1;
  char c2;
  int weight;
  int p1;
  int flag;
 
 }EDGE;

EDGE edge[SIZE];

int cycle_or_not(int indicate[],int taken,char node1,char node2);
int comp(void const *A, void const *B);

void main()
{
  int total,i;
  int indicate[SIZE],taken,cost=0;
  

  ///taking inputs///////////////////////////////////////////////
  printf("How many edges: ");
  scanf("%d",&total);

  printf("Now enter the edge and their weight [ node1 node2 weight (like a b 3) ]\n");
  for(i=0;i<total;i++)
  { scanf(" %c %c %d",&edge[i].c1,&edge[i].c2,&edge[i].weight);
	//adjacent[adja_size++]=i;
	edge[i].flag=0;
  }
  ////////////////////////////////////////////////////////////////

  printf("\nSelected Edgeds are listed below:\n");

  ///sorting the possible edges based on weight/////
  qsort(edge,total,sizeof(EDGE),comp);
  /////////////////////////////////////////////////
  char c1,c2;
  int cycle;
  taken=0;



  for(i=0;i<total;i++)
	{
	  c1=edge[i].c1;
	  c2=edge[i].c2;

	  ////////////////checking cycle or not/////////////////////
	  cycle=cycle_or_not(indicate,taken,c1,c2);
	  /////////////////////////////////////////////////////////

	  if(cycle==0)
	  {  cost=cost + edge[i].weight ;
		 printf("%c %c %d\n",edge[i].c1,edge[i].c2,edge[i].weight) ;
		 indicate[taken++]=i;
	  }
	}

  printf("\nTotal Cost=%d",cost);


}


  int cycle_or_not(int indicate[],int taken,char node1,char node2)
	{
	  char queue[SIZE];
	  int rear,front,cycle,j;

	  front=0;
	  rear=0;
	  cycle=0;

	  for(j=0;j<taken;j++)
	  edge[indicate[j]].p1=0;

	  queue[rear++]=node1;
	  front=rear-1;

	  while(front!=rear )
	  {
		 for(j=0;j<taken;j++)
		 {
		  if( queue[front]==edge[indicate[j]].c1 && edge[indicate[j]].p1!=1 )
			{
			  queue[rear++]= edge[indicate[j]].c2;
			  if(queue[rear-1]==node2)
			  { cycle=1;
				edge[indicate[j]].flag=-1;
				return cycle;
			  }
			  edge[indicate[j]].p1=1;
			}
		  else if(queue[front]==edge[indicate[j]].c2 && edge[indicate[j]].p1!=1)
			{
			  queue[rear++]= edge[indicate[j]].c1;
			  if(queue[rear-1]==node2)
			  {cycle=1;
				edge[indicate[j]].flag=-1;
				return cycle;
			  }
			  edge[indicate[j]].p1=1;
			}

		 }//end of inner for

		 front++;

	  } //end of while

	 cycle=0;
	 return cycle;
  }


int comp(void const *A, void const *B)
{

	EDGE *a = (EDGE*)A;
	EDGE *b = (EDGE*)B;

	
	if(a->weight>b->weight)
		return 1;
	if(a->weight<b->weight)
		return -1;
	return 0;
}