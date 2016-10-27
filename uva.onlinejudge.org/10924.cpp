#include<stdio.h>
#include<string.h>

int isPrime(int num);

void main()
{

	
	char word[50];
	int num=0,len,i,x;


	while(scanf(" %[^\n]",word)==1)
	{

		num=0;		
		len = strlen(word);

		for(i=0;i<len;i++)
		{

			if(word[i]>='A' && word[i]<='Z')
					x = (int)word[i]-38;
			else if(word[i]>='a' && word[i]<='z')
					x = (int)word[i]-96;
			else
					x=0;

			num = num + x;	
		}

		
		if(isPrime(num)==1)
		printf("It is a prime word.\n");
		else
		printf("It is not a prime word.\n");
		

	
	}//end of while
}//end of main

 int isPrime(int num){
		 

		  int i;

		  if (num<1) return 0;         
		  if (num==2 || num==1) return 1;        
		  if (num%2==0) return 0;       /* NO prime is EVEN, except 2     */

		  for (i=3;i*i<=num;i+=2)  /* start from 3, jump 2 numbers   */
			 {	if (num%i==0)            
						return 0;
			 }
			return 1;
    }

