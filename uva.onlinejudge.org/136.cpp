#include<stdio.h>
#include<math.h>
#define max 1000000000
   	void main()
	{
	double ugly[1900];
	
	double  l,temp;
	int n=0,i,j,k,z,m;
	for(i=0;i<14;i++)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<33;k++)
			{
					l=pow(2,k)*pow(3,j)*pow(5,i);
					ugly[n++]=l;
					if(ugly[n-1]>max)k=33;
			}
		}
	}
	z=n;
	for(i=z;i>0;i--){
	for(j=0;j<i;j++){
	if(ugly[j]>ugly[j+1]){
	temp=ugly[j];
	ugly[j]=ugly[j+1];
	ugly[j+1]=temp;
	}
	}
	}
	printf("The 1500'th ugly number is %.0lf.",ugly[1500]);
	}
