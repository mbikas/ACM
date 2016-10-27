#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define sz 2000

typedef struct{
	char a[sz];
}word;
word words[sz];
long len=0;

void check_word(char a[]);


int comp(void const *A, void const *B)
{

	word *a = (word*)A;
	word *b = (word*)B;

	return (strcmp(a->a,b->a));

}

void main()
{

	//freopen("g.txt","r",stdin);
	//freopen("gout.txt","w",stdout);

	long p=0,i;
	char c,a[sz];
	int flag=0;


	while(scanf("%c",&c)==1)
	{
	
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			if(flag==1)
			{ a[p++]='-';
			  a[p++]=tolower(c);
			  flag=0;
			}
			else
				a[p++]=tolower(c);		
		}
		else if(c=='-')
			flag=1;
		else
		{
			if(flag==1)
			{
				flag=0;
				//continue;
			}
			else
			{
				a[p]='\0';
				//printf("%s\n",a);
				if(p>0)
				check_word(a);
				flag=0;
				p=0;
				
			}
		
		}
	
	}

	qsort(words,len,sizeof(word),comp);
	for(i=0;i<len;i++)
		printf("%s\n",words[i].a);

}

void check_word(char a[])
{
	long i;
	for(i=0;i<len;i++)
	{
		if(strcmp(a,words[i].a)==0)
			return;	
	}
	strcpy(words[len].a,a);
	len++;

}