#include<stdio.h>
#include<string.h>


void main()
{

	//freopen("414.in","r",stdin);
	//freopen("414.out","w",stdout);

	int n,i,j,p,blank,min,blanks[15],total,step;
	char a[30];

	while(scanf("%d",&n)==1 && n!=0)
	{
	   	min=30;
		for(i=0;i<n;i++)
		{
			scanf(" %[^\n]",a);

			p = strlen(a);
			blank=0;
			for(j=0;j<p;j++)
			{
				if(a[j]==' ')blank++;
				//if(a[j]=='B')blank++;
			}

			step = blank/2;
			
			if(blank<min) min = blank;

			blanks[i] = blank;
			//printf("%s\n",a);
		
		
		}

		


		total=0;
		//for(i=0;i<n;i++)
		//printf("blank %d = %d\n",i,blanks[i]);

		step = min/2;
		for(i=0;i<n;i++)
		{				
				p  = blanks[i] - (step*2);
				if(p>0) total +=p;
		}	

		if(min%2!=0) 
		total = total - n;	
		

		

		printf("%d\n",total);


	
	
	}
}