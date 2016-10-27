#include<stdio.h>
#include<string.h>
#define sz 1000

void main()
{
	int row,col,test,n,min;
	char chess,temp[sz];

	gets(temp);
	sscanf(temp,"%d",&test);

	while(test--)
	{
		gets(temp);
		sscanf(temp,"%c %d %d",&chess,&row,&col);

		if(chess=='r' || chess=='Q')
		{
			min = 100;
			if(row<min)min = row;
			if(col<min)min = col;
			printf("%d\n",min);
		}

		else if(chess=='k') 
		{ 
			if(row*col % 2==1) 
				printf("%d\n",(row*col+1)/2); 
			else 
				printf("%d\n",row*col/2); 
		} 
		else if(chess=='K')
		{
			n = (int)((row+1)/2) * (int)((col+1)/2);
			printf("%d\n",n);		
		}
	
	}


}