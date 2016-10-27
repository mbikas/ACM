#include<stdio.h>
#include<math.h>

typedef struct{
	char a;
	double x;
	double y;
}POINT;
POINT point[17];

double area_triangle(double x,double y,double a1,double b1,double a2,double b2)
{
	return fabs(0.5*(x*(b1-b2)+a1*(b2-y)+a2*(y-b1)));

}

void main()
{
	double a1,a2,a3,a4,max;	
	int i,j,k,l,n,f;
	char c1,c2,c3;

	
	
	while( scanf("%d",&n)==1 &&n!=0) 
	{ 

		for(i=0;i<n;i++)
			scanf(" %c %lf %lf",&point[i].a,&point[i].x,&point[i].y);

		max=0.0;

		for(i=0;i<n;i++)
		{	for(j=i+1;j<n;j++)
			{	for(k=j+1;k<n;k++)
				{
					a4 = area_triangle(point[i].x,point[i].y,point[j].x,point[j].y,point[k].x,point[k].y);
					//printf("%c %c %c %lf\n",point[i].a,point[j].a,point[k].a,a4);
					if(a4>max)
					//if(fabs(a4-max)>0.000001)
					{		f=1;
							for(l=0;l<n;l++)
							{
								if(l!=i && l!=j && l!=k)
								{
							
									a1=area_triangle(point[i].x,point[i].y,point[j].x,point[j].y,point[l].x,point[l].y);
									a2=area_triangle(point[i].x,point[i].y,point[k].x,point[k].y,point[l].x,point[l].y);
									a3=area_triangle(point[j].x,point[j].y,point[k].x,point[k].y,point[l].x,point[l].y);
							
									if(fabs(a4-(a1+a2+a3)) <= .000001)
									{
										f=0;
										break;
									}
				
								}
						
							}//1

							if(f==1)
							{
								max = a4;
								c1=point[i].a;
								c2=point[j].a;
								c3=point[k].a;
							}
					
					
					}
				
		
				}//2		
			}//3		
		}//4


		printf("%c%c%c\n",c1,c2,c3);
		


	
	}//while
}//main

