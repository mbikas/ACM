 #include<stdio.h>

 #define sz 5

 int santa[5][5]={ {0,1,1,0,1}, {1,0,1,0,1}, {1,1,0,1,1}, {0,0,1,0,1} ,{1,1,1,1,0}};

 void backtrack(int a[],int k);

 void main()
 {
	int a[9];

	a[0]=0;

	backtrack(a,1);
 }

 void backtrack(int a[],int k)
 {
  int i;

  if(k==9)
	  {
		 for(i=0;i<9;i++)
		 printf("%d",a[i]+1);

		 printf("\n");
	  }

	else
	  {
		 for(i=0;i<5;i++)
		  {
			 if( santa[a[k-1]][i])
			  {
				 a[k]=i;
				 santa[a[k-1]][i]=0;
				 santa[i][a[k-1]]=0;
				 backtrack(a,k+1);
				 santa[a[k-1]][i]=1;
				 santa[i][a[k-1]]=1;
			  }
		  }
		}



 }


