#include<stdio.h>
#define size 1001


void main()
{


  unsigned long a[size],temp; // use long
  int  n,i,k;
  long t;



	while( scanf("%d",&n)==1){

		for(i=0;i<n;i++)
			scanf("%lu",&a[i]);

		t=0;
		for(i=1;i<=n-1;i++)
		 { k=0;
			while(k<n-i)
			 { if(a[k]>a[k+1])
				{ temp=a[k];
				  a[k]=a[k+1];
				  a[k+1]=temp;
				  t++;
				}
				k++;
			 }

		 }

	 printf("Minimum exchange operations : %ld\n",t);


  }
}
