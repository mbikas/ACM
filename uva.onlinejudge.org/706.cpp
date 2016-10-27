									 //Acm 706  LC-DISPLAY
                            //Solved By Bikas CSE SUST

#include<stdio.h>
#include<string.h>
void main()
{ int i,j,m,n,k;
  char a[20];


  while( scanf (" %d %s",&n,a)==2){

         m=strlen(a);
	 
         if(n==0 && a[0]=='0')
	  break;



	 ///////////////////////////////////////

	 for(i=0;i<m;i++)
	 {
		printf(" ");
		if(a[i]=='1' || a[i]== '4')
		 {
		  for(j=0;j<n;j++)
			printf(" ");

		 }

		else
		 {
		  for(j=0;j<n;j++)
			printf("-");
		 }

		printf(" ");
	  }
		printf("\n");
	 /////////////////////////////////////////////////////



	for(j=0;j<n;j++)
	 {
	  for(i=0;i<m;i++)
		{

		 if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='7')
		  {
			  for(k=0;k<n+1;k++)
				printf(" ");

				printf("|");
		  }

		 else if(a[i]=='5'||a[i]=='6')
		  {
				printf("|");

				for(k=0;k<n+1;k++)
				  printf(" ");
		  }

		 else if(a[i]=='4'||a[i]=='8'||a[i]=='9'||a[i]=='0')
		  {
				printf("|");
				for(k=0;k<n;k++)
				  printf(" ");

				printf("|");

		  }
	  }

	 printf("\n");
	}
 /////////////////////////////////////////////



	 for(i=0;i<m;i++)
	  {
		 printf(" ");

		 if(a[i]=='1'||a[i]=='7'||a[i]=='0')
			{
			  for(j=0;j<n;j++)
				printf(" ");

			}

		 else
			{
			  for(j=0;j<n;j++)
				printf("-");

			}
		  printf(" ");
		}

	 printf("\n");
 /////////////////////////////////

	for(j=0;j<n;j++)
	 {
	  for(i=0;i<m;i++)
		{

		 if(a[i]=='1'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='7'||a[i]=='9')
		  {
			  for(k=0;k<n+1;k++)
				 printf(" ");

				printf("|");
		  }

		 else if(a[i]=='2')
		  {
				printf("|");

				for(k=0;k<n+1;k++)
				  printf(" ");
		  }

		 else if(a[i]=='6'||a[i]=='8'||a[i]=='0')
		  {
				printf("|");
				for(k=0;k<n;k++)
				  printf(" ");

				printf("|");

		  }
	  }

	 printf("\n");
	}
  /////////////////////////////////////////////

	 for(i=0;i<m;i++)
	  {
		  printf(" ");
		  if(a[i]=='1'|| a[i]== '4'||a[i]=='7')
			{
			  for(j=0;j<n;j++)
				printf(" ");
			}

		  else
			{
			  for(j=0;j<n;j++)
				 printf("-");
			}

		  printf(" ");
	  }

	  printf("\n\n");



  } //while

}  //main

