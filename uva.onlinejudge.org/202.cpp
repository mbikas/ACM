/* REAPEATING DECIMALS */

#include<stdio.h>

int lastdigit,m[10000],n,d,c,i,in,j,con[10000];

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
     while(scanf("%d %d",&n,&d)==2)
     {
		printf("%d/%d = ",n,d);
		if(n==0 && d!=0)
		{
			printf("0.0(0)\n");
			printf("   1 = number of digits in repeating cycle\n\n");
			continue;
		}
		printf("%d",n/d);
		n=n%d;
		in=c=0;
		m[c++]=n;
		printf(".");
		while(1)
		{
			if(n<d)
				n=n*10;
			con[in++]=n/d; 
			
			m[c++]=n=n%d;
			
			if(cheque())
			{
				for(j=0;j<in;j++)
				{
					if(j==i)
						printf("(");
					if(j==50)
					{
						printf("...)\n");
						break;
					}
					printf("%d",con[j]);
				}
				if(j<50)
					printf(")\n");
				break;
			}

			if(n==0)
			{				
				for(j=0;j<in;j++)
					printf("%d",con[j]);
				printf("(0)\n");
				printf("   1 = number of digits in repeating cycle\n\n");
				goto x;
			}
		}		
		printf("   %d = number of digits in repeating cycle\n\n",lastdigit);
     }
	 return 0;
 }
