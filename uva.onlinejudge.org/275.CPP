/* EXPANDING FRACTIONS */

#include<stdio.h>

int lastdigit,m[800000],n,d,c,i;

	 int cheque()
	 {
		 for(i=0;i<c;i++)
			if(m[i]==n)
				return lastdigit=c-i-1;
		return 0;		 
	 }

int main()
{
	 x:
     while((scanf("%d %d",&n,&d)==2)&&(n||d))
     {
		if(n==0 && d!=0)
		{
			printf("0\nThis expansion terminates.\n\n");  
			continue;
		}
		c=0;
		m[c++]=n;
		printf(".");
		while(1)
		{
			if(n<d)
				n=n*10;
			printf("%d",n/d); 
			
			m[c++]=n=n%d;
			
			if(cheque())
				break;
			if(c%50==0)
				printf("\n");
			if(n==0)
			{				
				printf("\nThis expansion terminates.\n\n");
				goto x;
			}
		}		
		printf("\nThe last %d digits repeat forever.\n\n",lastdigit);
     }
	 return 0;
 }
