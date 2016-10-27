#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

long string_long(char start[]);

void main()
{
  char start[50];
  long num;


  while(scanf(" %[^\n]",start)==1)
  {
	  num = string_long(start);	  
	  printf("%ld\n",num);

	}
 }

long string_long(char start[])
{

	char *end;
	long n;
	

	//Move past the no number char
	  while(*start && !isdigit(*start) && *start!='-')
		  start++;

	  if(*start)
	  {
		  //Store 1st integer to (n)
		  //Store remaining string to (end)
		  n=strtol(start,&end,10);
		  start=end;
		  //printf("%ld",n);
	  }

	  return n;
}


