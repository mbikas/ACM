/*** LIS COUNT O(NLOGN) IMPLEMENTATION ***/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define SZ 105

long temp[SZ],data[SZ];

long lis_count(long *d,long n);
int comp(const void *a,const void *b);

void main()
{
	long n,i,res,cases=1,f=0;

	while(scanf("%ld",&n)==1 && n!=-1)
	{
		if(f==1)printf("\n");
		else f=1;


		data[0]=n;
		i=1;
		while(scanf("%ld",&n)==1 && n!=-1)
		data[i++]=n;

		
		reverse(&data[0],&data[i]);
		res=lis_count(data,i);		

		printf("Test #%ld:\n  maximum possible interceptions: %ld\n",cases++,res);


	}
}



long lis_count(long *d,long n)
{
	long num,i,ind;
	long *pt;
	num=1;
	temp[0]=d[0];
	for(i=1;i<n;i++)
	{
		pt=(long *)bsearch(&d[i],temp,num,sizeof(long),comp);
		if(pt)
			ind=pt-temp;
		else
		{
			ind=num;
			num++;
		}
		temp[ind]=data[i];
	}
	return num;
}

int comp(const void *a,const void *b)
{
	long *x=(long *)a;
	long *y=(long *)b;
	if(*x<*y&&(y-temp==0||*x>*(y-1))) //to find LDS just change the <,> signs
		return 0;
	if(*x>=*y)
		return 1;
	if(*x<*y)
		return -1;
	return 0;
}