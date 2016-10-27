#include<stdio.h>
#define size 1000 //10000-2000000

void main()
{
 char a[size];

 int i,p;

 while(scanf(" %[^\n]",a)==1)
 {                                     

  p=-1;

  if(a[0]=='*')
	break;

  if( (a[0]>=48 && a[0]<=57) || a[0]=='+'||a[0]=='-')
	 { p=7;
		printf("%c",a[0]);
	 }
  else
    printf("%c",a[0]);



  for(i=1;a[i]!='\0';i++)
  {



	if( (a[i]>=48 && a[i]<=57) && (p==3||p==4) )
	  { p=4;
		 printf("%c",a[i]);
	  }

	else if( ((a[i]>=48 && a[i]<=57) || a[i]=='+'||a[i]=='-') && p==2 )
	 {
		if(a[i]=='+'||a[i]=='-')
		 p=3;
		else
		 p=4;
		printf("%c",a[i]);

	 }

	else if ( (a[i]=='e'||a[i]=='E') && (p==1||p==0 || i==1) )
	  { p=2;
		 printf("%c",a[i]);
	  }

	else if( (a[i]>=48 && a[i]<=57) && ( p==1||p==6) )
	  { p=1;
		 printf("%c",a[i]);
	  }

	else if(a[i]=='.' && ( p==0 || i==1 || p==4) )
	  {
		 if(p==4)
		  p=-1;
	    else
		  p=6;
		 printf("%c",a[i]);
	  }

	else if( (a[i]>=48 && a[i]<=57) && ( p==0 ||p==7) )
	  { p=0;
		 printf("%c",a[i]);
	  }
	else
	  { p=-1;
		 printf("%c",a[i]);
	  }
  }



  if(p==1 || p==4)
	printf(" is legal.\n");

	else
	  printf(" is illegal.\n");




 }


}