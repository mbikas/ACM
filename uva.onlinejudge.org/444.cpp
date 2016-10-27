//Acm 444 Carry Operation
#include<stdio.h>
#include<string.h>
#define size 32000   

void encode(char a[]);
void decode(char a[]);



void main()
{
  char a[size];

  while( scanf(" %[^\n]",a)==1){



	  if(a[0]>=48 && a[0]<=57)
		 decode(a);
	  else
		 encode(a);

       printf("\n");

  }
 }

 void encode(char a[]){

	int m,j,i;  

	m=strlen(a);

	for(i=m-1;i>=0;i--){

	  j= (int)a[i];
	  while(j>0)
		{
		 printf("%d",j%10);
		 j=j/10;
		}
	}
	//printf("\n");
}


 void decode(char a[]){

	int m,j,i;      

	m=strlen(a);

	for(i=m-1;i>=0;){

	  if(a[i]=='1')
	  {

		 j= ((a[i]-48)*100)+((a[i-1]-48)*10)+(a[i-2]-48);
		 printf("%c",j);
		 i=i-3;
	  }
	 else
	  {
		 j=(int)a[i]-48;
		 j=j*10;
		 i--;
		 j=j+( (int)a[i]-48);
		 i--;
		 printf("%c",j);
	  }

	}

	//printf("\n");
}






