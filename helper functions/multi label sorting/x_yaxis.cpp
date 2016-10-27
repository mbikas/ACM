/*	implementation of qsort 
   	based on multilable sorting 

    sort based on point of x-axis
	if x-coordinates are same then sort y -coordinates 


    
*/ 



#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


typedef struct{
	
	int x;
	int y;
}point;

point points[50];
int npoints;


void read_points()
{
  npoints = 0;

  while( scanf("%d %d",&points[npoints].x,&points[npoints].y) !=EOF)
  npoints++;
  
}


int comp(const void* A, const void* B)
{
	point *a=(point*)A;
	point *b=(point*)B;
	
	
	if(a->x < b->x) return(-1);
	if(a->x > b->x) return(1);

	if(a->x == b->x)
	{
		if(a->y < b->y) return(-1);
		if(a->y > b->y) return(1);	
	
	}	
	
    return (0);

}




void main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);

	int	 i;

	

	read_points();

	printf("---------------------------------\n");
	for(i=0;i<npoints;i++)
	printf("%d %d\n",points[i].x,points[i].y);

	printf("---------------------------------\n");

	
	qsort(points,npoints,sizeof(point),comp);

	for(i=0;i<npoints;i++)
	printf("%d %d\n",points[i].x,points[i].y);


}