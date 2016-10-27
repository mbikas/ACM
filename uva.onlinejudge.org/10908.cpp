#include<stdio.h>
#include<string.h>
#define sz 105

typedef struct{
	char col[sz];
}ROW;
ROW row[sz];

long r,c;
int check_row_right(char val,long rq,long cq,long p);
int check_row_left(char val,long rq,long cq,long p);
int check_col_up(char val,long rq,long cq,long p);
int check_col_down(char val,long rq,long cq,long p);

void main()
{

	char val;
	long rq,cq,test,x,i,square,query;

	scanf("%ld",&test);

	while(test--)
	{
		
		scanf("%ld %ld %ld",&r,&c,&query);
		printf("%ld %ld %ld\n",r,c,query);

		for(i=0;i<r;i++)
			scanf(" %[^\n]",row[i].col);

		while(query--)
		{
			scanf("%ld %ld",&rq,&cq);


			if(rq>=r && cq>=c)
			{
				printf("0\n");
				continue;
			}

			val = row[rq].col[cq];

			
			square=1;
			i=1;
			while(1)
			{

				x = check_row_right(val,rq,cq+i,i);
				if(x==0)
					break;
					
				x = check_row_left(val,rq,cq-i,i);
				if(x==0)
					break;
				x = check_col_up(val,rq-i,cq,i);
				if(x==0)
					break;
				x = check_col_down(val,rq+i,cq,i);
				if(x==0)
					break;

				i++;				
				square += 2;		
			}

			printf("%ld\n",square);
		
		
		}

	
	
	
	}


}

int check_row_right(char val,long rq,long cq,long p)
{
	long i,x,y;

	if(cq>=c)
		return 0;

	x = rq + p;
	if(x>=r)
		return 0;
	
	y = rq - p;
	if(y<0)
		return 0;
	
	for(i=rq;i<=x;i++)
	{
		if(row[i].col[cq]!=val)
			return 0;
	}

	for(i=rq;i>=y;i--)
	{
		if(row[i].col[cq]!=val)
			return 0;
	}

	return 1;
}

int check_row_left(char val,long rq,long cq,long p)
{
	long i,x,y;


	if(cq<0)
		return 0;

	x = rq + p;
	if(x>=r)
		return 0;
	
	y = rq - p;
	if(y<0)
		return 0;
	
	for(i=rq;i<=x;i++)
	{
		if(row[i].col[cq]!=val)
			return 0;
	}

	for(i=rq;i>=y;i--)
	{
		if(row[i].col[cq]!=val)
			return 0;
	}

	return 1;
}

int check_col_up(char val,long rq,long cq,long p)
{
	long i,x,y;


	if(rq<0)
		return 0;

	x = cq + p;
	if(x>=c)
		return 0;
	
	y = cq - p;
	if(y<0)
		return 0;
	
	for(i=cq;i<=x;i++)
	{
		if(row[rq].col[i]!=val)
			return 0;
	}

	for(i=cq;i>=y;i--)
	{
		if(row[rq].col[i]!=val)
			return 0;
	}

	return 1;
}

int check_col_down(char val,long rq,long cq,long p)
{
	long i,x,y;


	if(rq>=r)
		return 0;

	x = cq + p;
	if(x>=c)
		return 0;
	
	y = cq - p;
	if(y<0)
		return 0;
	
	for(i=cq;i<=x;i++)
	{
		if(row[rq].col[i]!=val)
			return 0;
	}

	for(i=cq;i>=y;i--)
	{
		if(row[rq].col[i]!=val)
			return 0;
	}

	return 1;
}
