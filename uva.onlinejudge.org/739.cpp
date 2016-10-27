#include<stdio.h>
#include<string.h>

void main()
{
 int i,j,m,p;
 char a[21],b[4];

 printf("%13s %32s\n","NAME","SOUNDEX CODE");

 //while(scanf(" %[^\n]",a)!=EOF) 
 while(scanf(" %s",a)!=EOF)
 {
	p=0;
	m=strlen(a);
	j=1;

	b[0]=a[0];
	for(i=1;i<=3;i++)
	 b[i]=48;

	for(i=0;i<m;i++)
	{

	 if(j==4)
	  break;

	 if(a[i]=='B'||a[i]=='P'||a[i]=='F'||a[i]=='V')
		{
		  if(p!=1 && p!=0)
		  { b[j]='1';
			 j++;
		  }
		  p=1;
		}
	 else if(a[i]=='C'||a[i]=='S'||a[i]=='K'||a[i]=='G'||a[i]=='J'||a[i]=='Q'||a[i]=='X'||a[i]=='Z')
		{
		  if(p!=2 && p!=0)
		  { b[j]='2';
			 j++;
		  }
		  p=2;
		}
	 else if(a[i]=='D'||a[i]=='T')
		{
		  if(p!=3 && p!=0)
		  { b[j]='3';
			 j++;
		  }
		  p=3;
		}
	 else if(a[i]=='L')
		{
		  if(p!=4 && p!=0)
		  { b[j]='4';
			 j++;
		  }
		  p=4;
		}
	 else if(a[i]=='M'||a[i]=='N')
		{
		  if(p!=5 && p!=0)
		  { b[j]='5';
			 j++;
		  }
		  p=5;
		}
	 else if(a[i]=='R')
		{
		  if(p!=6 && p!=0)
		  { b[j]='6';
			 j++;
		  }
		  p=6;
		}

	 else
		p=7;



	}    //END OF for loop

	printf("%10c",a[0]);
	for(i=1;i<m;i++)
	 printf("%c",a[i]);

	j= 24-m;

	for(i=0;i<=j;i++)
	 printf(" ");

	
	for(i=0;i<=3;i++)
	 printf("%c",b[i]);

   printf("\n");

  } //END OF while loop


  printf("%32s\n","END OF OUTPUT") ;



}
