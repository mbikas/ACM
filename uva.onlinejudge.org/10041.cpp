#include<stdio.h> 
#include<stdlib.h>
 
 
int a[501],i,j,m,n,result; 

int compare (const void *A, const void *B) 
{ 
	int *a = (int*)A;
	int *b = (int*)B;

	return ( *a-*b ); 
} 

void main()
{ 
		scanf("%d",&n); 
		for(i=0;i<n;i++) 
		{ 
			result = 0; 
			
			scanf("%d",&m);
			for(j=0;j<m;j++) 
			scanf("%d",&a[j]);
			
			qsort (a,m, sizeof(int), compare); 
			
			for(j=0;j<m;j++) 
				result += (int)abs(double(a[j]-a[m/2])); 
			
			printf("%d\n",result); 
		} 

} 
