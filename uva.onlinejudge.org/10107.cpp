
#define SIZE 10000
#include<stdio.h>
#include<math.h>

 int i=1;
 unsigned long a[SIZE];

 void sort_array(  unsigned long num );

void main()
{
  int p;
  double x;

  while( scanf("%lu", & a[i])==1){

	  i++;

	  sort_array(a[i-1]);

	  p=i-1;

	  if(p%2==0)
		 {
			p=i/2;
			x=  a[p];
			x=x+ a[p+1];
			x=x/2;
		 }

	  else
		 {
			p=(i+1)/2;
			x=a[p];
		 }

	  x = floor(x);
	  printf("%.0lf\n",x);


 }
}




 void sort_array( unsigned long num )
	{
		 int k,j;

		 for(j=0;j<i-1;j++){

			 if(a[j]>num)
				{
				  for(k=i-1;k>j;k--)
					  a[k]=a[k-1];

				  a[j]=num;
				  break;
				}
		  }

    }

