#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define sz 3000

void main()
{
	char a[sz],b[sz];
	int i,j,flag1[30],flag2[30],len1,len2,p,f=0;

	while(gets(a) && gets(b))
	{
		

		for(i=0;i<26;i++)flag1[i]=0;
		len1 = strlen(a);
		for(i=0;i<len1;i++)
		{
			a[i] = tolower(a[i]);
			flag1[a[i]-'a']++;
		}
		
		for(i=0;i<26;i++)flag2[i]=0;
		len2 = strlen(b);
		for(i=0;i<len2;i++)
		{
			b[i] = tolower(b[i]);
			flag2[b[i]-'a']++;
		}
		
		for(i=0;i<26;i++)
		{
			if(flag1[i]>0 && flag2[i]>0)
			{
				if(flag1[i]<flag2[i])p = flag1[i];
				else p = flag2[i];
				for(j=0;j<p;j++)
				printf("%c",i+97);				
			}			
		}	
		printf("\n");	
	
	}
}
