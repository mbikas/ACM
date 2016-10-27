#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[2001][2001];

int comp(const void* a, const void* b);


 


void main()
{
	long i,j,n,p;

	char ch[76];

	

	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
		 scanf (" %s %[^\n]",str[i],ch);

		qsort(str,n,sizeof(str[0]),comp);

	
		 
		//for(i=0;i<n;i++)
		//printf("%s\n",str[i]);


        for(i=0;i<n;i++)
		{
			
					p=1;
					for(j=i+1;j<n;j++)
					{
						if(strcmp(str[i],str[j])==0 )
						{	
							p++;
						}

						else
						{
							break;
						}
					}

					printf("%s %ld\n",str[i],p);
					i=j-1;		
		
		}	


	}
}






int comp(const void* a, const void* b)
{
  
	return (strcmp((char *)a,(char *)b));
}
