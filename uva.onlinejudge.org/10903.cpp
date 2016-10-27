#include<stdio.h>
#include<string.h>

typedef struct{
	long win;
	int played;
}player;
player players[105];

void main()
{
	//freopen("10903.in","r",stdin);
	//freopen("10903.out","w",stdout);


	long n,game,i,p1,p2,flag=0,num_of_games;
	char move1[20],move2[20];
	double ans;

	while(scanf("%ld",&n)==1 && n!=0)
	{
		if(flag==1)printf("\n");

		for(i=0;i<=n;i++)
		{
			players[i].win=0;
			players[i].played=0;
		}
	
		scanf("%ld",&game);
		num_of_games = (game * n * (n - 1)) / 2;
		for(i=0;i<num_of_games;i++)
		{
			scanf("%ld %s %ld %s",&p1,move1,&p2,move2);		
				
			if((move1[0] == 'r' && move2[0] == 'p') || (move1[0] == 'p' && move2[0] == 's') || (move1[0] == 's' && move2[0] == 'r')){ 
                           players[p2].win += 1;
						   players[p1].played += 1; 
                           players[p2].played += 1;       
                  } 
                  else if((move2[0] == 'r' && move1[0] == 'p') || (move2[0] == 'p' && move1[0] == 's') || (move2[0] == 's' && move1[0] == 'r')){ 
                           players[p1].win += 1;
						   players[p1].played += 1; 
                           players[p2].played += 1;    
                          } 
                  else{ 
                  } 

		
		}

		for(i=1;i<=n;i++)
		{


				if(players[i].played==0)
					printf("-\n");
					
				else
				{
					ans = (double) ( (double)players[i].win/ (double)players[i].played);				
					printf("%0.3lf\n",ans);			
			
				}	
			
		}

		//printf("\n");
		flag=1;
	
	
	
	}
}