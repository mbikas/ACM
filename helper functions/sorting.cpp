#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define sz 15

char str[sz][sz];

int comp(const void* a, const void* b);

void main()
{
 long i,n;

 while(scanf("%ld",&n)==1)
 {
  for(i=0;i<n;i++)scanf(" %s",str[i]);

  qsort(str,n,sizeof(str[0]),comp);

  for(i=0;i<n;i++)printf("%s ",str[i]);
  printf("\n");


 }


}


int comp(const void* a, const void* b)
{
 char*A=(char*)a;
 char*B=(char*)b;
 long lena=strlen(A),flag;
 long lenb=strlen(B);

 if( (A[0]=='-')^(B[0]=='-'))return A[0]-B[0];

 if(lena!=lenb)flag=lena-lenb;

 else flag=strcmp(A,B);

 if(A[0]=='-')flag*=-1;

 return flag;


}
