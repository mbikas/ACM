// Acm 541 Error Correction
//solved by Bikas CSE SUST
#include<stdio.h>
#define size 50  // 30-40  
void main()

{
 int i,j,m,n,a[size][size],sum=0,row,r,c,col;


	while(scanf("%d",&n)==1&&n!=0){

		r=0,c=0;

		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]) ;

		i=0;
		while(i<n){
			sum=0;
			for(j=0;j<n;j++)
			  sum=sum+a[i][j];


			if(sum%2!=0)
			 { row=i+1;
				r++;
			 }

			i++;
		}


	 i=0;
	 while(i<n){
		 sum=0;
		 for(j=0;j<n;j++)
			sum=sum+a[j][i];

		 if(sum%2!=0)
		  { col=i+1;
			 c++;
		  }
		i++;
	}


	 if(r==0&&c==0)
			printf("OK\n");
	 else if(r==1&&c==1)
		 printf("Change bit (%d,%d)\n",row,col);		
	 else if(r>1||c>1)
			printf("Corrupt\n");


  }
}
