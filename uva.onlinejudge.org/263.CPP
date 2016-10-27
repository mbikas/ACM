#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define swap(a,b) a^=b^=a^=b


/////////increase if problem/////////////
#define sz 30000
//////////////////////////////////

void reverse(char x[]);
int comp(void const *A, void const *B);
int check_chain(long n);
long ct=0;

typedef struct{
	long num;
	}number;
number numbers[sz];


void main()
{
	char num1[15],num2[15];
	long n,n1,n2,p;
        int len,i;



 while(  scanf("%ld",&n)==1 && n!=0)
 {

	p=0;
        ct=0;

	printf("Original number was %ld\n",n);

	while(p!=1)
	{
        	sprintf(num2,"%ld",n);
                len = strlen(num2);

                qsort(num2,len,sizeof(num2[0]),comp);
        	strcpy(num1,num2);
        	reverse(num2);
	
		sscanf(num1,"%ld",&n1);
		sscanf(num2,"%ld",&n2);
		//printf("%ld %ld\n",n1,n2);

		n = n2-n1;

		printf("%ld - %ld = %ld\n",n2,n1,n);
		p = check_chain(n);
		numbers[ct].num = n;
                ct++;                

	}

	printf("Chain length %ld\n\n",ct);


 }

}


int check_chain(long n)
{
	long i;
	for(i=0;i<ct;i++)
	{
		if(numbers[i].num==n)
                return 1;
	}

        return 0;

}


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}


int comp(void const *A, void const *B)
{

	char *a = (char*)A;
	char *b = (char*)B;

	return *a - *b;

}

