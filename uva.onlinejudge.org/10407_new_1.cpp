#include<stdio.h>
#include<stdlib.h>

int comp(void const *A, void const *B);
long long  Gcd(long long a ,long long b) 
{ 
        if(b==0) 
                return a; 
        else 
             return Gcd(b,a%b); 
} 


void main()
{
	long long n,p,i,a[1005],gcd,first,x,total=0;

	while(scanf("%lld",&n)==1 && n!=0)
	{
		a[0] = n;
		total=1;
		while(scanf("%lld",&a[total])==1 && a[total]!=0)
		total++;		
		
		qsort(a,total,sizeof(a[0]),comp);
		
		first = a[0];
		p = 1;
		for(i=1;i<total;i++)
		{
			x = a[i] - first;
			if(p==1)gcd = x;
			else gcd = Gcd(gcd,x);			
			p=2;
		}
		printf("%lld\n",gcd);	
	
	}//while
}



int comp(void const *A, void const *B)
{

	long long *a = (long long*)A;
	long long *b = (long long*)B;
	long long p = *a-*b;
	
	if(p>0)
		return 1;
	if(p<0)
		return -1;
	return 0;

}