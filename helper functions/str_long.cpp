#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>





void main()
{
  char *start,*end;
  long n;


  start=new char[50];

  while(scanf(" %[^\n]",start)==1)
  {
	  //Return starting integer to a
	  long a=atol(start);

	  /*Store Signed Integer*/

	  //Move past the no number char
	  while(*start && !isdigit(*start) && *start!='-')
		  start++;

	  if(*start)
	  {
		  //Store 1st integer to (n)
		  //Store remaining string to (end)
		  n=strtol(start,&end,10);
		  start=end;
		  printf("%ld",n);
	  }

	  //printf("%ld\na=%ld",n,a);

	}
 }

