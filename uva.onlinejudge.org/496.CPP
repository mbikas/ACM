             //Acm 496 Simply SubSet
				//Solved By Bikas CSE Sust

#include<stdio.h>
#include<string.h>
#define size 100

 void separating_int(char str[]);
 void separatingInt(char str[]);
 int m,n;
 long a[size],b[size];

 void main()
	{

	  char c[900],d[900];
	  int i,j,p;

	  while( scanf(" %[^\n] %[^\n]",c,d)==2)
		{

		  //seprateing A & B
		  ////////////////////
		  separating_int(c);
		  separatingInt(d);
		  /////////////////////

		  /////////////////////
		  /*
		  for(i=0;i<m;i++)
			printf("%ld ",a[i]);
			printf("\n");
         
		  for(i=0;i<n;i++)
			printf("%ld ",b[i]);
			printf("\n");
        */
		///////////////////////////

		//////////////////////////
		if(m>=n)
		{
		  for(i=0;i<n;i++)
		  { p=0;
			for(j=0;j<m;j++)
			{
			 if(a[j]==b[i])
			 {
			  a[j]=NULL;
			  p=1;
			 }
			 if(p==1)
			  b[i]=NULL;

			}
		  }
		 }
		///////////////////////////

		//////////////////////////
		else
		{
		  for(i=0;i<m;i++)
		  { p=0;
			for(j=0;j<n;j++)
			{
			 if(b[j]==a[i])
			 {
			  b[j]=NULL;
			  p=1;
			 }
			 if(p==1)
			  a[i]=NULL;

			}
		  }
		 }
		///////////////////////////


      /////////////////////
		 /*
		  for(i=0;i<m;i++)
			printf("%ld ",a[i]);
			printf("\n");

		  for(i=0;i<n;i++)
			printf("%ld ",b[i]);
			printf("\n");
       */
		///////////////////////////


     //doing Intersection
	  ////////////////////////////
		p=0;
		for(i=0;i<m;i++)
		{
		 if(a[i]!=NULL)
		  p++;
		}

		j=0;
		for(i=0;i<n;i++)
		{
		 if(b[i]!=NULL)
		  j++;
		}
	  ////////////////////////////

	  if( p==0 && j==0 )
		printf("A equals B\n");

	  else if(p==0 && j!=0)
		printf("A is a proper subset of B\n");

	  else if(j==0 && p!=0)
		printf("B is a proper subset of A\n");

	  else if(p==m && j==n)
		printf("A and B are disjoint\n");

	  else
		printf("I'm confused!\n");






	}
 }




 void separating_int(char str[])
 {
	  int p,x,i;
	  m=0;
	  char temp[15];
	  p=strlen(str);
	  str[p]=' ';

	  //separating A
	  /////////////////////////////////
	  x=0;
	  for(i=0;i<=p;i++)
		 {
			if(str[i]!=' ')
			 {
				temp[x]=str[i];
				x++;
			 }
			else
			 { while (str[i+1]==' ')i++;
				temp[x]=NULL;
				sscanf(temp,"%ld",&a[m]);
				m++;
				x=0;
			 }
		 }
		///////////////////////////////////////
 }



 void separatingInt(char str[])
 {
	  int p,x,i;
	  n=0;
	  char temp[15];
	  p=strlen(str);
	  str[p]=' ';

	  //separating A
	  /////////////////////////////////
	  x=0;
	  for(i=0;i<=p;i++)
		 {
			if(str[i]!=' ')
			 {
				temp[x]=str[i];
				x++;
			 }
			else
			 { while (str[i+1]==' ')i++;
				temp[x]=NULL;
				sscanf(temp,"%ld",&b[n]);
				n++;
				x=0;
			 }
		 }
		///////////////////////////////////////
 }
