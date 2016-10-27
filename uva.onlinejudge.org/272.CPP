//Acm 272 Tex Quotes
//solved by Bikas CSE SUST
#include<stdio.h>

void main()
{ int m,p;
  char c;

  m=0;
	while((c=getchar())!=EOF){
	  p=1;
	 if(c=='"')
	  { m++;
		 p=0;
	  }

	 if(p==0)
	 {
	 if(m%2==0)
	  printf("''");

	 else if(m%2!=0)
	  printf("``");
	 }
	 else
	  printf("%c",c);



	}
}