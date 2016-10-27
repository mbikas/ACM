//10161 Ant on a chessboard
#include<stdio.h>
#include<math.h>

void main()
{
	long n,col,row,diag,root;

	while(scanf("%ld",&n)==1 && n)
	{
		root=ceil(sqrt(n));
		
		diag=root*root-root+1;
		//printf("%ld\n",diag);
		if(diag==n)
			row=col=root;
		else if(root%2==0)
		{
			if(n>diag)
			{
				row=root;
				col=root-(n-diag);
				
			}

			else
			{
				col=root;
				row=root-(diag-n);
			}
		}

		else
		{
			if(n>diag)
			{
				col=root;
				row=root-(n-diag);
			}

			else
			{
				row=root;
				col=root-(diag-n);
			}
		}

		printf("%ld %ld\n",row,col);
	}
	

}