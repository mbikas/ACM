						//Acm401 Palindrome
						//Solved By Bikas Cse Sust

#include<stdio.h>
#include<string.h>

void main()
{
 int i,palindrome,x,m,mirror;
 char a[20],b[20];

  while( scanf(" %s",a)==1){

			 m=strlen(a);

			 mirror=0;
			 palindrome=0;

			 x=m-1;

			 for(i=0;i<m;i++)
			 {
			  printf("%c",a[i]);
			  if(a[i]!=a[x])
				 palindrome=1;

			  if(a[i]=='J')b[i]='L';
			  else if(a[i]=='S')b[i]='2';
			  else if(a[i]=='5')b[i]='Z';
			  else if(a[i]=='J')b[i]='L';
			  else if(a[i]=='E')b[i]='3';
			  else if(a[i]=='L')b[i]='J';
			  else if(a[i]=='2')b[i]='S';
			  else if(a[i]=='3')b[i]='E';
			  else if(a[i]=='Z')b[i]='5';
			  else  b[i]=a[i];

			  x--;
			 }

		  printf(" -- ");


			  x=m-1;
		  for(i=0;i<m;i++)
			{
			  if(a[i]!=b[x])
				  { mirror=1;
					 break;
				  }
			  x--;
			}




		  if(mirror==0 && palindrome==0)
					printf("is a mirrored palindrome.\n\n");

		  else if(palindrome==1 && mirror==1)
					printf("is not a palindrome.\n\n");

		  else if(palindrome==0&& mirror==1)
					printf("is a regular palindrome.\n\n");

		  else if(palindrome==1&& mirror==0)
					printf("is a mirrored string.\n\n");





 }
}
