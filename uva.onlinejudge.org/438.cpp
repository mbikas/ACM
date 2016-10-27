//Acm 438 Circumference of the Circle
//solved by Bikas CSE SUST

#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

void main()
{
  float a,b,c,d,e,f,h,k,radius;

  while(scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&f)==6){


  h= ( ((a*a-c*c+b*b-d*d)*(d-f)) - ((c*c-e*e+d*d-f*f)*(b-d)) ) / (( ((a-c)*(d-f)) - ((c-e)*(b-d)) )*2)  ;
  k= ( ((a*a-c*c+b*b-d*d)*(c-e)) - ((c*c-e*e+d*d-f*f)*(a-c)))/(( ((b-d)*(c-e)) - ((d-f)*(a-c)) )*2) ;


  radius=(sqrt)( (h-a)*(h-a) + (k-b)*(k-b) ) ;

  printf("%.2f\n",(2*radius*PI));

  //  c=(sqrt)( (h-a)*(h-a) + (k-b)*(k-b) ) ;
  //  printf("%.2f\n",(2*c*PI));
  //omit radius


 }
}
