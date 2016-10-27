#include<stdio.h>
#include<math.h>

long d=0,x=0,y=0;


void extended_euclid(long a,long b){
  if(b==0){
    d=a;x=1;y=0;
  }  
  else{
    long tempX,tempY;
    extended_euclid(b,a%b);
    tempX=x;tempY=y;x=y;
    y=  (long)(tempX - floor ( double(a)/double(b)) * tempY);
  }
}

void main()

{
	long a,b;

	while(scanf("%ld %ld",&a,&b)==2)
	{
	
		extended_euclid(a,b);
		printf("%ld %ld %ld\n",x,y,d);
	
	
	}

}