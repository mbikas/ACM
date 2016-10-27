				//Acm 537  Artificial Intelligence? 
				//Solved By Bikas CSE Sust
#include<stdio.h>
#include<string.h>
#define size 1000 //32000

void main()
{
 double P,U,I;
 char a[size],b[20];
 int i,testCase,x,j,y,counter=1;
 //long x,i,j;

 scanf("%d",&testCase);
 while(testCase>0)
 {
  scanf(" %[^\n]",a);

  P=0;
  I=0;
  U=0;

  x=strlen(a);
  y=0;
  for(i=0;i<=x;i++)
  {

   // determining P & I  & U
	if(a[i]=='=')
	{ i++;
	  j=i-2;
	  while (  (a[i]>=48 && a[i]<=57) || a[i]=='.' )
		{
		 b[y]=a[i];
		 y++;
		 i++;

		}

	  //determining U=Voltage
	  //////////////////////////////////////////////////////////////////////////
	  if( ( a[i]=='V' || a[i]=='k'|| a[i]=='M' || a[i]=='m') && (a[j]=='U')  )
		{
			b[y]=NULL;
			if(a[i]=='V')
			 { sscanf(b,"%lf",&U);
				i++;
			 }
			else if(a[i]=='k')
			 {
				sscanf(b,"%lf",&U);
				i=i+2;
				U=1000*U;
			 }
			else if(a[i]=='M')
			 {
				sscanf(b,"%lf",&U);
				i=i+2;
				U=1000000*U;
			 }
			else if(a[i]=='m')
			 {
				sscanf(b,"%lf",&U);
				i=i+2;
				U=U/1000;
			 }
			y=0;
		 }
	  //////////////////////////////////////////////////////////////////////////


	  //determining I=Current
	  //////////////////////////////////////////////////////////////////////////
		else if( ( a[i]=='A' || a[i]=='k'|| a[i]=='M' || a[i]=='m') && (a[j]=='I')  )
		{
			b[y]=NULL;
			if(a[i]=='A')
			 { sscanf(b,"%lf",&I);
				i++;
			 }
			else if(a[i]=='k')
			 {
				sscanf(b,"%lf",&I);
				i=i+2;
				I=1000*I;
			 }
			else if(a[i]=='M')
			 {
				sscanf(b,"%lf",&I);
				i=i+2;
				I=1000000*I;
			 }
			else if(a[i]=='m')
			 {
				sscanf(b,"%lf",&I);
				i=i+2;
				I=I/1000;
			 }
			y=0;
		  }
		//////////////////////////////////////////////////////////////////////////


		//determining P=Power
		//////////////////////////////////////////////////////////////////////////
		else if( ( a[i]=='W' || a[i]=='k'|| a[i]=='M' || a[i]=='m') && (a[j]=='P')  )
		{
			b[y]=NULL;
			if(a[i]=='W')
			 { sscanf(b,"%lf",&P);
				i++;
			 }
			else if(a[i]=='k')
			 {
				sscanf(b,"%lf",&P);
				i=i+2;
				P=1000*P;
			 }
			else if(a[i]=='M')
			 {
				sscanf(b,"%lf",&P);
				i=i+2;
				P=1000000*P;
			 }
			else if(a[i]=='m')
			 {
				sscanf(b,"%lf",&P);
				i=i+2;
				P=P/1000;
			 }
			y=0;
		  }
		 //////////////////////////////////////////////////////////////////////////

	}

  }// inner for

 //printf("%f %f\n",U,I);

  //////////////////////////////////
  printf("Problem #%d\n",counter);
  if(P==0)
	printf("P=%.2lfW\n\n",U*I);

  if(U==0)
	printf("U=%.2lfV\n\n",P/I);

  if(I==0)
	printf("I=%.2lfA\n\n",P/U);
  //////////////////////////////////



	counter++;
	testCase--;
  }
}

