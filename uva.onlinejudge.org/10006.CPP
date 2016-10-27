#include<stdio.h>

void main()
{
 long a[15]={561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973};
 long n;
 int i;

 while( scanf("%ld",&n)==1 && n!=0)
 {

	for(i=0;i<15;i++)
	 { if( a[i]==n)
		  { printf("The number %ld is a Carmichael number.\n",n);
			 i=20;
			 break;
		  }

	 }
	if(i!=20)
	 printf("%ld is normal.\n",n);

 }

}