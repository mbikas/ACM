#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comp(const void*a, const void*b)
{
	char *x=(char*)a;
	char *y=(char*)b;

	if(strcmp(x,y)>0)
		return 1;
	else if(strcmp(x,y)<0)
		return -1;
 return 0;
}
 
int main()
{
	char str[105][100];
	long n,c,rw,i,j,k,l_max,len,br,in;

	while(scanf("%ld",&n)==1)
	{
		l_max=0;
		for(i=0;i<n;i++)
		{
			scanf(" %[^\n \r\t]",str[i]);
			len=strlen(str[i]);
			if(len>l_max)
				l_max=len;
		}

		c=(long)62/(l_max+2);
		rw=l_max+2;
		
		if(n%c==0)
			br=n/c;
		else
			br=(n/c)+1;
		
		qsort(str,n,sizeof(str[0]),comp);

		printf("------------------------------------------------------------\n");
		for(i=0;i<br;i++)
		{
			in=i;
			for(j=0;j<c;j++)
			{
				if(in<n)
				{
					printf("%s",str[in]);
					len=strlen(str[in]);
					for(k=len;k<rw;k++)
						printf(" ");
					in=in+br;
				}
			}
			printf("\n");
		}
			
	}
	return 0;
}






