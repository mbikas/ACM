//Acm 483 Word Scramble
//solved by Bikas CSE SUST

#include<stdio.h>
#include<string.h>
#define sz 100000

void main()
{ 
	
	long p,i,j,len;  
	char words[sz],temp[sz];

	while(scanf(" %[^\n]",words)==1)
	{
		len = strlen(words);
		p=0;

		for(i=0;i<=len;i++)
		{
			if(words[i]==' ' || i==len)
			{

				for(j=p-1;j>=0;j--)
				printf("%c",temp[j]);

				if(i==len)
					printf("\n");
				else
					printf(" ");				
				p=0;				
			}
			else
				temp[p++]=words[i];				
			
			
		}
	}
}
