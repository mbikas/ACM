#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 

char a[10000000]; 

void main()
{ 

	int i,leap,ord,f=1,len; 
	while (	gets(a))
	{ 
		if (f) 
			f=0; 
		else 
			printf("\n");
		
		int mod4,mod100,mod400,mod15,mod55; 
		mod4=mod100=mod400=mod15=mod55=0; 
		ord=1;leap=0; 

		len = strlen(a);
		for (i=0;i<len;i++) 
		{ 
			mod4=(mod4*10+a[i]-'0')%4; 
			mod100=(mod100*10+a[i]-'0')%100; 
			mod400=(mod400*10+a[i]-'0')%400; 
			mod15=(mod15*10+a[i]-'0')%15; 
			mod55=(mod55*10+a[i]-'0')%55; 
		} 
		
		if ((!mod4 && mod100) || !mod400) 
		{ 
			leap=1; 
			ord=0; 
			printf("This is leap year.\n"); 
		}
		
		if (!mod15) 
		{ 
			ord=0; 
			printf("This is huluculu festival year.\n"); 
		} 
		if (leap && !mod55) 
		{ 
			ord=0; 
			printf("This is bulukulu festival year.\n"); 
		} 
		if (ord) 
			printf("This is an ordinary year.\n"); 

	} 
} 
