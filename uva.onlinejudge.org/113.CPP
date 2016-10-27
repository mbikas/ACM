//Acm 113 Power of Cryptography
//solved by Bikas CSE SUST
#include<stdio.h>
#include<math.h>
void main()
{
 long double m,n,p;
 while(scanf("%Lf %Lf",&m,&n)==2)

  {
 m=1/m;
 p=pow(n,m);

 printf("%.0Lf\n",p);
   }

}