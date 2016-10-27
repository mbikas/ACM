/* WERTYU */

#include<stdio.h>
#include<string.h>

char input[8000000];

int main()
{
	char a[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	long len,len1,i,j;
	len=strlen(a);

	while(gets(input))
	{
		len1=strlen(input);
		
		for(i=0;i<len1;i++)
		{
			for(j=0;j<len;j++)
			{
				if(a[j]==input[i])
					printf("%c",a[j-1]);
			}
			if(input[i]==' ')
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
		