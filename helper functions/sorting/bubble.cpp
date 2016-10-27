#include<stdio.h>
#include<string.h>

int assending(char array[100][20],int size);

void main()
{  
	int i,n;
	char x[100][20];
	
	printf("How many String:\t");
	scanf("%d",&n);
	
	printf("\nNow enter the Strings:\t");
	for(i=0;i<n;i++) 
		scanf(" %[^\n]",x[i]);
	
	assending(x,n);
	
	printf("ascending is:\n");
	for(i=0;i<n;i++)		
	{
		printf("%s\n",x[i]);
	}		
}

int assending(char array[100][20],int size)
{  
	int i,j,n=size;
	char temp[100];
	
	for(i=1;i<n;i++)
	{  
		for(j=0;j<n-i;j++)
		{
			if(strcmp(array[j],array[j+1])>0)
			{ 
				strcpy(temp,array[j]);
				strcpy(array[j],array[j+1]);
				strcpy(array[j+1],temp);
			}
		}
	}
	return 0;
}



