//Acm 299 Train Swapping
//solved by Bikas CSE SUST

#include<stdio.h>
#define size 1000


void main()
{
  int i,m,n,temp,k,t,a[size],b[size];



  scanf("%d",&m);

  while(m>0)
	{ scanf("%d",&n);

	  for(i=0;i<n;i++)
	   scanf("%d",&a[i]);

	  t=0;
	  for(i=1;i<=n-1;i++)
		{ k=0;
			while(k<n-i)
			{ if(a[k]>a[k+1])
				  { temp=a[k];
					 a[k]=a[k+1];
					 a[k+1]=temp;
					 t++;

			}

			  k++;
			}

		}

	  printf("Optimal train swapping takes %d swaps.\n",b[i]);


	m--;
  }
}
