#include<stdio.h>
#include<string.h>

void main()
{
	long x,len,i; 
	char a[10000]; 

	while(scanf(" %[^\n]",a)==1)
	{
		x=0;
		len=strlen(a);

		for (i = len - 1;i>=0;i--)
		{
			   if (a[i] =='p'||a[i] =='q'||a[i] =='r'||a[i] =='s'||a[i] =='t'||a[i] =='u'||a[i] =='v'||a[i] =='w'||a[i] =='x'||a[i] =='y'||a[i] =='z')
					x = x+1; 
			   else if(a[i]=='C'||a[i]=='D'||a[i]=='E'||a[i]=='I')
			   {
					if(x>=2)
						x = x - 1;
					else 
					{
						x = 0;
						break;
					}
			   }
			  else if (a[i] == 'N')
			  {
				if (x < 1)
				{
				  x = 0;
				  break;
				}
				else
				  x = x;
			}
		}
		if(x==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}