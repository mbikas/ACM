#include<stdio.h>
#include<stdlib.h>

#define sz 100


int comp(void const *A, void const *B);

void main()
 {	
	int n,i;
	char a[sz];
	
	while( scanf("%d",&n)==1)
	 {
		for(i=0;i<n;i++)
		scanf (" %c",&a[i]);

		qsort(a,n,sizeof(a[0]),comp);

		for(i=0;i<n;i++)
		printf("%c ",a[i]);

		printf("\n");
	 }

}




int comp(void const *A, void const *B)
{

	char *a = (char*)A;
	char *b = (char*)B;

	return *a - *b;

}