#include <stdio.h>
#include <string.h>

/* change this constant if you want a longer subsequence */
#define MAX 1001

char X[MAX],Y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX];

int LCSlength() {
  m=strlen(X);
  n=strlen(Y);

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


void main() {
  while ( scanf(" %[^\n] %[^\n]",X,Y)==2){
	 printf("%d\n",LCSlength()); /* count length */

    //printf("\n");
  }
}

