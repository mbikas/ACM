//Acm 10110 Light more Light
//solved by Bikas CSE SUST

#include<stdio.h>
#include<math.h>
void main()
{ double m;
  long long int n;

  while(scanf("%lld",&n)==1&&n!=0)
  {  
     m=sqrt(n);   

     if(m==abs(m))
       printf("yes\n");
     else
       printf("no\n");
  }
}