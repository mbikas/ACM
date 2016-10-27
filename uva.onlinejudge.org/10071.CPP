//Acm 10071 Back to High School Physics
//solved by Bikas CSE SUST

#include<stdio.h>
void main()
{
  long int m,n;

  while((scanf("%ld %ld",&m,&n)==2)&&m>=-100&&m<=200&&n>=0&&n<=200)
    printf("%ld\n",(2*(m*n)));
    

}