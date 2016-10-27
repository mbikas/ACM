//855
#include<stdio.h>
#include<stdlib.h>
#define sz 50005


int comp(const void* A, const void* B)
{
	int *a=(int*)A;
	int *b=(int*)B;
	

	if(*a>*b)return 1;
	if(*a<*b)return -1;
	return 0;
}


int main()
{
	int test,i,S,F,A;
	int streets[sz],avenues[sz];

	scanf("%d",&test);

	while(test--)
	{
		scanf("%d %d %d",&S,&A,&F);
		for(i=0;i<F;i++)
		scanf("%d %d",&streets[i], &avenues[i]);

		qsort(streets,F,sizeof(streets[0]),comp);
		qsort(avenues,F,sizeof(avenues[0]),comp);

		if(F%2==0)i = F/2-1;
		else i = (F+1)/2 -1;

		printf("(Street: %d, Avenue: %d)\n",streets[i],avenues[i]);
	
	}

	return 0;
}
