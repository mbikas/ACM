#include<stdio.h>
#include<string.h>
#define SIZE 1000002

void main()
{  char a[SIZE],counter[SIZE];
	long p,i,L,U,n,x=1;


	while(scanf(" %s",a)==1)
	{

	  p=strlen(a);
	  for(i=0;i<=p;i++)
		counter[i]=0;

	  for(i=1;i<p;i++)
	  {
		if(a[i]!=a[i-1])
		 counter[i]=counter[i-1]+1;
		else
		 counter[i]=counter[i-1];
	  }


	  scanf("%ld",&n);
     printf("Case %ld:\n",x);
	  for(i=0;i<n;i++)
	  {
		scanf("%ld %ld",&L,&U);


		if(counter[L]==counter[U])
		 printf("YES\n");
		else
		 printf("NO\n");


	  }

	  x++;
	}

}