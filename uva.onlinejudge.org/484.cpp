#include<stdio.h>

void check_digit(long n);

typedef struct{
  long num;
  int occur;
}number;
number numbers[7500];
long m=0;

void main()
{
	//freopen("484.in","r",stdin);
	//freopen("484.out","w",stdout);
	long i,n;

	while(scanf("%d",&n)==1)
	{
		check_digit(n);

	
		
	}
	
	  
	  for(i=0;i<m;i++)
	  printf("%ld %d\n",numbers[i].num,numbers[i].occur);

	

}



 void check_digit(long n)
 {
		long i;
		for(i=0;i<m;i++)
		{
			if( numbers[i].num==n)
			{
				numbers[i].occur++;
				return;
			}
		}
      

		numbers[m].num = n;
		numbers[m].occur=1;
		m++;
		return;


 }