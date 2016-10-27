#include<stdio.h>
#include<string.h>
#define sz 1005
void main()
{
	int secret[sz],temp[sz],guess[sz];
	long cases=1,strong,weak,i,j,n,p,len,x;
	char a[3000];

	while(scanf("%ld",&n)==1 && n!=0)
	{
		printf("Game %ld:\n",cases++);

		scanf(" %[^\n]",a);
		len = strlen(a);
		n=0;
		for(i=0;i<len;i++)
		{
			if(a[i]>='1' && a[i]<='9')
				secret[n++]=a[i]-'0';
		}

		while(1)
		{
			strong=0;
			p=0;

			scanf(" %[^\n]",a);
			len = strlen(a);
			x=0;
			for(i=0;i<len;i++)
			{ 	if(a[i]>='0' && a[i]<='9')
				{	guess[x++]=a[i]-'0';
			        if(guess[x-1]==0)
					p++;
				}		            
			}
			if(p==n)break;

			for(i=0;i<n;i++)
				temp[i]=secret[i];

			for(i=0;i<x;i++)
			{   if(guess[i]==temp[i])
					{	strong++;
						temp[i]=-1;
						guess[i]=-1;
					}
				
			}

			

			weak=0;

			for(i=0;i<x;i++)
			{
				if(guess[i]!=-1)
				{
					for(j=0;j<n;j++)
					{
						if(temp[j]==guess[i])
						{
							weak++;
							temp[j]=-1;
							guess[i]=-1;
							break;
						}
					}
				}
			
			}

			printf("    (%ld,%ld)\n",strong,weak);



		}
	
	
	}//while
}//main