#include<stdio.h>
#include<string.h>
#include<stdlib.h>


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

team teams[32];
int team_number;
char tournament[105];

void initialize();
void read_input();
int binary_search(char a[],int m);
int comp_name(const void* A, const void* B);
int comp_all(const void* A, const void* B);
void output();



void main()
{

	//freopen("10194.in","r",stdin);
	//freopen("10194.out","w",stdout);

	int test,game,i;	

	scanf("%d",&test);

	while(test>0)
	{
		scanf(" %[^\n]",tournament);		
		scanf("%d",&team_number);

		for(i=0;i<team_number;i++)
		scanf(" %[^\n]",teams[i].name);

		//for(i=0;i<team_number;i++)
		//printf("%d = %s\n",i,teams[i].name);

		qsort(teams,team_number,sizeof(team),comp_name);

		//for(i=0;i<team_number;i++)
		//printf("%d = %s\n",i,teams[i].name);

		initialize();		

		scanf("%d",&game);

		for(i=0;i<game;i++)
		read_input();
		
	
		qsort(teams,team_number,sizeof(team),comp_all);

		
		output();


		printf("\n");	
	
		test--;
	}





}


void read_input()
{
	char game[100],temp[35],team1[35],team2[35];
	int len,i,flag=0,n,goal1,goal2,index1,index2;

	scanf(" %[^\n]",game);

	len = strlen(game);

	flag=0;
	n=0;

	for(i=0;i<=len;i++)
	{
		if( (game[i]!='#') && (game[i]!='@') && (game[i]!='\0') )
		 temp[n++]=game[i];
       	else
		{
			temp[n]='\0';
			if(flag==0)
			{
			  strcpy(team1,temp);
			  flag=1;
			}
			else if(flag==1)
			{
			  sscanf(temp,"%d",&goal1);
			  flag=2;
			}
			else if(flag==2)
			{
			  sscanf(temp,"%d",&goal2);
			  flag=3;
			}
			else if(flag==3)
			{
			   strcpy(team2,temp);
			}
			n=0;
		
		}
	
	}

	//printf("%s %d --%s %d\n",team1,goal1,team2,goal2);
	

	///////////////////managing both teams statistics/////////////
	index1 = binary_search(team1,team_number);
	index2 = binary_search(team2,team_number);
	//printf("team1 = %d   team2 = %d\n",index1,index2);

	teams[index1].played +=1; 
	teams[index2].played +=1;

	teams[index1].goal_scored +=goal1;
	teams[index1].goal_against +=goal2;

	teams[index2].goal_scored +=goal2;
	teams[index2].goal_against +=goal1;

	teams[index1].goal_diff = teams[index1].goal_scored  - teams[index1].goal_against;
	teams[index2].goal_diff = teams[index2].goal_scored  - teams[index2].goal_against;

	if( goal1-goal2==0)
	{
		teams[index1].ties +=1; 
		teams[index2].ties +=1;
		teams[index1].point +=1;
		teams[index2].point +=1;
	}
	else if( goal1-goal2>0)
	{
		teams[index1].wins +=1; 
		teams[index2].loss +=1;
		teams[index1].point +=3;
		
	}
	else if( goal1-goal2<0)
	{
		teams[index1].loss +=1; 
		teams[index2].wins +=1;
		teams[index2].point +=3;	
	}

	////////////////////////////////////////////////////////


}//end of read_input() function




// function for binary search from sorted list///////////
int binary_search(char a[],int m)
{
  int beg,mid,end;

  beg=0;
  end=m-1;
  mid=(int)( (beg+end)/2 );

  while(beg<=end && ( strcmp(a,teams[mid].name)!=0) )
  {
	 if( strcmp(a,teams[mid].name)<0 )
	  end=end-1;
	 if( strcmp(a,teams[mid].name)>0 )
	  beg=beg+1;

	 mid=(int)( (beg+end)/2 );
  }

  if( strcmp(a,teams[mid].name)==0 )
	return mid;
  else
	return -1;

}
////////////////end of bsearch///////////////////



int comp_name(const void* A, const void* B)
{
	team *a=(team*)A;
	team *b=(team*)B;
 
	return strcmp(a->name,b->name);
}


int comp_all(const void* A, const void* B)
{
	team *a=(team*)A;
	team *b=(team*)B;
 
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

	
	return strcmp(a->name,b->name);
}


//initializing all teams//////////
void initialize()
{		int i;
	
		for(i=0;i<team_number;i++)
		{	teams[i].goal_against = 0;
			teams[i].goal_diff = 0;
			teams[i].goal_scored = 0;
			teams[i].loss =0;
			teams[i].played = 0;
			teams[i].point = 0;
			teams[i].ties = 0;
			teams[i].wins = 0;
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