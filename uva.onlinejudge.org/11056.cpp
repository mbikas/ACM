#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define sz 105
void tokenize(char a[]);

typedef struct{
	char a[25];
	long time;
}name;
name names[sz];
int len=0;


void print(long row)
{
	printf("Row %ld\n",row);	
}


int comp(const void* A, const void* B)
{
	name *a=(name*)A;
	name *b=(name*)B;
	
	int len1,i;
	char temp1[30],temp2[30];
	
	if(a->time < b->time) return(-1);
	if(a->time > b->time) return(1);

	strcpy(temp1,a->a);
	len1 = strlen(temp1);
	
	for(i=0;i<len1;i++)
	temp1[i]=tolower(temp1[i]);	
	

	strcpy(temp2,b->a);
	len1 = strlen(temp2);
	
	for(i=0;i<len1;i++)
	temp2[i]=tolower(temp2[i]);	

	return (strcmp(temp1,temp2));

	

}




void main()
{

	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	long n,i,p,row;
	char a[1000];
	while(scanf("%ld",&n)==1)
	{
		//if(n==0)
		//	break;

		len=0;
		for(i=0;i<n;i++)
		{
			scanf(" %[^\n]",a);
			tokenize(a);
			len++;
		
		}

		//for(i=0;i<len;i++)
		//	printf("%s %ld\n",names[i].a,names[i].time);

		qsort(names,len,sizeof(name),comp);

		row=1;
		//printf("Row %ld\n",row);
		//row++;
		p=0;
		for(i=0;i<len;i++)
		{
			if(i%2==0)
			{print(row);
			 row++;
			}
			printf("%s\n",names[i].a);
		}

		//if(n!=0)
		printf("\n");
	
	}


}



void tokenize(char a[])
{
	int i,p,j,flag,len1;
	char str[25];
	long min,sec,mlsec;

	len1 = strlen(a);

	p=0;
	for(i=0;i<len1;i++)
	{
	
		if(a[i]!=':')
		{
			str[p++]=a[i];
		}
		else
		{
			while(str[p]==' ')p--;
			p--;
			str[p]='\0';
			//printf("%s\n",str);
			strcpy(names[len].a,str);
			break;
		
		}	
	
	}
	p=0;
	flag=0;
	for(j=i;j<len1;j++)
	{
		if( (a[j]>='0'&&a[j]<='9') )
		{
			if(flag==0)flag=1;
			str[p++]=a[j];
		}
		else
		{
			if(flag==1)
			{
				str[p]='\0';
				sscanf(str,"%ld",&min);
				break;
			}
		}	
	}
	
	p=0;
	flag=0;
	for(i=j;i<len1;i++)
	{
		if( (a[i]>='0'&&a[i]<='9') )
		{
			if(flag==0)flag=1;
			str[p++]=a[i];
		}
		else
		{
			if(flag==1)
			{
				str[p]='\0';
				sscanf(str,"%ld",&sec);
				break;
			}
		}	
	}

	p=0;
	flag=0;
	for(j=i;j<len1;j++)
	{
		if( (a[j]>='0'&&a[j]<='9') )
		{
			if(flag==0)flag=1;
			str[p++]=a[j];
		}
		else
		{
			if(flag==1)
			{
				str[p]='\0';
				sscanf(str,"%ld",&mlsec);
				break;
			}
		}	
	}

	//printf("%ld %ld %ld\n",min,sec,mlsec);

	mlsec = (min*60*1000) + (sec*1000) +mlsec;

	
	//printf("%ld\n",mlsec);

	names[len].time= mlsec;







}