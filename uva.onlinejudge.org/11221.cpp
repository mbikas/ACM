#include<stdio.h>
#include<math.h>
#include<string.h>
#define sz 11000
int main()
{
	long test,i,j,len,x,num,m,n,cases=1,len1,len2,p;
	char word[sz],str[sz];
	char line1[sz],line2[sz];



	scanf("%ld",&test);
	while(test--)
	{
		printf("Case #%ld:\n",cases++);
		scanf(" %[^\n]",word);
		p = strlen(word);

		len=0;
		for(i=0;i<p;i++)
		{
			if(word[i]>='a' && word[i]<='z')str[len++]=word[i];
		}
		str[len]='\0';

		n  =  (long)(sqrt(len));

		if(n*n !=len)
		{
			printf("No magic :(\n");
			continue;		
		}

		//check

		len1=0;		
		m=0;
		for(i=0;i<n;i++)
		{
			m=i;
			for(j=0;j<n;j++)
			{	line1[len1++]=str[m];
				//printf("m = %d\n",m);
				m=m+n;
			}
			    
		}		
		line1[len1]='\0';
		//printf("line1 = %s\n",line1);
		if(strcmp(line1,str)!=0)
		{
				printf("No magic :(\n");
				continue;			
		}

		len1=0;		
		m=len-1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{	line1[len1++]=str[m];
				m--;
			}
			    
		}		
		line1[len1]='\0';
		//printf("line1 = %s\n",line1);
		if(strcmp(line1,str)!=0)
		{
				printf("No magic :(\n");
				continue;			
		}

		len1=0;		
		m=len-1;
		x = n*n-1;
		for(i=0;i<n;i++)
		{
			m = x;
			for(j=0;j<n;j++)
			{	line1[len1++]=str[m];
				m=m-n;
			}
			x--;
			    
		}		
		line1[len1]='\0';
		//printf("line1 = %s\n",line1);
		if(strcmp(line1,str)!=0)
		{
				printf("No magic :(\n");
				continue;			
		}

		printf("%ld\n",n);






	
	
	}	

	return 0; 
}