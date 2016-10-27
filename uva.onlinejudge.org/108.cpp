#include<stdio.h>
#define sz 102


long arr[sz][sz];

long max_sum(long n);


void main()
{
	long n,max,i,j;
	
	while(scanf("%ld",&n)==1)
	{
	
		for(i=1;i<=n;i++){
			arr[i][0]=0;
			for(j=1;j<=n;j++){
				scanf("%ld",&arr[i][j]);
				arr[i][j]+=arr[i][j-1];
			}
		}

		max = max_sum(n);

		printf("%ld\n",max);


	
	
	
	
	}


}




long max_sum(long n)
{
  long max,sum,i,j,k;
  max=0;
  for(k=1;k<=n;k++){
    for(i=k;i<=n;i++){
      sum=0;
      for(j=1;j<=n;j++){
          sum+=arr[j][i]-arr[j][k-1];
          if(sum<0 && sum<max)sum=0;
          else if(max<sum)max=sum;
      }
    }
  }

  return max;
  //printf("%ld\n",max);
}
