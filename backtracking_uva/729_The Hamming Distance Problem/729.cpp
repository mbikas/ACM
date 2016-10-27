#include<stdio.h>
#include<string.h>
#define MAX 18

int total_zero,total_one;
void backtrack(char a[],int k,int n,int one,int zero);
void con_candidate(char a[],int k,int n,char c[],int one,int zero,int *ncan);

void main()
{
	int test,N,H;
	char a[MAX];
	bool blank=false;

	scanf("%d",&test);

	while(test--)
	{
		if(blank)printf("\n");
		else blank = true;
		scanf("%d %d",&N,&H);		
		memset(a,0,sizeof(a));
		total_one = H;
		total_zero = N-H;
		backtrack(a,0,N,0,0);
	}

}

void backtrack(char a[],int k,int n,int one,int zero)
{
	int i,ncan,one1,zero1;
	char c[MAX];
	bool One;

	if(k==n)
	{
		for(i=1;i<=k;i++)printf("%c",a[i]);
		printf("\n");
	}
	else
	{
		k++;
		con_candidate(a,k,n,c,one,zero,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			One = true;
			if(a[k]=='1')one = one +1;
			else {
				zero = zero+1;
				One = false;
			}
			backtrack(a,k,n,one,zero);
			if(One)one--;
			else zero--;

		
		}
	
	}
}

void con_candidate(char a[],int k,int n,char c[],int one,int zero,int *ncan)
{
	*ncan = 0;

	if(zero<total_zero)
		c[(*ncan)++] = '0';
	if(one<total_one)
		c[(*ncan)++] = '1';


}