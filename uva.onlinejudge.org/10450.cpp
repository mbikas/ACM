#include<stdio.h>

void main()
{
 int counter=1,n,num,i;

 double x,y,z;

 scanf("%d",&num);

 while(num>0)
 {
	scanf("%d",&n);
	x=1;
	y=1;
   z=0;

	for(i=0;i<n;i++)
	 {
	  z=x+y;
	  x=y;
	  y=z;
	 }

	printf("Scenario #%d:\n%.0lf\n\n",counter,z);

   counter++;
	num--;
 }
}
