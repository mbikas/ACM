//Acm 694 Collatz Sequence
//solved by Bikas CSE SUST 
#include<stdio.h>
void main()
{    long long int m,n,p,x,j;

	j=1;
	while((scanf("%lld %lld",&m,&x)==2)&&m>0&&x>0)
   {
    
	 p=1;
   if(m==1||m==0)
     p=0;
    
    n=m;
    while(n!=1&&n!=0)
      { if(n>x)
         { p--;
	   break;
         }
      
       if(n%2==0)
	{n=n/2;
         p++;
         
        }
       else 
	{n=3*n+1;
	 p++;
        }
      } 


     
     
      

	printf("case %lld: A = %lld, limit = %lld, number of terms = %lld\n",j,m,x,p);
	j++;
 }


}
















