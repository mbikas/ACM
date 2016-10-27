#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define swap(a,b) a^=b^=a^=b

#define sz 1000


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}

int palindrome(char a[])
{
	char temp[sz];
	strcpy(temp,a);
	reverse(temp);

	if(strcmp(temp,a)==0)return 1;
	return 0;


}

void main()
{

	char word[sz],str[sz];
	int p=0,len=0,i;

	while(gets(str))
	{
		if(strcmp(str,"DONE")==0)break;

		len = strlen(str);
		p=0;

		for(i=0;i<len;i++)
		{
			if( (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') )
			 word[p++]= (tolower)(str[i]);  
		
		}
		word[p]='\0';
		
		if(palindrome(word))
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");		
	
	
	}
}