#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
	char str[202];
}word;
word words[5002];
long len=0;
void add(char a[]);


int comp(void const *A, void const *B)
{

	word *a = (word*)A;
	word *b = (word*)B;

	return (strcmp(a->str,b->str));

}

void main()
{
	//freopen("10815.in","r",stdin);
	//freopen("10815.out","w",stdout);
	
	char a[205],c;
	int p,flag;
	long i;


	p=0;
	flag=0;
	
	while(scanf("%c",&c)==1)
	{
		
		if( (c>='a'&&c<='z')|| (c>='A'&&c<='Z') )
		{
		   if(flag==0)flag=1;
		   a[p++]=tolower(c);			
		}
		else
		{
			
			
			if(flag==1)
			{
				a[p]='\0';
				flag=0;	
				add(a);	
				//printf("%s\n",a);
			}
			p=0;
			flag=0;
				
		}
	
	}//while

	qsort(words,len,sizeof(word),comp);

	for(i=0;i<len;i++)
		printf("%s\n",words[i].str);

}//main

void add(char a[])
{

	long i;
	int f=0;

	for(i=0;i<len;i++)
	{
		if(strcmp(a,words[i].str)==0)
		{
			f=1;
			return;
		}	
	}


	strcpy(words[len].str,a);
	len++;

}