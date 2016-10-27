#include<stdio.h>
#include<math.h>

void main()
{
	double temp;
	long row,col;

	long long p,diag,n;

	while(scanf("%lld",&p)==1 && p!=0)
	{
		temp = (double) sqrt(p);
		n = (long) ceil(temp);

		diag = n*n - n + 1;

		if(diag==p)
		{
			row = n;
			col =n;
		}

		else if(diag<p)
		{
			if(n%2!=0)
			{
				row = n;
				col = p - diag;
				col = n - col;
			}
			else
			{
				col = n;
				row = p-diag;
				row = n - row;			
			}
		}
		else if(diag>p)
		{
			if(n%2==0)
			{
				row = n;
				col = diag-p;
				col = n - col;
			}
			else
			{
				col = n;
				row = diag-p;
				row = n - row;			
			}
		}

		printf("%ld %ld\n",col,row);
	
	
	
	
	}



}