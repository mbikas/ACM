#include<stdio.h>
#include<string.h>

 void string_sort(int m);

 typedef struct
 {
	char c[100];
  }dic;

 dic d[20];

 void main()
 { int m,i;
	while(scanf("%d",&m)==1)
	 {
		for(i=0;i<m;i++)
		 scanf (" %s",d[i].c);

		string_sort(m);

		for(i=0;i<m;i++)
		printf("%s\n",d[i].c);

	 }

}





 void string_sort(int m)
  {
	 char temp[20];
	 int  i,j;


	  for(i=1;i<m;i++)
	  for(j=0;j<m-i;j++)
		{
		  if( strcmp( d[j].c,d[j+1].c)>0)
			{
			  strcpy(temp ,d[j].c);
			  strcpy(d[j].c,d[j+1].c);
			  strcpy(d[j+1].c,temp);
			}
		}
  }
