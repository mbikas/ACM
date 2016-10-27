//Acm 10469  To carry or not to carry 
//solved by Bikas CSE SUST

#include<stdio.h>
void main()
{
		  unsigned long num1,num2,sum,temp;
		  int m,n,i,max,flag;
		  char firstNum[32],secondNum[32],add[32];


		  while(scanf("%lu%lu",&num1,&num2)==2)
		  {
			flag=0;
			sum=0;
			temp=num1;
			m=n=0;

			while(temp!=0)//Integer to binary
			{
					if(temp%2==0)
					  firstNum[m]='0';
					else
					  firstNum[m]='1';

					temp=temp/2;
					m++;
			}

			for(i=m;i<32;i++)
				firstNum[i]='0';

			temp=num2;
			while(temp!=0)//Integer to binary
			{
					if(temp%2==0) secondNum[n]='0';
					else secondNum[n]='1';
					temp=temp/2;
					n++;
			}

			for(i=n;i<32;i++)
					secondNum[i]='0';

			max=(m>n)? m:n ;

			for(i=0;i<max;i++)//For addition
			 {
				if(firstNum[i]=='0' && secondNum[i]=='0')
				  add[i]='0';

				else if(firstNum[i]=='1' && secondNum[i]=='1')
				  add[i]='0';

				else
				  add[i]='1';

			 }


			for(i=max-1;i>=0;i--)//For binary to integer          
			 {
			  if(flag==1)
				{  if(add[i]=='0')
					  sum*=2;
					else
					  sum=(sum*2)+1;

				}

			  if(add[i]=='1' && flag==0)
				{
				  flag=1;
				  sum=1;
				}
			}


		  printf("%lu\n",sum);


 }
}
