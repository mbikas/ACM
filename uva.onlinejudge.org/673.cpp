//gacm 673 Parentheses Balance

#include<stdio.h>
#include<string.h>

void main()
{
	long n,count,count2,len;
	char s[200],stack[200];
	int top,flag;
	
	scanf("%ld ",&n);
	for(count=0;count<n;count++)
	{
		//scanf(" %[ ^\n]",s);
		gets(s);
		top=1;
		flag=1;
		len=strlen(s);
		
		if(len==0)
			printf("Yes\n");
		else
		{
		for(count2=0;count2<len;count2++)
		{
			if(s[count2]==')')
			{	
				if(top==1)
				{	
					flag=0;
					goto label;
				}

				else if(stack[--top]=='(')
				{
					flag=1;
					
				}
				
				else
				{
					flag=0;
					goto label;
				}
			}
			
			else if( s[count2] == ']')
			{	
				if(top==1)
				{	
					flag=0;
					goto label;
				}

				else if(stack[--top]=='[')
				{
					flag=1;
					
				}

				else
				{
					flag=0;
					goto label;
				}

				
			}

			else if(s[count2]=='(' || s[count2]=='[')
			{
				stack[top]=s[count2];
				top++;
			}

			
			
		}

		if(top>1)
			flag=0;
	label:
		if(flag==1)
			printf("Yes\n");

		else if(flag==0)
			printf("No\n");
	}
	}

	

} 