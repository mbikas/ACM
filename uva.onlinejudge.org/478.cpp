#include<stdio.h>
#include<math.h>


double area_triangle(double x,double y,double a1,double b1,double a2,double b2)
{
	return fabs(0.5*(x*(b1-b2)+a1*(b2-y)+a2*(y-b1)));

}

void main()
{
	double upperX[11],upperY[11],lowerX[11],lowerY[11],x0[11],y0[11],radius[11];
	double x1[11],y1[11],x2[11],y2[11],x3[11],y3[11];
	double x,y,a1,a2,a3,a4;
	char r[15];
	int i,j,z,point;

	
	i=0;
	while(scanf("%c",&r[i])==1) 
	{ 
		if(r[i]=='*') 
			break; 
		if(r[i]=='r') 
			scanf("%lf%lf%lf%lf%*c",&upperX[i],&upperY[i],&lowerX[i],&lowerY[i]); 
		else if(r[i]=='c') 
			scanf("%lf%lf%lf%*c",&x0[i],&y0[i],&radius[i]);
		else if(r[i]=='t')
			scanf("%lf%lf%lf%lf%lf%lf%*c",&x1[i],&y1[i],&x2[i],&y2[i],&x3[i],&y3[i]);
		i++; 
	} 






	point=1;
	while(scanf("%lf %lf",&x,&y)==2 )
	{
		if( (fabs(x-9999.9)<0.000001) && (fabs(y-9999.9)<0.000001) )
		break;
		
		z=0;
		for(j=0;j<i;j++)
		{ 
			if( (x>upperX[j] && x<lowerX[j]) &&  ( (y>upperY[j] && y<lowerY[j])||(y<upperY[j] && y>lowerY[j])) )
			 { printf("Point %d is contained in figure %d\n",point,j+1);
			   z=1;
			 }
			else if(  (  (x-x0[j])*(x-x0[j]) + (y-y0[j])*(y-y0[j]) ) < (radius[j]*radius[j]) )
			{ printf("Point %d is contained in figure %d\n",point,j+1);
			  z=1;
			}
			else if(r[j]=='t')
			{
				a1=area_triangle(x,y,x1[j],y1[j],x2[j],y2[j]);
				a2=area_triangle(x,y,x1[j],y1[j],x3[j],y3[j]);
				a3=area_triangle(x,y,x2[j],y2[j],x3[j],y3[j]);
				a4=area_triangle(x1[j],y1[j],x2[j],y2[j],x3[j],y3[j]);

				if(fabs(a4-(a1+a2+a3)) <= .000001)
				{
					printf("Point %ld is contained in figure %ld\n",point,j+1);
					z=1;
				}
			}

		 }
		


		if(z==0)
			printf("Point %d is not contained in any figure\n",point);
		point++;

 }

}