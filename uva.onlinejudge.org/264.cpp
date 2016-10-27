					  //Acm264 Count on Canton
					  //Solved By Bikas Cse Sust

#include<stdio.h>

void main()
{

 long n,p,m,i;


 while(scanf("%ld",&n)==1)
 {

  for(i=1;i<=n;i++)
  {
	p=m;
	if(i%2==0)
	 m=(i/2)*(i+1);
	else
	 m=((i+1)/2)*i;

	if(m>=n)
	  break;
  }


	if(n==1)
	 printf("TERM %ld IS 1/1\n",n);

	else
	 {
     p=n-p;
	  m=i+1-p;

	  if(i%2==0)
		 printf("TERM %ld IS %ld/%ld\n",n,p,m);


	  else
		 printf("TERM %ld IS %ld/%ld\n",n,m,p);

	 }


 }
}
