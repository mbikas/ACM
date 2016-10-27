#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define sz 150

typedef struct{
	char name[sz];
	long win;
	long set;
	long point;
	long loss;
	long set_point;
}match;

match matches[1005];
int ct=0;

void tokenize(char ch[]);
int comp(const void* A,const void* B);


void main()
{
	//freopen("10933.in","r",stdin);
	//freopen("10933.out","w",stdout);



	int T,i,j,k,M;
	char a[sz];

	while(scanf("%d",&T)==1 && T!=0)
	{
		ct=0;
		for(i=0;i<T;i++)
		{
			scanf(" %[^\n]",a);
			strcpy(matches[ct].name,a);
			ct++;
		}
		
		for(i=0;i<ct;i++)
		{
			matches[i].point=0;
			matches[i].set=0;
			matches[i].win=0;
			matches[i].loss=0;
			matches[i].set_point=0;
		}

		scanf("%d",&M);
		
		for(i=0;i<M;i++)
		{
			scanf(" %[^\n]",a);
			tokenize(a);
		}

		for(i=0;i<ct;i++)
		matches[i].set_point = matches[i].win - matches[i].loss;
		
		//for(i=0;i<ct;i++)
		//printf("%s %ld %ld %ld\n",matches[i].name,matches[i].set,matches[i].set_point,matches[i].point);
	

		qsort(matches,ct,sizeof(match),comp);

		
		//printf("1234567890123456789012345678901234567890\n");
	
		for(i=0;i<ct;i++)
		{
			j = strlen(matches[i].name);
			j = 20-j;
			printf("%s",matches[i].name);

			for(k=0;k<j;k++)
			printf(" ");			
			printf("%5ld%5ld%10ld\n",matches[i].set,matches[i].set_point,matches[i].point);
		}
		printf("\n");
	

	

	}//end of while
}//end of main




void tokenize(char ch[])
{
	char temp[sz],team1[sz],team2[sz];
	long p,q,i,j,len,ind1,ind2,point1,point2,set1=0,set2=0,set=0;
	long a[10],b[10];

	len= strlen(ch);
	ch[len]=' ';
	
	//////////////////////////////////////////
	p=0;
	for(i=0;i<len;i++)
	{
		if(ch[i]!='-')
		temp[p++]=ch[i];
		else
		{	temp[p]='\0';
			i++;
			break;
		}	
	}
	strcpy(team1,temp);

	p=0;
	for(;i<len;i++)
	{
		if(ch[i]!=':')
		temp[p++]=ch[i];
		else
		{
			temp[p]='\0';
			i++;
			break;
		}	
	}
	strcpy(team2,temp);

	//printf("%s --- %s\n",team1,team2);
	////////////////////////////////////////////////////////////////

	for(j=0;j<ct;j++)
	{	if(strcmp(matches[j].name,team1)==0)
		{ 
		  ind1 = j;
		  break;
		}
	}
	for(j=0;j<ct;j++)
	{
		if(strcmp(matches[j].name,team2)==0)
		{ 
		  ind2 = j;
		  break;
		}
	}

	//printf("%d %d\n",ind1,ind2);
	/////////////////////////////////////////////

	


	///////////////////////////////////////////
	bikas:
		j=i;
		p=0;

		for(i=j;i<=len;i++)
		{
				if(ch[i]!='-')
				{
					if(ch[i]!=' ')
						temp[p++]=ch[i];
				}
				else
				{
					temp[p]='\0';
					sscanf(temp,"%d",&point1);
					p=0;
					i++;
					//printf("%d\n",point1);
					a[set]=point1;
					break;
				}
		}
		p=0;
		j=i;
		for(i=j;i<=len;i++)
		{
				if(ch[i]!=' ')
				{
					if(ch[i]!=' ')
					temp[p++]=ch[i];
				}
				else
				{
					temp[p]='\0';
					sscanf(temp,"%d",&point2);
					p=0;
					//printf("%d\n",point2);
					b[set]=point2;
					j=i;
					set++;
					goto bikas;
				}
		}


        p=0;
		q=0;

		for(i=0;i<set;i++)
		{
			//printf("%d -- %d\n",a[i],b[i]);
			set1 = set1 + a[i];
			set2 = set2 + b[i];
			
			
			if(a[i]-b[i]>=2)
			{	matches[ind1].win++;
				matches[ind2].loss++;
				p++;
			}
			if(b[i]-a[i]>=2)
			{	matches[ind2].win ++;
				matches[ind1].loss++;
				q++;
			}
		}

		if(p>q)
			matches[ind1].set++;
		else
			matches[ind2].set++;


		matches[ind1].point +=set1;
		matches[ind2].point +=set2;

}

int comp(const void* A,const void* B)
{

	match *a = (match*)A;
	match *b = (match*)B;

	
	
	if(a->set < b->set) return(1);
	if(a->set > b->set) return(-1);	

	if(a->set_point < b->set_point) return(1);
	if(a->set_point > b->set_point) return(-1);

	if(a->point < b->point) return(1);
	if(a->point > b->point) return(-1);

	return (strcmp(a->name,b->name)) ;
	
	

}