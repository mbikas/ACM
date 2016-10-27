#include <stdio.h>
#include <string.h>
#define MAX 101

int X[MAX],Y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX];
int LCSlength();




void main() {
  int counter=1;

  while (scanf("%d %d",&m,&n)==2 && (m!=0||n!=0) )
  {
	 for(i=0;i<m;i++)
	  scanf("%d",&X[i]);

	 for(i=0;i<n;i++)
	  scanf("%d",&Y[i]);


	 printf("Twin Towers #%d\n",counter);
	 printf("Number of Tiles : %d\n\n",LCSlength());

	 counter++;

  }
}





int LCSlength() {


  for (i=1;i<=m;i++) c[i][0]=0;
  for (j=0;j<=n;j++) c[0][j]=0;

  for (i=1;i<=m;i++)
	 for (j=1;j<=n;j++) {
		if (X[i-1]==Y[j-1]) {
		  c[i][j]=c[i-1][j-1]+1;
		  b[i][j]=1; /* from north west */
		}
		else if (c[i-1][j]>=c[i][j-1]) {
		  c[i][j]=c[i-1][j];
		  b[i][j]=2; /* from north */
		}
		else {
		  c[i][j]=c[i][j-1];
		  b[i][j]=3; /* from west */
		}
	 }

  return c[m][n];
}


