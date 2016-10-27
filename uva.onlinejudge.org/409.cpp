#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int comp(const void* a, const void* b);
int binary_search(char a[],int m);

typedef struct{
char c[25];
}KEYWORD;
KEYWORD keyword[25];

typedef struct{
char c[80];
}EXCUSE;
EXCUSE excuse[25];

void main()
{
	//freopen("409.in","r",stdin);
	//freopen("409.out","w",stdout);
	int i,j,len1,p,m,n,len,num[25];
	int number,max,count=1,z;
	char temp[71];

	while(scanf("%d %d",&m,&n)==2)
	{

		///taking the keyword and uppercasing them///////////
		for(i=0;i<m;i++)
		{	scanf(" %s",keyword[i].c);
		    p = strlen(keyword[i].c);
			for(j=0;j<p;j++)
			keyword[i].c[j] = toupper(keyword[i].c[j]);
			
		}
		//////////////////////////////////////////////

		//////////sorting the keywords for bsearch/////
		qsort(keyword,m,sizeof(KEYWORD),comp);


		//for(i=0;i<m;i++)
		//printf("%s\n",keyword[i].c);

		
		for(i=0;i<n;i++)
		scanf(" %[^\n]",excuse[i].c);

		printf("Excuse Set #%d\n",count);


		
		//////////////////finding keywords in the excuses/////////////////
		max=0;

		for(i=0;i<n;i++)
		{
			number=0;
			len = strlen(excuse[i].c);

			p=1;
			for(j=0;j<=len;j++)
			{
				len1=0;
				if(p==1 || (excuse[i].c[j]>=65&&excuse[i].c[j]<=122))
				{
					while(excuse[i].c[j]>=65&&excuse[i].c[j]<=122)
					 { temp[len1++]=toupper(excuse[i].c[j]);
						j++;
					 }
					p=0;
					temp[len1]=NULL;

					if(len1>0)
					z = binary_search(temp,m);
					//printf("%s %d\n",temp,z);
					if( z!=-1)
					number++;
				}
			}

			if(number>max)
			max=number;
			num[i] = number;
		}
		/////////////////////////////////////////////////////////////////////



		for(i=0;i<n;i++)
		{
			if(num[i]==max)
			printf("%s\n",excuse[i].c);
		}

		printf("\n");
		count++;
	}



}




int comp(const void* a, const void* b)
{
  
	KEYWORD *A = (KEYWORD*)a;
	KEYWORD *B = (KEYWORD*)b;
	
	return (strcmp(A->c,B->c));

}



int binary_search(char a[],int m)
{
  int beg,mid,end;

  beg=0;
  end=m-1;
  mid=(int)( (beg+end)/2 );

  while(beg<=end && ( strcmp(a,keyword[mid].c)!=0) )
  {
	 if( strcmp(a,keyword[mid].c)<0 )
	  end=mid-1;
	 if( strcmp(a,keyword[mid].c)>0 )
	  beg=mid+1;

	 mid=(int)( (beg+end)/2 );
  }

  if( strcmp(a,keyword[mid].c)==0 )
	return mid;
  else
	return -1;

}


