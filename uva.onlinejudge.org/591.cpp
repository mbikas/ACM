// Acm 591 Boxes of Bricks
// solved by Bikas CSE SUST
#include<stdio.h>
#define size 1000

void main()
{ int i,sum,a[size],p,avg,x=1;

  while(scanf("%d",&p)==1&&p!=0)
  {
    avg=0;             
    sum=0;

   for(i=0;i<p;i++)
     { scanf("%d",&a[i]);
       avg=avg+a[i];
     }

   avg=avg/p;

   for(i=0;i<p;i++)
    { if(a[i]>avg)
        sum+=a[i]-avg;
    }

   printf("Set #%d\nThe minimum number of moves is %d.\n\n",x,sum);
   x++;
  }


}



