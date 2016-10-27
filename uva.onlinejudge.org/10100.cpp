
#include <stdio.h>
#include <string.h>
#include<ctype.h>

#define MAX 1005
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

void printLCS(int i,int j) {
  if (i==0 || j==0) return;

  if (b[i][j]==1) {
    printLCS(i-1,j-1);
    printf("%c",X[i-1]);
  }
  else if (b[i][j]==2)
    printLCS(i-1,j);
  else
	 printLCS(i,j-1);
}

void main() 
{
	//freopen("10100.in","r",stdin);
	//freopen("10100.out","w",stdout);

	char a[MAX],temp[MAX];
	long len,cases=1,x,len1,p,k,old;
	int f=1;

	while (gets(X))
	{
		f=1;
		len = 0;

		len1 = strlen(X);

		if(len1==0)f=0;
		
		

		


		gets(a);
		len1 = strlen(a);

		if(len1==0)f=0;
		x=0;
		

		if(f==0)
		{
			printf("%2ld. Blank!\n",cases++);
			continue;
		}

			

		//len = strlen(a);
		p=0;
		x=0;
		old=0;

		for(k=0;k<=len1;k++)
		{
			if(isalpha(a[k]))
			{
				Y[p++]=a[k];
			}
			else
			{
				Y[p]='\0';
				//printf("%s\n",Y);

				if(p>old){
				if(LCSlength()==p)
				len++;	
				}
				
				old=p;
				
			}		
		}

		printf("%2ld. Length of longest match: %ld\n",cases++,len);		
				
		
  }
}

