#include<stdio.h>
#include<string.h>

void main()
{
	 char a[1000],*p;

	 while(gets(a))
	 {

			p=strtok(a," ");
			while(p)
			{
					printf("%s ",p);
					p=strtok(NULL," ");
			}
			printf("\n");
	 }

}
