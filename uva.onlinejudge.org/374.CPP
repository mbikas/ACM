#include<stdio.h>
#include<math.h>

unsigned long bigmod(unsigned long b,unsigned long p,unsigned long m) ;

void main()
{
  unsigned long b,p,m;  // long long int

  while(scanf(" %lu %lu %lu",&b,&p,&m)==3)
  {
	b=bigmod(b,p,m);
	printf("%lu\n",b);

  }
}





unsigned long bigmod(unsigned long b,unsigned long p,unsigned long m) {

	unsigned long a;
   if (p == 0) 
      return 1; 
   if (p%2 == 0){ 
      a = bigmod(b,p/2,m); 
      return (a*a) % m; 
	 }
	else
	 return ((b % m) * bigmod(b,p-1,m)) % m;

}