#include<stdio.h>
#include<string.h>

void main()
{
 int i,m,testCase,x=1,p[27];
 char c;
 long long int arrange;

 scanf("%d ",&testCase);

 while(testCase>0){

	for(i=0;i<26;i++)
	  p[i]=0;

	  m=0;
	  while( scanf("%c",&c)==1)
	  {
		 if(c=='\n')
			break;
		 p[c-65]++;
		 m++;

	  }

	  arrange=1;

	  while(m>1)
	  {
		arrange*=m;
		m--;
	  }

	 for(i=0;i<26;i++)
		{ if(p[i]>1)
			 {
				m=p[i];
				while(m>1)
				 { arrange=arrange/m;
					m--;
				 }
			 }
		}


	  printf("Data set %d: %lld\n",x,arrange);


	  x++;
	  testCase--;
  }
}
