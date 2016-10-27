#include<stdio.h>
#include<math.h>


int GCD(int a,int b);

void main()
{
	int n,i,tot,nocommonfactor,ct1,ct2;
	int arr[55];

	double ans; 


	while(scanf("%d",&n)==1 && n!=0)
	{

		for(i=0;i<n;i++)
		scanf("%d",&arr[i]);


		tot=0;
		nocommonfactor=0;
		for (ct1=0; ct1<=n-2 ;ct1++)
		for (ct2=ct1+1 ;ct2<= n-1 ;ct2++)
		{	tot++;
			if (  GCD(arr[ct1],arr[ct2])==1 )
				nocommonfactor++;		
	
		}

		//printf("total = %d   noCommon=%d\n",tot,nocommonfactor);


		if(nocommonfactor==0)
			printf("No estimate for this data set.\n");
		else
		{
			ans = sqrt((6.0/ (double)nocommonfactor)* (double)tot);
			printf("%.6lf\n",ans);
		}




	
	}

}


int GCD(int a,int b)
 {
		while( b > 0)
		 {
			a = a%b;
			a = a+b;
			b = a-b;
			a = a-b;
		 }
	return a;
 }