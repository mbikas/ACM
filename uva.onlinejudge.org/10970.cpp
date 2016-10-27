#include<stdio.h>

void main()
{
	long row,col,x;
	while(scanf("%ld %ld",&row,&col)==2)
	{
		x = row-1;

		row = row * (col-1);

		x = x+ row;
		if(x<0)x=0;
		printf("%ld\n",x);


	}


}