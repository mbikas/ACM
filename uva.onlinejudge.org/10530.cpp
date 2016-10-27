				//Acm 10530 Gueesing Game
				//Solved By Bikas CSE Sust

#include<stdio.h>
#include<string.h>

void main()
{
 int n,i,x[11],p;
 char a[10];

 for(i=1;i<=10;i++)
  x[i]=1;

 while(scanf(" %d",&n)==1 && n!=0)
 {
  scanf(" %[^\n]",a);
  p=strlen(a);


  if(a[p-1]=='h')
	{
	  for(i=n;i<=10;i++)
		 x[i]=0;
	}

  else if(a[p-1]=='w')
	{
	  for(i=n;i>=1;i--)
		 x[i]=0;
	}

  else if(a[p-1]=='n')
	{
	  if(x[n]==1)
		 printf("Stan may be honest\n");
	  else
		 printf("Stan is dishonest\n");

	  for(i=1;i<=10;i++)
		 x[i]=1;
	}

 }
}
