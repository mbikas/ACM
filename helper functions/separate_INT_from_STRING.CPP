#include<stdio.h>
#include<string.h>
#define size 100

 void separating_int(char a[]);
 int m=0;
 long num[size];

 void main()
	{

	  char a[900];
     int i;

	  while( scanf(" %[^\n]",a)==1)
		{

		  separating_int(a);

		  for(i=0;i<m;i++)
			 printf("%ld ",num[i]);
		  printf("\n");

	}
 }




 void separating_int(char a[])
 {
	  int p,x,i;
	  char temp[15];
     m=0;
	  p=strlen(a);
	  a[p]=' ';

	  //separating A
	  /////////////////////////////////
	  x=0;
	  for(i=0;i<=p;i++)
		 {
			if(a[i]!=' ')
			 {
				temp[x]=a[i];
				x++;
			 }
			else
			 { while (a[i+1]==' ')i++;
				temp[x]=NULL;
				sscanf(temp,"%ld",&num[m]);
				m++;
				x=0;
			 }
		 }
		///////////////////////////////////////
 }
