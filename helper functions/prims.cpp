							//Solved by bikas Cse2/2
#include<stdio.h>
#define SIZE 20

typedef struct{
 char c1;
 char c2;
 int weight;
 int p1;
 int flag;
 int taken;
}NODE;

NODE node[SIZE];

int cycle_or_not(int indicate[],int index,char node1,char node2);

void main()
{
 int n,i,j,max=1000,min;

 char node1,node2;
 int indicate[SIZE],index,cost=0;

 int adjacent[SIZE],adja_size;



 ///taking inputs///////////////////////////////////////////////
	printf("How many edges: ");
	scanf("%d",&n);

	printf("Now enter the edge and their weight [ node1 node2 weight (like a b 3) ]\n");
	for(i=0;i<n;i++)
	 {
		scanf(" %c %c %d",&node[i].c1,&node[i].c2,&node[i].weight);
		 if(node[i].weight<max)
		  { min=i;
			 max=node[i].weight;
		  }
		node[i].flag=0;
      node[i].taken=0;
	 }
	////////////////////////////////////////////////////////////////

	index=0;
	printf("\nSelected Edgeds are listed below:\n");
	printf("%c %c %d\n",node[min].c1,node[min].c2,node[min].weight) ;

	adja_size=0;
	bikas:
	indicate[index++]=min;
	cost=cost+node[min].weight;

	node1=node[min].c1;
	node2=node[min].c2;
	node[min].flag=1;
	node[min].taken=1;

	///////listing the possible edges///////////////
	for(i=0;i<n;i++)
	 { if( (node[i].c1== node1 || node[i].c2==node1 ||node[i].c1== node2 || node[i].c2==node2) && node[i].flag!=-1 && node[i].flag!=1 && node[i].taken!=1)
		 {
			adjacent[adja_size]=i;
			node[adjacent[adja_size]].taken=1;
			adja_size++;
		 }
	 }
	/////////////////////////////////////////////////

	///sorting the possible edges based on weight/////
	int temp;
	for(i=1;i<adja_size;i++)
	 { for(j=0;j<adja_size-i;j++)
		 if(node[adjacent[j]].weight>node[adjacent[j+1]].weight)
		 {
			temp= adjacent[j];
			adjacent[j]= adjacent[j+1];
			adjacent[j+1]=temp;

		 }
	 }
	/////////////////////////////////////////////////
	char c1,c2;
	int cycle;
	////////////////checking cycle/////////////////////

	for(i=0;i<adja_size;i++)
	{

	  c1=node[adjacent[i]].c1;
	  c2=node[adjacent[i]].c2;
	  cycle=cycle_or_not(indicate,index,c1,c2);

	  if(cycle==0)
	  {
		min=adjacent[i];
		printf("%c %c %d\n",node[min].c1,node[min].c2,node[min].weight) ;
		goto bikas;
	  }

	}

   //////////////////////////////////////////////////
	printf("\nTotal Cost=%d",cost);


}


  int cycle_or_not(int indicate[],int index,char node1,char node2)
	{
	  char queue[SIZE];
	  int rear,front,cycle,j;

	  front=0;
	  rear=0;
	  cycle=0;

	  for(j=0;j<index;j++)
	  node[indicate[j]].p1=0;

	  queue[rear++]=node1;
	  front=rear-1;

	  while(front!=rear )
	  {
		 for(j=0;j<index;j++)
		 {
		  if( queue[front]==node[indicate[j]].c1 && node[indicate[j]].p1!=1 )
			{
			  queue[rear++]= node[indicate[j]].c2;
			  if(queue[rear-1]==node2)
			  {cycle=1;
				node[indicate[j]].flag=-1;
				return cycle;
			  }
			  node[indicate[j]].p1=1;
			}
		  else if(queue[front]==node[indicate[j]].c2 && node[indicate[j]].p1!=1)
			{
			  queue[rear++]= node[indicate[j]].c1;
			  if(queue[rear-1]==node2)
			  {cycle=1;
				node[indicate[j]].flag=-1;
				return cycle;
			  }
			  node[indicate[j]].p1=1;
			}

		 }//end of inner for

		 front++;

	  } //end of while

	 cycle=0;
	 return cycle;
  }

