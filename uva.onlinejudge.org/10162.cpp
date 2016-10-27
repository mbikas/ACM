#include<stdio.h>
#include<string.h>
#include<math.h>


void main()
{
	char str[120];
	long len,i,x,y,sum,ans;
	long even[9]={1,4,7,6,5,6,3,6,9};
	long odd[9]={1,6,3,6,5,6,7,4,9};


	while(scanf(" %[^\n]",str)==1 &&  (strcmp(str,"0"))   )
	{
		len = strlen(str);

		x=(long)str[len-1]-'0';
		y=0;
		
		if(len>1)
			y=(long)str[len-2]-'0';

		sum=0;
		
		for(i=0;i<y;i++)
			sum+=47;

		if(y%2==0)
		{	
			for(i=0;i<x;i++)
				sum+=even[i];
		}
		else
		{	
			for(i=0;i<x;i++)
				sum+=odd[i];
		}

		ans=sum%10;

		printf("%ld\n",ans);
	}
}


