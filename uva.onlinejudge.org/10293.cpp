#include<stdio.h>

void main()
{

  char c,ch;
  int a[31],i;
  int p=0;

  for(i=0;i<31;i++)
	a[i]=0;

  while(scanf("%c",&c)==1)
  {
	  if(c=='#')
		 {
				for(i=1;i<31;i++)
				  {
					 if(a[i]!=0)
					  printf("%d %d\n",i,a[i]);
				  }

				for(i=0;i<31;i++)
					 a[i]=0;

				p=0;

		 }

	  else if(c!=' ' && c!='?' && c!='!' && c!=',' && c!='.' && c!= '\n')
		 {
				ch=c;
				if(c!='-' && c != '\'' && c!='"' && c!='`')
					{
						p++;
					}
		 }

	  else
		 {
				if(ch!='-')
				  {	a[p]++;
						p=0;
				  }
		 }      


  }
}
