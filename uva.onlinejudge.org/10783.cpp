//Acm 10783 Odd Sum
//solved by Bikas CSE SUST

#include<stdio.h>

void main()
{
 int testCase, i,j=1,m,n,temp;
 long sum;

 while(scanf("%d",&testCase)==1){

  while(testCase>0){

	 sum=0;
	 scanf("%d %d",&m,&n);

	 if(m>n)
	  { temp=m;
		 m=n;
		 n=temp;
	  }

	 printf("%d %d\n",m,n);


	 for(i=m;i<=n;i++)
	 {
	  if(i%2!=0)
		sum+=i;
	 }

	 printf("Case %d: %ld\n",j,sum);



	j++;
	testCase--;
  }
  j=1;
 }
}