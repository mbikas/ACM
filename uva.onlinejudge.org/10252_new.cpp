#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define sz 3000

void main()
{
	char string1[sz],string2[sz];
	int i,j,temp1[150],temp2[150],f=0;

	while( gets(string1) && gets(string2) )
	{

		//if(f==1)printf("\n");
		//else f=1;
		for(i=96;i<=124;i++)temp1[i]=temp2[i]=0;


		for(i=0, j=strlen(string1) ; i<j ;i++)
		{ 
			if(string1[i]<97) string1[i]+=32; 
			temp1[string1[i]]++; 
		} 
		
		for(i=0, j=strlen(string2) ; i<j ;i++)
		{ 
			if(string2[i]<97) string2[i]+=32; 
			temp2[string2[i]]++; 
		}
		
		for(i=97;i<123;i++)
		{ 
			if(temp1[i]&&temp2[i])
			{ 
				if(temp1[i]<temp2[i]) j=temp1[i]; 
				else j=temp2[i]; 
				while(j)
				{ 
					printf("%c",i); 
					j--; 
				} 
			} 
		}
		printf("\n");		
	}
}
