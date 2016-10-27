#include<stdio.h>

void main()
{

 int stan,p;

 double n;

 while(scanf("%lf",&n)==1)
 {
	p=0;
	stan=1;
	while(n>1)
	{
		if(p==0)
		{ n=n/9;
		  stan=1;
		  p=1;
		}
		else
		{ n=n/2;
		  stan=0;
		  p=0;
		}
	}

	if(stan==1)
	 printf("Stan wins.\n");
	else
	 printf("Ollie wins.\n");


 }





}