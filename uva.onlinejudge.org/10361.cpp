#include<stdio.h>
#include<string.h>
//#define size 101

void main()
{
 int i,testCase,s2len,s3len,s4len,s5len,p,x1,x2,x3,x4;
  char a[101],s2[101],s3[101],s4[101],s5[101];


  while(scanf("%d",&testCase)==1){

	 while(testCase>0){

	 scanf(" %[^\n]",a);

	 s2len=s3len=s4len=s5len=0;

	 //printing the 1st line
	  p=0;
	 for(i=0;a[i]!='\0';i++)
	 {
		 if(a[i]!='<' && a[i]!='>')
			printf("%c",a[i]);

		 if(a[i]=='<' && p==0)
		 { x1=i;
			p=1;
		 }

		 if(a[i]=='>' && p==1)
		 { x2=i;
			p=2;
		 }
		 if(a[i]=='<' && p==2)
		 { x3=i;
			p=3;
		 }

		 if(a[i]=='>' && p==3)
		 { x4=i;
			p=4;
		 }


	 }
	 printf("\n");


	 //////////////////////////////////////
	 //  taking s2 s3 s4 s5

	 for(i=x1+1;i<x2;i++)
	 {
	  s2[s2len]=a[i];
	  s2len++;
	 }

	 for(i=x2+1;i<x3;i++)
	 {
	  s3[s3len]=a[i];
	  s3len++;
	 }

	 for(i=x3+1;i<x4;i++)
	 {
	  s4[s4len]=a[i];
	  s4len++;
	 }

	 for(i=x4+1;a[i]!='\0';i++)
	 {
	  s5[s5len]=a[i];
	  s5len++;
	 }
	 //////////////////////////////////////

	 scanf(" %[^\n]",a);

	 p=1;
	 for(i=0;a[i]!='\0';i++)
	 {
	  if(a[i]!='.')
		{ printf("%c",a[i]);
		  if(p>1)
			p=1;
		}

	  if(a[i]=='.')
		 {
		 p++;
		 }

	  if(p==4)
		 break;

	}

	for(i=0;i<s4len;i++)
	 printf("%c",s4[i]);
	
	for(i=0;i<s3len;i++)
	 printf("%c",s3[i]);

	for(i=0;i<s2len;i++)
	 printf("%c",s2[i]);

  for(i=0;i<s5len;i++)
	 printf("%c",s5[i]);


   printf("\n");






  testCase--;
  }
 }
}