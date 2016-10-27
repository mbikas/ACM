// acm 492  Pig-Latin
//solved by Bikas CSE SUST
#include<stdio.h>
#include<string.h>
#define size 4000000

void main()
{
  char c[size];
  unsigned long i,x,k,m;        
  int p;

  while( scanf(" %[^\n]",c)==1){

  m=strlen(c);
  p=0;

  if(m==0)
   printf("\n");

  for(i=0;i<m+1;i++){
	  if( ( c[i]>='a'&&c[i]<='z') || ( c[i]>='A'&&c[i]<='Z'))
		{ if(p==0)
			x=i;
		  p=1;
		}

	  else{
		 if(p==1)
		  {
			 if(c[x]=='a'||c[x]=='A'||c[x]=='e'||c[x]=='E'||c[x]=='i'||c[x]=='I'||c[x]=='o'||c[x]=='O'||c[x]=='u'||c[x]=='U')
				{ for(k=x;k<i;k++)
					printf("%c",c[k]);

				  printf("ay");
				}

			 else{
				  for(k=x+1;k<i;k++)
					printf("%c",c[k]);
				  printf("%cay",c[x]);
				}


			if(c[i]!='\0')
			 printf("%c",c[i]);
		 }

		else
			if(c[i]!='\0')
			 printf("%c",c[i]);

		p=0;
		}

	 } //for

	printf("\n");

 }
}

