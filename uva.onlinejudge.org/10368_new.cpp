#include<stdio.h>

int wins(int player, long big, long small) ;

void main()
{
	long high,low,temp,win;
	while(scanf("%ld %ld",&low,&high)==2 && (low!=0 || high!=0))
	{
		
		
		if(low>high)
		{
			temp = low;
			low = high;
			high = temp;		
		}

		win = wins(1,high,low);
		
		if(win==1)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");



	
	}


}

int wins(int player, long big, long small) 
{ 

	long t; 

	if(big < small) 
	{ 
		t = big; 
		big = small; 
		small = t; 
	} 
	if(!(big%small)) 
		return player; 

	//for(long i=1; i*small<big; i++)
	for(long i=big/small; i>=1; i--) 
	{ 
		if(wins(!player, small, big - (small*i)) == player ) 
		return player; 
	} 
	
	return !player; 
} 
