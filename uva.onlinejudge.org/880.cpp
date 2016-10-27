#include<stdio.h>
#include<math.h>




void main()
{

 long long n,x,y,p,q;


 while(scanf("%lld",&n)==1)
 {

	 

	 x = (long long) ((sqrt(1+8*n)-1)/2); 
     y = x*(x+1)/2; 
    
	 if (y == n) 
	 {  

		printf("1/%lld\n",x);
	 }
     else 
	 {
		 p = (x + 1)-(n-y)+1;
		 q = 1+(n-y)-1;

		 printf("%lld/%lld\n",p,q);

	 }

  

 }
}



