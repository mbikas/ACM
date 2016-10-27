#include<stdio.h>
#include<string.h>
#define sz 100

void sub_string(char a[],char sub[],int start,int end);

void main()
{
	char a[sz],sub[sz],sub1[sz],ch;
	int i,p,Length,flag,test;


	while(scanf("%d",&test)==1)
	{
			while(test>0)
			{
			//scanf("%c",&ch);
					scanf(" %s",a);
					p = strlen(a);
					for(Length = 1;Length<=p;Length++)
					{
				
								sub_string(a,sub,0,Length);
				
								if(p%Length !=0)
								continue;
								else
								{
									i=0;
									flag=1;
									while(i<p)
									{ 
											sub_string(a,sub1,i,i+Length);
											if(strcmp(sub,sub1) != 0)
											{	flag=0;
												break;
											}
											i = i+Length;
									}

									if(flag==1)
									{		printf("%d\n",Length);
											break;
									}
								}
					}//end of for		
				
					test--;	
			
			}


	
	
	}//end of while

}//end of main




void sub_string(char a[],char sub[],int start,int end)
{
	int i,len=0;

	for(i=start;i<end;i++)
	sub[len++] = a[i];

	sub[len] = '\0';
}