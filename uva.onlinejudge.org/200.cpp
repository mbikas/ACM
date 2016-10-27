#include<stdio.h>
#include<string.h>
#define sz 10000

char input[10001][21];

int tail=0;
char queue[sz];
void enqueue(char ch);

int main()
{
	int max,count,i,j,len,len1;	
	
	max=count=tail=0;
	
	while(scanf(" %s",input[count])==1)
	{
		if(strcmp(input[count],"#")==0)
		{
			
			for(i=0;i<max;i++)
			{
				for(j=0;j<count;j++)
				{
					len1 = strlen(input[j]);
					if(i<len1)enqueue(input[j][i]);					 	
				}				
			}			
			for(i=0;i<tail;i++)printf("%c",queue[i]);
			printf("\n");
			max = tail=count=0;
			continue;
		}
		
		len = strlen(input[count]);
		if(len>max)max = len;
		count++;
		
	}	
	
	return 0;
}

void enqueue(char ch)
{
	int i;
	
	for(i=0;i<tail;i++)
	{
		if(queue[i]==ch)
			return;	
	}
	queue[tail]=ch;
	tail++;
}