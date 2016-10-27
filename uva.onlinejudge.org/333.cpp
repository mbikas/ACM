//acm 333 Recognizing Good ISBNs
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define EOF '\0'

void reverse(char x[])
{
	long len,i,j;
	char temp;

	len=strlen(x);
	j=len-1;

	for(i=0;i<len/2;i++,j--)
	{
		//swap
		temp=x[i];
		x[i]=x[j];
		x[j]=temp;
	}
}

void main()
{
	char code[100];
	long s1,s2,digit,len,count,flag;
	while( gets(code) && code!=EOF)
	{
			len=strlen(code);
		

			flag=1;
			s1=0;
			s2=0;
			digit=0;

			count=len-1;
			while(count>=0 && code[count]==' ')
			{
				code[count--]='\0';
			}

			len=strlen(code);
			reverse(code);
			count=len-1;
			
			while(count>=0 && code[count]==' ')
				code[count--]='\0';
			reverse(code);
			len=strlen(code);
			
			for(count=0;count<len;count++)
			{
				if(isdigit(code[count]))
				{
					digit++;
					s1+=(code[count]-'0');
					s2+=s1;
				}

				else if(code[count]=='-')
				{
					;
				}

				else if(code[count]=='X' && digit==9)
				{
					digit++;
					s1+=10;
					s2+=s1;
				}

				else if(code[count]!= ' ')
				{
					//printf("%s is incorrect.\n",code);
					flag=0;
					break;
				}

				if(digit>10)
				{
					
					break;
				}
			}

			if(digit==10 && flag==1)
			{
				if(s2%11==0)
					printf("%s is correct.\n",code);
				else
					printf("%s is incorrect.\n",code);
			}

			else
				printf("%s is incorrect.\n",code);
		

	}
}