					//Acm 10789 Prime Frequency
					//Solved by Bikas Cse Sust

#include<stdio.h>
#include<math.h>


int isPrime(int x);

void main()
{
  int i,T,ch[65],counter=1,p,n;
  char c;

  scanf("%d ",&T);

	while(T>0){

	p=0;

	for(i=0;i<=61;i++)
	  ch[i]=0;


	while( scanf("%c",&c)==1 ){

	  if(c=='\n')
		 break;

	  if(c>=48 && c<=57)
		 { n= (int)c-48;
			ch[n]++;
		 }

	  if(c>=65 && c<=90)
		 { n= (int)c-55;
			ch[n]++;
		 }

	  if(c>=97 && c<=122)
		 {  n= (int)c-61;
			 ch[n]++;
		 }

	 }

	printf("Case %d: ",counter);
	for(i=0;i<=61;i++)
	 {
		if( ch[i]!=0 && ( isPrime(ch[i])==1) )
		 {
			if(i<=9)
			 c=i+48;
			if(i>=10 && i<=35)
			 c=i+55;
			if(i>=36 && i<=61)
			  c=i+61;

			printf("%c",c);
			p=1;
		 }

	 }

	if(p!=1)
	 printf("empty");

	printf("\n");
	T--;
	counter++;



 }
}







// return 1 if prime else 0 otherwise
int isPrime(int x)
{
 int n,j;
 if(x==1)
  return 0;

 n=sqrt(x);
 for(j=2;j<=n;j++)
  {
	 if(x%j==0)
		return 0;
  }

	return 1;

}


