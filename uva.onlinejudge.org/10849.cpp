#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

bool check_same_line(long x1,long y1,long x2,long y2);


int main()
{
	long i,cases,test,n,x1,x2,y1,y2;
	scanf("%ld",&test);

	while(test--)
	{
		scanf("%ld",&cases);
		scanf("%ld",&n);
		while(cases--)
		{
			scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);

			//Out of the board
			if(x1>n || x2>n || y1>n || y2>n )
			{
				printf("no move\n");
				//continue;		
			}
		
			//Source and Destination is same
			else if(x1==x2 && y1==y2)
			{
				printf("0\n");
				//continue;		
			}
			
			//On the same line
		
			else if( ( abs(x1-x2) == abs(y1-y2) ) || (x1+y1 == x2+y2) )
			{
				printf("1\n");
				//continue;			
			}
			
			//On the different line
			else if(check_same_line(x1,y1,x2,y2))
			{
				printf("2\n");
				//continue;			
			}
			else 
			{
				printf("no move\n");
				//continue;			
			}
		
		}
	
	
	}

	return 0;
}

bool check_same_line(long x1,long y1,long x2,long y2)
{
	if ( ( (x1%2==0 && y1%2==0) || (x1%2!=0 && y1%2!=0) ) && ( (x2%2==0 && y2%2==0) || (x2%2!=0 && y2%2!=0) ) )
		return true;

	if ( ( (x1%2==0 && y1%2!=0) || (x1%2!=0 && y1%2==0) ) && ( (x2%2==0 && y2%2!=0) || (x2%2!=0 && y2%2==0) ) )
		return true;

	return false;
}
