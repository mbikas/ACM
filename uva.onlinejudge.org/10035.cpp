						//Acm10035 Carry operation
						//Solved By Bikas Cse Sust

#include<stdio.h>

void main()
{
	int p,result;

   long x,y,temp;

  while( scanf("%ld %ld",&x,&y)==2 && ( x!=0 || y!=0) ){

	 result=0;
	 p=0;

	 if(x>=y)
		{ temp=x;
		  y=y;
		}

	 else
		{ temp=y;
		  y=x;
		}

	 while(temp>0){

		  x = ( temp%10)  + ( y%10) +p;

		  if(x>=10)
			{
			 result++;
			 p=1;
			}
		  else
			 p=0;

		  temp=temp/10;
		  y=y/10;

	  }



  if(result==0)
	 printf("No carry operation.\n");

  if(result==1)
	 printf("%d carry operation.\n",result);

  if(result>1)
	 printf("%d carry operations.\n",result);


 }
}
