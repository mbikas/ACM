					//Acm 476 Points in Figures: Rectangles
               //Solved By Biaks CSE Sust
#include<stdio.h>

void main()
{
 double upperX[11],upperY[11],lowerX[11],lowerY[11];
 double x,y;
 char c;
 int i,p,n,z;

 p=1;
 while( scanf("%c",&c)==1  && c!='*')
 {
	scanf("%lf %lf %lf %lf ",&upperX[p],&upperY[p],&lowerX[p],&lowerY[p]);
	p++;

 }

 
 n=1;
 while(scanf("%lf %lf",&x,&y)==2 )
 {

	
  if( x==9999.9 && y==9999.9 )
	 break;

  z=0;
  for(i=1;i<p;i++)
	{ if( (x>upperX[i] && x<lowerX[i]) &&  ( (y>upperY[i] && y<lowerY[i])||(y<upperY[i] && y>lowerY[i])) )
		 { printf("Point %d is contained in figure %d\n",n,i);
			z=1;
		 }

	}

  if(z==0)
	printf("Point %d is not contained in any figure\n",n);
  n++;

 }





}