#include<stdio.h>
#include<string.h>

#define sz 3000

void main()
{
	long n,p;
	char a[sz];

	while(scanf("%ld\n",&n)==1)
	{
	
		while(n>0)
		{
	
			scanf(" %s",a);

		
			p = strlen(a);

			if(	(strcmp(a,"1")==0) || (strcmp(a,"4")==0) || (strcmp(a,"78")==0)	)
				printf("+\n");
			else if(	(a[p-1]=='5') && (a[p-2]=='3')	)
				printf("-\n");
			else if(	(a[0]=='9') && (a[p-1]=='4')	)
				printf("*\n");
			else if(	(a[0]=='1') && (a[1]=='9') && (a[2]=='0')	)
				printf("?\n");

			///////////optional///////////
			//else
			//	printf("\n");
			//////////////////////////////


			n--;	
		
		
		}	
	
	}
}