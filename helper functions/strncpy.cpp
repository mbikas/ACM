#include<stdio.h>
#include<string.h>

void main()
{
	char a[100],str[100];

	while(scanf(" %s",a)==1)
	{

		strncpy(str,a+2,3);
		str[3]='\0';
		printf("%s\n",str);

	}

}
