#include<stdio.h>

long myPow( int base,int exp ) {
	long result( 1 );
	int bitMask( 1 );
	int currentPower( base );

	 for( bitMask = 1; bitMask <= exp; bitMask <<= 1 ) {
		  if( bitMask & exp ) {
				result *= currentPower; // multiple
		  }
		  currentPower *= currentPower; // square
	 }

	 return result;
}

void main()
{
		long p,q,r;

		p = myPow(2,3);
		printf("%ld\n",p);  

}