#include<stdio.h>
#include<stdlib.h>

#define sz 1000

int comp(void const *A, void const *B);

int main()
 {	
	int n,i,test,cases=1,tot,money;
	int a[sz];
	bool ok;
	
	long sum;

	scanf("%d",&test);
	while(test--)
	{	
		scanf("%d %d",&money,&n);
		
		for(i=0;i<n;i++)
		
			scanf ("%d",&a[i]);

			 
			
			sum=0;
			tot=0;	
			ok = false;
			for(i=0;i<n;i++)
			{
				sum +=a[i];
				tot++;
				if(sum>=money)
				{
					ok=true;
					break;
				}
			}
			printf("Scenario #%d:\n",cases++);
			if(ok)printf("%d\n\n",tot);
			else printf("impossible\n\n");
	
	}
	return 0;
}




int comp(void const *A, void const *B)
{

	long *a = (long*)A;
	long *b = (long*)B;


	long p = *a-*b;
	
	if(p>0)
		return -1;
	if(p<0)
		return 1;
	return 0;

}