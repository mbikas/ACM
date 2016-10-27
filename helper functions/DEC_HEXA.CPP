#include<stdio.h>

 void decimal_hexadecimal(long p);

void main()
{
 long p;
 while( scanf("%ld",&p)==1)
 {
  decimal_hexadecimal(p);

 }
}

void decimal_hexadecimal(long p)
{ int x,i=0;
  char a[11];

  while(p>0)
  {
	x=(int)(p%16);

	if(x==15)a[i]='F';
	else if(x==14)a[i]='E';
	else if(x==13)a[i]='D';
	else if(x==12)a[i]='C';
	else if(x==11)a[i]='B';
	else if(x==10)a[i]='A';
	else a[i]=x+48;
	p=p/16;
	i++;
  }

  for(x=i-1;x>=0;x--)
	printf("%c",a[x]);

  printf("\n");


}
