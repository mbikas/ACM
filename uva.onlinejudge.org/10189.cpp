#include<stdio.h>
#define size 100

void main()
{
 int i,j,k,l,number=1,row,col,flag=0;
 char a[size][size];


 while( scanf("%d %d",&row,&col)==2 && row!=0 && col!=0 ){

	 if(flag==1)printf("\n");
	 else flag=1;

	 for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		 { scanf(" %c",&a[i][j]);
			 if(a[i][j]=='.')
				a[i][j]=48;
		 }

	 for(i=0;i<row;i++)
	  {for(j=0;j<col;j++)
		{
		 if(a[i][j]=='*')
		  {
			 k=i-1;
			 l=j-1;
			 if(a[k][l]!='*')
			  a[k][l]=a[k][l]+1;
			 k=i-1;
			 l=j;

			 if(a[k][l]!='*')
				a[k][l]=a[k][l]+1;
			 k=i-1;
			 l=j+1;

			 if(a[k][l]!='*')
				a[k][l]=a[k][l]+1;
			 k=i+1;
			 l=j-1;

			 if(a[k][l]!='*')
				a[k][l]=a[k][l]+1;
			 k=i+1;
			 l=j;

			 if(a[k][l]!='*')
				a[k][l]=a[k][l]+1;
			 k=i+1;
			 l=j+1;

			 if(a[k][l]!='*')
				a[k][l]=a[k][l]+1;
			 k=i;
			 l=j-1;

			 if(a[k][l]!='*')
				a[k][l]=a[k][l]+1;
			 k=i;
			 l=j+1;
			 if(a[k][l]!='*')
				a[k][l]=a[k][l]+1;

		  }
		}
	  }

	 printf("Field #%d:\n",number);
	 number++;

	 for(i=0;i<row;i++)
	  {for(j=0;j<col;j++)
		 {
		  printf("%c",a[i][j]);
		 }
		  printf("\n");
		}


	

  }
 }
