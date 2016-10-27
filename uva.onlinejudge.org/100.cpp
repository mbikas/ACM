#include<stdio.h>
#include<time.h>
void main()
{
	 long int i,n,max,m,p,temp,x,y,j;
	 time_t start,end;


	while(scanf("%ld",&m) && scanf("%ld",&n)==1)
	{ time(&start);
	  max=1;
	  x=m,y=n;

	if(m>n)
	{ temp=m;
	  m=n;
	  n=temp;
	}

  for(i=m;i<=n;i++)

	 { j=i;

		p=1;
	  if(j%2!=0)
			 {
	 while(j!=1&&j!=0)
		{
		 if(j%2==0)
		  {j=j/2;
			p++;

		  }
		 else
		  {j=3*j+1;
			p++;
		  }

			}
	  }

	  if(max<p)
		max=p;
  }
	time(&end);
	printf("%ld %ld %ld\ntime %.0lf sec\n",x,y,max,difftime(end, start));

 }


}
















