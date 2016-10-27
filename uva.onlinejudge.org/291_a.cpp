#include<stdio.h>
#include<string.h>

char str[6][6],x[10];

void backtrack(int k);
void init();
void constract(char a[],int k,char c[],int *ncandidate);

void main()
{
	init();
	memset(x,0,sizeof(x));
	x[1]='1';
	backtrack(2);
}

void init()
{
	memset(str,0,sizeof(str));
	str[1][2]=1;	str[2][1]=1;
	str[1][5]=1;	str[5][1]=1;
	str[1][3]=1;	str[3][1]=1;
	str[2][3]=1;	str[3][2]=1;
	str[2][5]=1;	str[5][2]=1;
	str[3][4]=1;	str[4][3]=1;
	str[3][5]=1;	str[5][3]=1;
	str[4][5]=1;	str[5][4]=1;
}

void constract(char a[],int k,char c[],int *ncandidate)
{
	int i;
	bool flag[6][6];
	memset(flag,0,sizeof(flag));
	for(i=1;i<(k-1);i++)
	{
		flag[a[i]-48][a[i+1]-48]=1;
		flag[a[i+1]-48][a[i]-48]=1;
	}

	for(i=1;i<6;i++)
	{
		if(str[a[k-1]-48][i])
		{
			if(flag[a[k-1]-48][i]==0)
				c[(*ncandidate)++]=i+48;
		}
	}
}

void backtrack(int k)
{
	int i,ncandidate=0;
	char c[10];
	if(k==10)
	{
		printf("%s\n",x+1);
		return;
	}
	constract(x,k,c,&ncandidate);

	for(i=0;i<ncandidate;i++)
	{
		x[k]=c[i];
		backtrack(k+1);
	}
}