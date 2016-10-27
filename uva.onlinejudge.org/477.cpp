#include<stdio.h>

void main()
{
 double upperX[11],upperY[11],lowerX[11],lowerY[11],x0[11],y0[11],radius[11];
 double x,y;
 char c;
 int i,p,q,n,z,a[11],b[11];

 p=1;
 q=1;
 i=1;

 n=1;

 while( scanf("%c",&c)==1  && c!='*')
 {
	if(c=='r')
	{ scanf("%lf %lf %lf %lf ",&upperX[p],&upperY[p],&lowerX[p],&lowerY[p]);
	  a[p]=n;
	  p++;
	}
	else if(c=='c')
	{
	  scanf("%lf %lf %lf ",&x0[q],&y0[q],&radius[q]);
	  b[q]=n;
	  q++;


	}

	n++;
 }





 n=1;
 while(scanf("%lf %lf",&x,&y)==2 )
 {


  if( x==9999.9 && y==9999.9 )
	 break;



		z=0;
		for(i=1;i<p;i++)
		 { if( (x>upperX[i] && x<lowerX[i]) &&  ( (y>upperY[i] && y<lowerY[i])||(y<upperY[i] && y>lowerY[i])) )
			 { printf("Point %d is contained in figure %d\n",n,a[i]);
				z=1;
			 }

		 }


		for(i=1;i<q;i++)
		  {    if(  (  (x-x0[i])*(x-x0[i]) + (y-y0[i])*(y-y0[i]) ) < (radius[i]*radius[i]) )
				  { printf("Point %d is contained in figure %d\n",n,b[i]);
					 z=1;
				  }
		 }


  if(z==0)
	printf("Point %d is not contained in any figure\n",n);
	n++;

 }

}