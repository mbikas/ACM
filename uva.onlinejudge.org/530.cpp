#include<stdio.h>
#include<math.h>


double nCr(long n,long m)
{
	long k;
	long i,j;
	double c,d;
	
	c=d=1;
	k=(m>(n-m))?m:(n-m);
	for(j=1,i=k+1;(i<=n);i++,j++)
	{	
		c*=i;
		d*=j;
		if( !fmod(c,d)  && (d!=1) )
		{	c/=d;
			d=1;
		}
	}

	return c;
}



void main()
{	
	long n,m;

	while(scanf("%ld %ld",&n,&m)==2 && (n!=0 || m!=0))
		printf("%.0lf\n",nCr(n,m));
	

}



 

