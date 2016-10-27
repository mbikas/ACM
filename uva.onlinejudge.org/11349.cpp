#include<stdio.h>
#include<string.h>
long long mat[105][105];
int main()
{
	long long test,i,j,len,p,n,cases=1,r,c,diff,midx,midy;
	char input[10000],temp[200];
	bool f;
	gets(input);
	sscanf(input,"%lld",&test);
	while(test--)
	{
		scanf(" %s %s %lld",input,temp,&n);
		
		/*
		gets(input);
		len = strlen(input);
		f = false;
		p=0;
		for(i=0;i<len;i++)
		{
		if(f)temp[p++]=input[i];
		if(input[i]=='=')
		f = true;
		}
		temp[p]='\0';
		sscanf(temp,"%lld",&n);
		*/
		f=true;
		
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%lld",&mat[i][j]);
				if(mat[i][j]<0)f=false;
			}
			
			/*
			for(i=0;i<n;i++)
			{
			for(j=0;j<n;j++)
			printf("%lld ",mat[i][j]);		
			printf("\n");
			}
			*/
			if(!f) 
			{
				printf("Test #%lld: Non-symmetric.\n",cases++);
				continue;
			}
			if(n%2==0 )
			{
				
				//printf("Test #%lld: Non-symmetric.\n",cases++);
				
				f=true;
				
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						//diff=midx-i;
						r=n-i+1;
						
						//diff=midy-j;
						c=n-j+1;
						
						if(mat[i][j]!=mat[r][c])
						{
							f=false;
							break;
						}
					}
					if(!f) break;
				}
				if(!f) printf("Test #%lld: Non-symmetric.\n",cases++);
				else printf("Test #%lld: Symmetric.\n",cases++);
				
				continue;
			}
			midx = midy = (long long)n/2 + 1;
			
			f=true;
			
			for(i=1;i<=n;i++)
			{
				for(j=i;j<=n;j++)
				{
					diff=midx-i;
					r=midx+diff;
					
					diff=midy-j;
					c=midy+diff;
					
					if(mat[i][j]!=mat[r][c])
					{
						f=false;
						break;
					}
				}
				if(!f) break;
			}
			
			if(!f) printf("Test #%lld: Non-symmetric.\n",cases++);
			else printf("Test #%lld: Symmetric.\n",cases++);
			
			//gets(input);
			
			
	}
	
	return 0;
	
}
