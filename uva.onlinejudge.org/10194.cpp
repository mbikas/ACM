#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define sz 105


typedef struct{

	char name[35];
	int point;
	int played;
    int wins;
	int ties;
	int loss;
	int goal_diff;
	int goal_scored;
	int goal_against;
}team;

team teams[35];
int team_number;
char tournament[105];

void initialize();
void read_input(char team1[],char team2[],int goal1,int goal2);
int comp_all(const void* A, const void* B);
void output();




void main()
{

	//freopen("10194.in","r",stdin);
	//freopen("10194.out","w",stdout);

	int test,i,m;
	char a[35],b[35];
	int na,nb;

	scanf("%d",&test);

	while(test>0)
	{
		scanf(" %[^\n]",tournament);		
		
		scanf("%d",&team_number);

		for(i=0;i<team_number;i++)
		scanf(" %[^\n]",teams[i].name);

		//for(i=0;i<team_number;i++)
		//printf("%d = %s\n",i,teams[i].name);

		
		initialize();		

		scanf("%d",&m);

		for(i=0;i<m;i++)
		{ 
			scanf(" %[^#]#%d@%d#%[^\n]",a,&na,&nb,b); 

			//printf("%s %s\n",a,b);		
			read_input(a,b,na,nb);
		}

	
		for(i=0;i<team_number;i++)
		teams[i].goal_diff = teams[i].goal_scored - teams[i].goal_against;
		
		
		//output();
	
		qsort(teams,team_number,sizeof(team),comp_all);

		
		output();

		//////////////////
		if(test!=1)
		//////////////////////

		printf("\n");
		
	
		test--;
	}





}






void read_input(char team1[],char team2[],int goal1,int goal2)
{
	
	int i,index1,index2,x;	
	

	///////////////////managing both teams statistics/////////////

	//printf("%s   %s---\n",team1,team2);

	for(i=0;i<team_number;i++)
	{	
		
	     if( strcmp(team1,teams[i].name) ==0 )
			 index1 = i;

		else if( strcmp(team2,teams[i].name) ==0 )
			 index2 = i;

	}

	

	//printf("team1 = %d   team2 = %d\n",index1,index2);

	

	teams[index1].played +=1; 
	teams[index2].played +=1;

	teams[index1].goal_scored +=goal1;
	teams[index1].goal_against +=goal2;

	teams[index2].goal_scored +=goal2;
	teams[index2].goal_against +=goal1;

	x = goal1 - goal2;

	if( x==0)
	{
		teams[index1].ties +=1; 
		teams[index2].ties +=1;
		teams[index1].point +=1;
		teams[index2].point +=1;
	}
	else if( x>0)
	{
		teams[index1].wins +=1; 
		teams[index2].loss +=1;
		teams[index1].point +=3;
		
	}
	else
	{
		teams[index1].loss +=1; 
		teams[index2].wins +=1;
		teams[index2].point +=3;	
	}

	////////////////////////////////////////////////////////

}//end of read_input() function

int comp_all(const void* A, const void* B)
{
	team *a=(team*)A;
	team *b=(team*)B;

	char temp1[35],temp2[35];
	int i,len;

	//Most points earned. 
	//Most wins. 
	//Most goal difference (i.e. goals scored - goals against) 
	//Most goals scored. 
	//Less games played. 
	//Lexicographic order
 
	if(a->point > b->point) return(-1);
	if(a->point < b->point) return(1);

	if(a->wins > b->wins) return(-1);
	if(a->wins < b->wins) return(1);

	if(a->goal_diff > b->goal_diff) return(-1);
	if(a->goal_diff < b->goal_diff) return(1);

	if(a->goal_scored > b->goal_scored) return(-1);
	if(a->goal_scored < b->goal_scored) return(1);

	if(a->played < b->played) return(-1);
	if(a->played > b->played) return(1);
	
	strcpy(temp1,a->name);
	len = strlen(temp1);
	for(i=0;i<len;i++)
	temp1[i] = toupper(temp1[i]);	
	

	strcpy(temp2,b->name);
	len = strlen(temp2);
	for(i=0;i<len;i++)
	temp2[i] = toupper(temp2[i]);

	//printf("%s %s  =  %d\n",temp1,temp2,strcmp(temp1,temp2));
	
	return strcmp(temp1,temp2);	
	
}


//initializing all teams//////////
void initialize()
{		int i;
	
		for(i=0;i<team_number;i++)
		{	teams[i].goal_against = 0;
			teams[i].goal_diff = 0;
			teams[i].goal_scored = 0;
			teams[i].played = 0;
			teams[i].point = 0;
			teams[i].wins = 0;
			teams[i].ties=0;
			teams[i].loss=0;
		}
	
}


void output()
{

	int i,rank=1;

	printf("%s\n",tournament);


	for(i=0;i<team_number;i++)
	{	printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",rank,teams[i].name,teams[i].point,teams[i].played,teams[i].wins,teams[i].ties,teams[i].loss,teams[i].goal_diff,teams[i].goal_scored,teams[i].goal_against);
		rank++;
	}
}

