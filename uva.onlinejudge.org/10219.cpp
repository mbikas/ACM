#include<stdio.h>
#include<math.h>

void main()
{
	long n,r,i,n1,n2;
	double ans;

	while( scanf("%ld %ld",&n,&r)==2)
	{
		ans = 0.0;
		n1 = n;
		n2 = r;
		for(i=0;i<r;i++)
		{
			ans += (log10(n1) -  log10(n2));
			n1--;
			n2--;		
		}
		ans = (long)floor(ans);

		ans = ans +1;

		printf("%.0lf\n",ans);
	
	}


}