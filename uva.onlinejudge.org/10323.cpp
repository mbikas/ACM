//Acm 10323 Factorial!  you must be kidding!!!
//solved by Bikas CSE SUST

#include<stdio.h>

void main()
{
	 int num,count1;
	 double fact;

	 while(scanf("%d",&num)==1){

		if(num<0)
		 {
			if( (-1*num)%2==0)
			  printf("Underflow!\n");
			else
			  printf("Overflow!\n");
		 }

		else
		 { fact=1;
			for(count1=2;count1<=num;count1++)
			 {  fact*=count1;
				  if(fact>6227020801.0)
					{
					  printf("Overflow!\n");
					  break;
					}
			 }

			if(fact<10000)
			  printf("Underflow!\n");

			else if(fact>=10000 && fact<=6227020801.0)
			  printf("%.0lf\n",fact);

		 }



  }
}
