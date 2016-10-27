						//Acm446 Kibbles `n' Bits `n' Bits `n' Bits
						//Solved By Bikas Cse Sust

#include<stdio.h>
#include<string.h>
#include<math.h>

void hexa_to_binary(char a[]);
int hexa_to_decimal(char a[]);

void main()
{

  int testCase,sum1,sum2;
  char a[4],ch;


  scanf("%d",&testCase);

	  while(testCase>0){

		 scanf(" %s ",a);

		 hexa_to_binary(a);
		 sum1=hexa_to_decimal(a);

		 scanf(" %c %s",&ch,a);

		 printf(" %c ",ch);
		 hexa_to_binary(a);
		 sum2=hexa_to_decimal(a);




		 if(ch=='+')
			sum1=sum1+sum2;
		 if(ch=='-')
			sum1=sum1-sum2;


		 printf(" = %d\n",sum1);


		 testCase--;

  }
}




 //returning the decimal of equivalent (char) Hexadecimal number
 int hexa_to_decimal(char a[])
 {
	 int m,x,i,decimal=0,p;
	 m=strlen(a);
	 x=m-1;

	 for(i=0;i<m;i++)
	 {

	  if(a[i]=='A'||a[i]=='a')     p=10;
	  else if(a[i]=='B'||a[i]=='b')p=11;
	  else if(a[i]=='C'||a[i]=='c')p=12;
	  else if(a[i]=='D'||a[i]=='d')p=13;
	  else if(a[i]=='E'||a[i]=='e')p=14;
	  else if(a[i]=='F'||a[i]=='f')p=15;
	  else p= ((int)a[i]-48) ;

	  decimal+=  p * pow(16,x);
	  x--;
	 }

	 return decimal;


 }


 // printing binary representation of the (char)hexadecimal number in 13 field width
 void hexa_to_binary(char a[])
 {
		 int m,i;
		 m=strlen(a);

		 if(m==1)
		  printf("000000000");

		 else if(m==2)
		  printf("00000");

		 else if(m==3)
		  printf("0");



		 for(i=0;i<m;i++)
		 {
		  if(a[i]=='F' || a[i]=='f' )
			printf("1111");

		  else if(a[i]=='E'||a[i]=='e')
			printf("1110");

		  else if(a[i]=='D'||a[i]=='d')
			printf("1101");

		  else if(a[i]=='C'||a[i]=='c')
			printf("1100");

		  else if(a[i]=='B'||a[i]=='b')
			 printf("1011");

		  else if(a[i]=='A'||a[i]=='a')
			 printf("1010");

		  else if(a[i]=='0')
			 printf("0000");

		  else if(a[i]=='1')
			 printf("0001");

		  else if(a[i]=='2')
			 printf("0010");

		  else if(a[i]=='3')
			 printf("0011");

		  else if(a[i]=='4')
			 printf("0100");

		  else if(a[i]=='5')
			 printf("0101");

		  else if(a[i]=='6')
			 printf("0110");

		  else if(a[i]=='7')
			 printf("0111");

		  else if(a[i]=='8')
			 printf("1000");

		  else if(a[i]=='9')
			 printf("1001");

	}
 }








