#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define sz 200

typedef struct{
	char a[100];
}word;
word words[105];
int nword = 0;

int comp1(void const *A, void const *B);
int check_anagram(char word1[],char word2[]);
int comp(void const *A, void const *B);
void output();

void main()
{

	//freopen("454.in","r",stdin);
	//freopen("454.out","w",stdout);


		char str[sz];
		long test,f=0;

		scanf("%ld\n",&test);

		while(test--)
		{
			if(f==1)printf("\n");
			else f=1;

			 nword = 0;

	
			while( gets(str) )
			{
				if(strlen(str)==0)
					break;
		
				strcpy(words[nword].a,str);
				nword++;
			}

			output();
		
		}
}



int check_anagram(char word1[],char word2[])
{
	char a[sz],b[sz];
	long p,len1,len2,i;
	
	len1=0;
	p = strlen(word1);
	for(i=0;i<p;i++)
	{   if(isalpha(word1[i]))
			a[len1++] = word1[i];	
	}
	a[len1] = '\0';

	len2=0;
	p = strlen(word2);
	for(i=0;i<p;i++)
    {   if(isalpha(word2[i]))
			b[len2++] = word2[i];
	}	
	b[len2] = '\0';

	if(len1!=len2)return 0;



	qsort(a,len1,sizeof(a[0]),comp);	
	qsort(b,len2,sizeof(b[0]),comp);	

	//printf("%s -- %s\n",a,b);

	if(strcmp(a,b)==0)
	return 1;

	return 0;
	
}



void output()
{

	long i,j;

	qsort(words,nword,sizeof(word),comp1);
	
	for(i=0;i<nword-1;i++)
	{ 
		for(j = i+1;j<nword;j++)
		{
		  if( check_anagram(words[i].a,words[j].a)==1 )
			  printf("%s = %s\n",words[i].a,words[j].a);

		
		}
		
	}
}

int comp(void const *A, void const *B)
{
	char *a = (char*)A;
	char *b = (char*)B;

	return *a - *b;
}


int comp1(void const *A, void const *B)
{
	word *c = (word*)A;
	word *d = (word*)B;

	return ( strcmp(c->a,d->a) );
}
