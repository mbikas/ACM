#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<ctype.h>
#define true 1
#define false 0

#define MAX 1000

void seive(long limit);
long prime_num,prime[MAX+1];

void main()
{
    long i,limit;

	scanf("%ld",&limit);

	seive(limit);

	for(i=0;i<prime_num;i++)
	 printf("%ld ",prime[i]);

}


  //return prime from 0 to MAX
 void seive(long limit)
  {
	 long i,j;
	 int flag[MAX+1];

	 //memset(flag, true, sizeof(flag));
	 for(i=0;i<=limit;i++)
	 flag[i]=true;

	 for(i = 3; i*i <= limit; i += 2)
	  {  if(flag[i] == false)
			 continue;
		  for(j = i*i; j <= MAX; j += i)
			 flag[j] = false;
	  }
	 prime[0] = 2;
	 prime_num = 1;
	 for(i = 3; i <= limit; i += 2)
	  {  if(flag[i] == true)
			 prime[prime_num++] = i;
	  }
  }








