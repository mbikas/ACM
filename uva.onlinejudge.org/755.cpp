#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 500

typedef struct{
	char a[15];
	
}Index;
Index index[100005];
long nindex=0;

void tokenize(char a[]);
long binary_search(char key[],long size);
void check_duplicate(char a[]);
int comp(void const *A, void const *B);
void output();

void main()
{
	long test,i,cases;
	char tel[sz];

	scanf("%ld",&cases);

	while(cases>0)
	{
		
			nindex=0;
			scanf("%ld",&test);
						
			for(i=0;i<test;i++)
			{
		
					scanf(" %[^\n]",tel);
					tokenize(tel);

					
			}

			qsort(index,nindex,sizeof(Index),comp);

			//for(i=0;i<nindex;i++)
			//printf("%s\n",index[i].a);
			//printf("-------------------------------\n");
			output();

			if(cases!=1)
			printf("\n");
			nindex=0;

			cases--;
	}
}



void tokenize(char a[])
{


	int len,i,x;
	char temp[15];
	x=0;

	len = strlen(a);

	for(i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			temp[x++] = a[i];
		else if(a[i]=='A'||a[i]=='B'||a[i]=='C')
		   temp[x++] = '2';
		else if(a[i]=='D'||a[i]=='E'||a[i]=='F')
		   temp[x++] = '3';
		else if(a[i]=='G'||a[i]=='H'||a[i]=='I')
		   temp[x++] = '4';
		else if(a[i]=='J'||a[i]=='K'||a[i]=='L')
		   temp[x++] = '5';
		else if(a[i]=='M'||a[i]=='N'||a[i]=='O')
		   temp[x++] = '6';
		else if(a[i]=='P'||a[i]=='R'||a[i]=='S')
		   temp[x++] = '7';
		else if(a[i]=='T'||a[i]=='U'||a[i]=='V')
		   temp[x++] = '8';
		else if(a[i]=='W'||a[i]=='X'||a[i]=='Y')
		   temp[x++] = '9';
		else
			continue;
	
	}

	temp[x] = '\0';

	//printf("%s\n",temp);

	strcpy(index[nindex].a,temp);
	nindex++;

}


int comp(void const *A, void const *B)
{

	Index *a = (Index*)A;
	Index *b = (Index*)B;

	return (strcmp(a->a,b->a));
}

void output()
{
	long i,ct;
	int p=0,j;
	char temp[15];

	strcpy(temp,index[0].a);

	ct=1;
	for(i=1;i<=nindex;i++)
	{	
		if(strcmp(temp,index[i].a)==0)
		{ 
			ct++;
		}
		else
		{
			if(ct>1)
			{
				for(j=0;j<3;j++)
					printf("%c",temp[j]);
				printf("-");

				for(j=3;j<7;j++)
					printf("%c",temp[j]);

				printf(" %ld\n",ct);
				p=1;
			}
			ct=1;
			strcpy(temp,index[i].a);
		}
		
		
		
	}

	if(p==0)
		printf("No duplicates.\n");




}