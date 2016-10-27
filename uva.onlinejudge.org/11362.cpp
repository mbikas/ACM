#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int cmp(const void *a,const void *b)
{
	char *A=(char*)a;
	char *B=(char*)b;
	return strcmp(A,B);
}
int main()
{
	long tcas,i,j,k,len,l,n;
	char str[10005][15],split[15];
	bool flag;
	scanf("%ld",&tcas);
	while(tcas--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",str[i]);		
		}
		qsort(str,n,sizeof(str[0]),cmp);
		flag=true;
		for(i=0;i<n;i++)
		{
			len=strlen(str[i]);
			for(j=i+1;j<i+2;j++)
			{
				l=strlen(str[j]);
				for(k=0;k<l && k<len;k++)
				{
					split[k]=str[j][k];
				}
				split[k]='\0';
				if(strcmp(str[i],split)==0)
				{
					flag=false;
					break;
				}
			}
			if(flag==false)
				break;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}