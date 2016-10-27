#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char eng[15];
	char foreign[15];
}DIC;
DIC dic[100005];

int comp(const void* A, const void* B);
long binary_search(char a[],long m);



void main()
{

	//freopen("10282.in","r",stdin);
	//freopen("10282.out","w",stdout);

	long n=0,i,p,m,j;
	char eng[20],c,str[30];

	
	//taking dictionary inputs/////////
	
	while(scanf("%[^\n]",str)==1)
	{
		scanf("%c",&c);
	    p = strlen(str);

		if(strlen(str)==0)break;
		m=0;
		for(i=0;i<p;i++)
		{
			if(str[i]!=' ')
			eng[m++] = str[i];
			else
			{
			 eng[m] = '\0';
			 break;
			}		
		}
		strcpy( dic[n].eng , eng);
		m=0;
		for(j=i+1;j<p;j++)
		  eng[m++] = str[j];
		eng[m] = '\0';	
		strcpy( dic[n].foreign , eng);
		n++;	
	}
	//////////////////////////////////////


	qsort(dic,n,sizeof(DIC),comp);

	
	//for(i=0;i<n;i++)
	//printf("%s %s\n",dic[i].eng,dic[i].foreign);


	while(scanf(" %s",str)==1)
	{
	
		p = binary_search(str,n);

		if(p==-1)
			printf("eh\n");
		else
			printf("%s\n",dic[p].eng);
	
	}


}


int comp(const void* A, const void* B)
{
	DIC *a=(DIC*)A;
	DIC *b=(DIC*)B;
 
	int result;

	if( (result = strcmp(a->foreign,b->foreign))!=0 ) return result;
	return(strcmp(a->foreign,b->foreign));


}


long binary_search(char a[],long m)
{
  long beg,mid,end;

  beg=0;
  end=m-1;
  mid=(long)( (beg+end)/2 );

  while(beg<=end && ( strcmp(a,dic[mid].foreign)!=0) )
  {
	 if( strcmp(a,dic[mid].foreign)<0 )
	  end=end-1;
	 if( strcmp(a,dic[mid].foreign)>0 )
	  beg=beg+1;

	 mid=(long)( (beg+end)/2 );
  }

  if( strcmp(a,dic[mid].foreign)==0 )
	return mid;
  else
	return -1;

}
