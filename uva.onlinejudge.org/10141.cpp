#include<stdio.h>
#include<string.h>

typedef struct{
	char name[1000];
	double price;
	long req;
}NAME;
NAME names[1];

void main()
{
	long n,p,i,j,reqs,cases=1;
	double prices;
	char str[1000];
	int f=0;

	while(scanf("%ld %ld",&n,&p)==2 && ( n!=0 || p!=0) )
	{
		if(f==1)printf("\n");
		else f=1;

		names[0].req = 0;

		for(i=0;i<n;i++)
			scanf(" %[^\n]",str);

		

		for(i=0;i<p;i++)
		{
			scanf(" %[^\n]",str);
			scanf("%lf %ld",&prices,&reqs);

			////////////////////////////
			if(reqs>=names[0].req)
			{
				if(reqs>names[0].req)
				{
					strcpy(names[0].name,str);
					names[0].price = prices;
					names[0].req = reqs;					
				}
				
				
				///////////////////////////////
				else if(names[0].req==reqs)
				{
					if(prices<names[0].price)
					{ strcpy(names[0].name,str);
					  names[0].price = prices;
					  names[0].req = reqs;
					}
				}
				///////////////////////////////////
				
				
			}
			//////////////////////////////
			for(j=0;j<reqs;j++)
				scanf(" %[^\n]",str);
		}

		if(p)
		printf("RFP #%ld\n%s\n",cases++,names[0].name);	
	
	
	}
}
