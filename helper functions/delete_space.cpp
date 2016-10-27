#include<stdio.h>
#include<string.h>

void delete_space(char a[]);

void main()
{
	
	char str[100];
	

	while( scanf(" %[^\n]",str) ==1)
	{
		
		delete_space(str);
		printf("[%s]\n",str);
	}


}

void delete_space(char a[])
{
		int i,j,k,len;
		char temp1[100];

		len = strlen(a);

		strcpy(temp1,a);

		i=0;
		while(temp1[i]==' ')i++;

		j=len-1;
		while(temp1[j]==' ')j--;

		len=0;
		for(k=i;k<=j;k++)
		a[len++] = temp1[k];

		a[len] = '\0';

}
