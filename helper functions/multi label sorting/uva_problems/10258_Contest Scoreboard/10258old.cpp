#include<stdio.h>
#include<stdlib.h>


typedef struct{

	int name;
	long penelty;
	int prob_no[10];
	char status[10];
	int total;
	
}contest;

contest contests[105];
int max;
int comp(const void* A, const void* B);


void read_input()
{
	
	int name,problem,time,i,j;
	char status;

	//contestant problem time L 

	for(i=0;i<102;i++)
	{
	  contests[i].penelty = 0;
	  contests[i].name =0;
	  contests[i].total=0;
	  //contests[i].status = 'I';
	  for(j=0;j<10;j++)
		  contests[i].prob_no[j] = 0;
	  for(j=0;j<10;j++)
		  contests[i].status[j] = 'I';


	}
	i=0;
	max=0;

	while( scanf(" %d %d %d %c",&name,&problem,&time,&status)==4)
	{
		    if(name>max)max = name; 
		    

			if(status=='I')
			{
				if(contests[name].status[problem]!='C')
					contests[name].prob_no[problem] += 20;
				contests[name].name = name;

			}
			else if(status=='C')
			{
				if(contests[name].status[problem] !='C')
				{
					contests[name].penelty += contests[name].prob_no[problem] + time;
					contests[name].total++;
				}
				contests[name].status[problem] = 'C';
				contests[name].name = name;
			
			}
			else
			{
				//contests[name].status = 'P';
				contests[name].name = name;
			
			}

			/////////////
			i++;
			//printf("%d %d %ld\n",contests[name].name,contests[name].total,contests[name].penelty);
			if(i==5)break;
			//////////////

	}
	

}


void main()
{

	int i;
	read_input();

	for(i=1;i<=max;i++)
	{
	
		if(contests[i].name!=0)
			printf("%d %d %d\n",contests[i].name,contests[i].total,contests[i].penelty);
	}

	qsort(contests,max+1,sizeof(contest),comp);


	for(i=0;i<=max;i++)
	{
	
		if(contests[i].name!=0)
			printf("%d %d %d\n",contests[i].name,contests[i].total,contests[i].penelty);
	}









}

int comp(const void* A, const void* B)
{
	contest *a=(contest*)A;
	contest *b=(contest*)B;

	if(a->total > b->total) return(-1);
	if(a->total < b->total) return(1);

	if(a->penelty > b->penelty) return(1);
	if(a->penelty < b->penelty) return(-1);

	

	return 0;


}