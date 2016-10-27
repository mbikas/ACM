//Acm 190 Circle through Three Points
//solved by Bikas CSE SUST

#include<stdio.h>
#include<math.h>
void main()
{
  float a,b,c,d,e,f,h,k,x,radius;

  while( scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&f)==6){

  h= ( ((a*a-c*c+b*b-d*d)*(d-f)) - ((c*c-e*e+d*d-f*f)*(b-d)) ) / (( ((a-c)*(d-f)) - ((c-e)*(b-d)) )*2)  ;
  k= ( ((a*a-c*c+b*b-d*d)*(c-e)) - ((c*c-e*e+d*d-f*f)*(a-c)))/(( ((b-d)*(c-e)) - ((d-f)*(a-c)) )*2) ;

  radius=(sqrt)( (h-a)*(h-a) + (k-b)*(k-b) ) ;

  if( (h>0&&k>0) || (h==0&&k==0) )
	 printf("(x - %.3f)^2 + (y - %.3f)^2 = %.3f^2\n",h,k,radius);

  if(h>0&&k<0)
	 printf("(x - %.3f)^2 + (y + %.3f)^2 = %.3f^2\n",h,(-1*k),radius);

  if(h<0&&k>0)
	 printf("(x + %.3f)^2 + (y - %.3f)^2 = %.3f^2\n",(-1*h),k,radius);

  if(h<0&&k<0)
	 printf("(x + %.3f)^2 + (y + %.3f)^2 = %.3f^2\n",(-1*h),(-1*k),radius);




  x=h*h+k*k-radius*radius;

  if(x>=0)
  {
  if(h>0&&k>0)
  printf("x^2 + y^2 - %.3fx - %.3fy + %.3f = 0\n",(2*h),(2*k),x);


  if((h<0&&k<0) || (h==0&&k==0) )
  printf("x^2 + y^2 + %.3fx + %.3fy + %.3f = 0\n",(-2*h),(-2*k),x);


  if(h>0&&k<0)
  printf("x^2 + y^2 - %.3fx + %.3fy + %.3f = 0\n",(2*h),(-2*k),x);


  if(h<0&&k>0)
  printf("x^2 + y^2 + %.3fx - %.3fy + %.3f = 0\n",(-2*h),(2*k),x);
 }

 if(x<0)
  {
  if(h>0&&k>0)
  printf("x^2 + y^2 - %.3fx - %.3fy - %.3f = 0\n",(2*h),(2*k),(-1*x));


  if((h<0&&k<0) || (h==0&&k==0) )
  printf("x^2 + y^2 + %.3fx + %.3fy - %.3f = 0\n",(-2*h),(-2*k),(-1*x));


  if(h>0&&k<0)
  printf("x^2 + y^2 - %.3fx + %.3fy - %.3f = 0\n",(2*h),(-2*k),(-1*x));


  if(h<0&&k>0)
  printf("x^2 + y^2 + %.3fx - %.3fy - %.3f = 0\n",(-2*h),(2*k),(-1*x));
 }

 printf("\n");

}



}
