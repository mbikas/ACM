#include<stdio.h>

void main()
{

 int a[60],i,max;
 char c;

 for(i=0;i<=52;i++)
  a[i]=0;

 while( scanf("%c",&c) !=EOF){

	if(c>='A'&&c<='Z')
	  a[c-65]++;

	if(c>='a'&&c<='z')
	  a[c-71]++;


	if(c=='\n'){
		max=0;
		for(i=0;i<=52;i++)
		 {
		  if(a[i]>max)
		  max=a[i];
		 }

		for(i=0;i<=52;i++)
		 {
		  if(a[i]==max)
		  {
			if(i<=25)
			  printf("%c",(i+65));
			if(i>25)
			  printf("%c",(i+71));
		  }
		 }

		printf(" %d\n",max);

		for(i=0;i<=52;i++)
		 a[i]=0;

	}


 }
}