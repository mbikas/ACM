#include<stdio.h>
#define size 21
void main()
{
 int i,j,k,l,row,number;
 char a[size][size],b[size][size],c[size][size];

  scanf("%d",&number);

  while(number>0)
  {


	 scanf(" %d",&row);


	 for(i=0;i<row;i++)
	 for(j=0;j<row;j++)
	  { scanf(" %c",&a[i][j]);
		  if(a[i][j]=='.')
			 b[i][j]=48;

	  }

	////////////////////////////////////
	for(i=0;i<row;i++)
	 {for(j=0;j<row;j++)
		{
		  if(a[i][j]=='*')
			{ b[i][j]='*';
			  k=i-1;
			  l=j-1;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			  k=i-1;
			  l=j;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			  k=i-1;
			  l=j+1;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			  k=i+1;
			  l=j-1;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			  k=i+1;
			  l=j;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			  k=i+1;
			  l=j+1;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			  k=i;
			  l=j-1;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			  k=i;
			  l=j+1;
			  if(a[k][l]!='*')
				 b[k][l]=b[k][l]+1;

			}
		 }
	  }
	 ////////////////////////////////////

	  k=0;
	 //indicating mines selected or not
	 /////////////////////////////////////
	  for(i=0;i<row;i++)
		 for(j=0;j<row;j++)
		  { scanf(" %c",&c[i][j]);
			  if(c[i][j]=='.')
				 b[i][j]='.';
			  if(c[i][j]=='x'&&a[i][j]=='*')
				 k=1;
		  }
	 /////////////////////////////////////////


	 //printing this if mine in selected
	 /////////////////////////////////
	 if(k==1)
	  {
		for(i=0;i<row;i++)
		 {for(j=0;j<row;j++)
			{
			  if(c[i][j]=='x')
				printf("%c",b[i][j]);
			  else
				printf("%c",a[i][j]);
			}

			  printf("\n");
		 }

	  }
	 ///////////////////////////////////////

	 //printing this if mine in not selected
	 ////////////////////////////////
	 else
	  {
		for(i=0;i<row;i++)
		 {for(j=0;j<row;j++)
			printf("%c",b[i][j]);
			printf("\n");
		 }
	 }
	/////////////////////////////////////




	number--;

	if(number!=0) // try without this line
		printf("\n");

 }

}