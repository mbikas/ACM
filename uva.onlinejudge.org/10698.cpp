#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 100000

typedef struct{
	char name[30];
	long goal_scored;
	long goal_suffered;
	long goal_diff;
	long points;
	double percentage;
	long played;
}team;
team teams[sz];
long m,n;
long search_name(char names[]);
void print_output();
int comp(const void* A, const void* B);

void main()
{

	//freopen("10698.in","r",stdin);
	//freopen("out1.txt","w",stdout);


	char str[10000],name1[30],name2[30];
	long i,p1,p2,index1,index2,f=0;
	double x,y,percent;

	while(scanf("%ld %ld",&m,&n)==2 && (m!=0 || n!=0))
	{

		//if(f==1)printf("\n");
		//else f=1;
		for(i=0;i<m;i++)
		{	scanf(" %[^\n]",teams[i].name);
		    teams[i].points=0;
			teams[i].goal_scored=0;
			teams[i].goal_suffered=0;
			teams[i].played = 0;
		}
		

		for(i=0;i<n;i++)
		{
			scanf(" %[^\n]",str);
			sscanf(str,"%s %ld - %ld %s",name1,&p1,&p2,name2);
			//printf("%s %ld - %ld %s\n",name1,p1,p2,name2);

			index1 = search_name(name1);
			teams[index1].goal_scored   += p1;
			teams[index1].goal_suffered += p2;
			teams[index1].played++;

			index2 = search_name(name2);
			teams[index2].goal_scored   += p2;
			teams[index2].goal_suffered += p1;
			teams[index2].played++;
			

			if(p1>p2)
				teams[index1].points += 3;				
			else if(p1==p2)
			{
				teams[index1].points += 1;
				teams[index2].points += 1;
			}
			else			
				teams[index2].points += 3;	
		
		}

		for(i=0;i<m;i++)
		{
			teams[i].goal_diff = teams[i].goal_scored - teams[i].goal_suffered;
			if(teams[i].played == 0)teams[i].percentage = -1;
			else
			{
				x = (double)(teams[i].played *3);
				y = (double)teams[i].points;
				percent =  y/x*100;

				teams[i].percentage = percent;
				//printf("%lf\n",percent);			
			}
		}
		qsort(teams,m,sizeof(team),comp);
		print_output();
		printf("\n");


	}
}


long search_name(char names[])
{
	long i;
	for(i=0;i<m;i++)
	{
		if(strcmp(teams[i].name,names)==0)
			return i;
	}
	return -1;
}



int comp(const void* A, const void* B)
{
	long i,len;
	char temp1[30],temp2[30];
	team *a=(team*)A;
	team *b=(team*)B;
 
	if(a->points > b->points) return(-1);
	if(a->points < b->points) return(1);

	if(a->goal_diff > b->goal_diff) return(-1);
	if(a->goal_diff < b->goal_diff) return(1);

	if(a->goal_scored > b->goal_scored) return(-1);
	if(a->goal_scored < b->goal_scored) return(1);

	
	strcpy(temp1,a->name);
	len = strlen(a->name);
	for(i=0;i<len;i++)
		temp1[i] = tolower(temp1[i]);
	temp1[i]='\0';

	strcpy(temp2,b->name);
	len = strlen(b->name);
	for(i=0;i<len;i++)
		temp2[i] = tolower(temp2[i]);
	temp2[i]='\0';

	return strcmp(temp1,temp2);		
	
}

void print_output()
{
	long i,pos=1,f=0;

	for(i=0;i<m;i++)
	{
		if(i!=0 && teams[i].points==teams[i-1].points && teams[i].goal_diff == teams[i-1].goal_diff && teams[i].goal_scored==teams[i-1].goal_scored)
		{ 
			if(teams[i].percentage == -1)//percentage = N/A
				printf("%19s%4ld%4ld%4ld%4ld%4ld%s\n",teams[i].name,teams[i].points,teams[i].played,teams[i].goal_scored,teams[i].goal_suffered,teams[i].goal_diff,"    N/A");
			
			else
				printf("%19s%4ld%4ld%4ld%4ld%4ld%7.2lf\n",teams[i].name,teams[i].points,teams[i].played,teams[i].goal_scored,teams[i].goal_suffered,teams[i].goal_diff,teams[i].percentage);
			
		}
		else
		{ 
			if(teams[i].percentage == -1)//percentage = N/A
				printf("%2ld.%16s%4ld%4ld%4ld%4ld%4ld%s\n",pos,teams[i].name,teams[i].points,teams[i].played,teams[i].goal_scored,teams[i].goal_suffered,teams[i].goal_diff,"    N/A");
			else
				printf("%2ld.%16s%4ld%4ld%4ld%4ld%4ld%7.2lf\n",pos,teams[i].name,teams[i].points,teams[i].played,teams[i].goal_scored,teams[i].goal_suffered,teams[i].goal_diff,teams[i].percentage);
				  
		}
		pos++;
		//printf("%s %ld %ld %ld\n",teams[i].name,teams[i].points,teams[i].goal_diff,teams[i].goal_scored);
	
	}


}