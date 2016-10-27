 						//Acm10013 Super long sums
						//Solved By Bikas Cse Sust

#include<stdio.h>
#define size 1000000

void main()
{

 long m,p,q,a[size],len,i,n;
 int testCase;

 scanf("%d",&testCase);

 while(testCase>0){

  scanf(" %ld",&m);
  len=0;

  while(m>0)
  {
	scanf("%ld %ld",&p,&q);

	a[len]=p+q;
	len++;

	m--;
  }

  

  for(i=len-1;i>0;i--)
  {
	n=a[i]/10;
	a[i]=a[i]%10;

	a[i-1]=a[i-1]+n;


 }


 for(i=0;i<len;i++)
  printf("%ld",a[i]);

  
  printf("\n\n");



  testCase--;
 }
}