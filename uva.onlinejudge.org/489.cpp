#include<stdio.h>
#include<string.h>
#define sz 4000


void main()
{
	char puzzle[sz],guess[sz];
	int round,i,x,len,ct,gues[30],puz[30],letter;

	while(scanf("%d",&round)==1 && round!=-1)
	{
		scanf(" %s %s",puzzle,guess);


		for(i=0;i<=26;i++)
		{	puz[i]=0;
			gues[i]=0;
		}

		letter=0;
		len = strlen(puzzle);	
		for(i=0;i<len;i++)
		{
			x = puzzle[i]-'a';
			if(puz[x]==0)
			{
				puz[x]=1;
				letter++;
			}
		}

		ct=0;
		len = strlen(guess);	
		for(i=0;i<len;i++)
		{
			x = guess[i]-'a';

			if(gues[x]==0)
			{
				if(puz[x]==1)
				{
					gues[x]=1;
					letter--;
				}
				else
					ct++;
			}

			if(ct==7 || letter==0)break;
		}

		printf("Round %d\n",round);
		if(letter==0)
			printf("You win.\n");
		else if(ct==7)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");

	
	
	
	}
}