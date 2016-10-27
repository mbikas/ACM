//Acm 10038 Jolly Jumper
//solved by Bikas CSE SUST
#include<stdio.h>
#define size 5000

void main()
{   
  int a[size],x[size],p,i,m,n;   
  while(scanf("%d",&n)==1)
   
   {
     for(i=0;i<n;i++)
     scanf("%d",&x[i]);
	a[0]=1;
   
      for(i=1;i<n;i++)
       a[i]=0;

      for(i=0;i<n-1;i++)
      { m=x[i+1]-x[i];

        if(m>=0)       
         a[m]=1;
	else
         { m=m*-1;
	   a[m]=1;
         }
      }

     p=0;
     for(i=0;i<n;i++)
     {if(a[i]!=1)
      {p=1;
       break;
      }
     }

     if(p==1)
      printf("Not jolly\n");
     else
      printf("Jolly\n");
   }
  
   
}

