#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	long *A=(long*)a;
	long *B=(long*)b;
	if(*A>*B)
		return 1;
	if(*A<*B)
		return -1;
	return 0;
}

int main()
{
	long tcas,n,i,j,k,pos[25],max,sum,min,t,m,p,temp[25],po,l,tmp;
	
	scanf("%ld",&tcas);
	while(tcas--)
	{
		scanf("%ld",&n);
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&pos[i]);
			temp[i]=pos[i];
			if(pos[i]>max)
				max=pos[i];
		}
		qsort(pos,n,sizeof(pos[0]),cmp);
		min=9999999;
		for(i=1;i<=max;i++)
		{
			sum=0;
			p=i;
			for(j=0;j<n;j++)
			{
				m=9999999;
				po=p;
				for(k=0;k<n;k++)
				{
					if(pos[k]!=-1)
					{
						t=pos[k]-p;
						if(t<0)
							t=t*-1;
						if(m>t)
						{
							m=t;
							tmp=pos[k];
							l=k;
						}
					}
				}
				pos[l]=-1;
				p=tmp;
				t=po-p;
				if(t<0)
					t=t*-1;
				sum=sum+t*2;
			}
			for(j=0;j<n;j++)
				pos[j]=temp[j];
			if(sum<min)
			{
				min=sum;
			}
		}
		printf("%ld\n",min);
		
	}
	return 0;
}
