/*160 FACTORS AND FACTORIALS 51274ME BISHNU PADA CHANDA 13-3-2005*/
#include<stdio.h>
void main()

{

  int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  int n,count,p,num,i;


  while(scanf("%d",&num)==1 && num!=0){

		printf("%3d! =",num);

		for(i=0;i<25;i++)
		{
		  count=0;
		  if(prime[i]>num)
			 break;
		  for(p=2;p<=num;p++)
			{
			  n=p;

			  while(n%prime[i]==0&&n!=0)
			  {
				 count++;
				 n=n/prime[i];
			  }
			}
		 if(i==15)printf("\n      ");
			printf("%3d",count);

		}

		printf("\n");




  }
}
