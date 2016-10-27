//Acm 10055 Hasmat the brave Warrior
//solved by Bikas CSE SUST

#include<stdio.h>
void main()
{ long double m,n;

  while(scanf("%Lf %Lf",&m,&n)==2)
  
  {
   if(m>n)
        printf("%.0Lf\n",m-n);
   else  
	printf("%.0Lf\n",n-m);
  }
}