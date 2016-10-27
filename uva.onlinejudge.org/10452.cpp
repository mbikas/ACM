#include<stdio.h>
#include<string.h>

typedef struct{
	char a[10];
}word;
word words[10];


//int check_target(int len,int pos,int width);
char find_char(char c);


void main()
{
	long test;
	int i,len,width,pos,p;
	char c;
	
	
	scanf("%ld",&test);

	while(test>0)
	{
		scanf("%d %d",&len,&width);
		
		for(i=0;i<len;i++)
		scanf(" %[^\n]",words[i].a);
		
		for(i=0;i<width;i++)
		{	if(words[len-1].a[i]=='@')
			{   pos = i;
				break;
			}
		}

		p = len-1;
		c = 'I';

		while(1)
		{
			
			if(p!=0 && words[p-1].a[pos]==c )
			{
				p = p-1;
				pos = pos;
				c = find_char(c);
				if(c=='a')
				{	printf("forth\n");
					break;
				}
				else
					printf("forth ");
			}
			else if(  pos!=0 && words[p].a[pos-1]==c )
			{
				
				pos = pos-1;
				c = find_char(c);
				if(c=='a')
				{	printf("left\n");
					break;
				}
				else
					printf("left ");
			}
			else if(pos!= width-1 && words[p].a[pos+1]==c )
			{
				pos = pos+1;
				c = find_char(c);
				if(c=='a')
				{	printf("right\n");
					break;
				}
				else
					printf("right ");
				
			}
			else
				continue;
			
		
		}
	
	
		test--;
	}
}


char find_char(char c)
{
	if(c=='I')
	{
		return 'E';
		
	}
	else if(c=='E')
	{
		return 'H';
		
	}
	else if(c=='H')
	{
		return 'O';
		
	}
	else if(c=='O')
	{
		return 'V';
		
	}
	else if(c=='V')
		return 'A';
	else if(c=='A')
		return '#';
		
	return 'a';

}

/*
int check_target(int len,int pos,int width)
{


		
	
		if(len!=0)
		{
			if(words[len-1].a[pos]=='#')
				return 1;		
		}
		if(pos!=0)
		{
			if(words[len].a[pos-1]=='#')
				return 1;
		}
		if(pos!=width-1)
		{
			if(words[len].a[pos+1]=='#')
				return 1;		
		}

		return 0;
}
*/