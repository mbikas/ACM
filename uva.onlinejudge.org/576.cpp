#include<stdio.h>
#include<string.h>

void main()
{
 int i,p,x,m,n;
 char a[200];


 while(scanf(" %[^\n]",a)==1)
 {
  if(a[0]=='e'&&a[1]=='/'&&a[2]=='o'&&a[3]=='/'&&a[4]=='i')
	 break;



  m=strlen(a);

  p=1;
  x=0;
  n=0;
  for(i=0;i<=m;i++)
  {
	 if(a[i]=='/'|| a[i]=='\0')
	 {
	  n=0;
	  if(x==5 && p==1)
	  {
		//printf("%d ",x);
		x=0;
		p=2;
	  }
	  else if(x==7 && p==2)
	  {
		//printf("%d ",x);

		x=0;
		p=3;
	  }
	  else if(x==5 && p==3)
	  {
		//printf("%d ",x);
		x=0;
		printf("Y\n");
		break;

	  }
	  else
		{
		 printf("%d\n",p);
		 break;

		}
	}


	 if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')
	  {
		  if(n==0)
			 { x++;
				n=1;
			 }
	  }
	else
	  n=0;



	}












 }
}
