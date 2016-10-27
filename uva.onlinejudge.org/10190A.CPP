#include<stdio.h>
#define size 1000  // 10000- 100000

void main()
{
 unsigned long m,n,a[size];
 int i,p;

  //long i,p;



 while(scanf("%lu %lu",&m,&n)==2)
 {

	p=0;
	a[p]=m;
	p++;
	if(n==1)
	 printf("%lu %lu\n",m,n);

	else if(n>m || n==0)
	 printf("Boring!\n");


	else{

	  while(m>n&&n!=1){
		  m=m/n;
		  if(a[p-1]%n!=0)
			{ printf("Boring!");
			  p=0;
			  break;
			}
		  else{
			  a[p]=m;
			  p++;
			}
		}

	  if(p>0){
		 a[p]=1;
		 p++;
		 for(i=0;i<p;i++)
		  printf("%lu ",a[i]);
	  }

	 printf("\n");
	}
  }
 }
