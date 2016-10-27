						//Acm10050 Hartals
						//Solved By Bikas Cse Sust

#include<stdio.h>

void main()
{
	int i,j,m,testCase,a[3651],n,p,x; //3651

	scanf("%d",&testCase);

	while(testCase>0){

	  scanf("%d",&n);

	  for(i=0;i<=n;i++)
		 a[i]=0;

	  scanf("%d",&p);

	  for(i=0;i<p;i++)
		{
			scanf("%d",&m);

			j=m;

			while(j<=n)
			  {
					if ( j%7 !=0 )
						a[j]=1;

					j=j+m;
			  }
		}


	  p=0;
	  j=6;
	  for(i=0;i<=n;i++)
	  {
		 if(a[i]!=0 && i!=j)
			p++;
		 if(i>j)
			j=j+7;
	  }

	  printf("%d\n",p);



     testCase--;
 }
}