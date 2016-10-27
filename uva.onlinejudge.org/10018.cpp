//Acm 10018 Reverse and Add
//solved by Bikas CSE SUST

#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 20 //50

void main()
{ int z,x,i,p,flag,m;
  unsigned long  sum,temp;
  char a[size];


  while( scanf("%d",&z)==1){
	 while(z!=0){

		scanf(" %s",a);
		m=strlen(a);
		p=1;
		flag=0;

		while(flag!=1){

		sum=0;
		for(i=0;i<m;i++)
			sum+= ( (pow)(10,i) * ((int)a[i]-48)) ;


		x=m-1;
		for(i=0;i<m;i++)
			{
			 sum+= ( (pow)(10,x) * ((int)a[i]-48)) ;
			 x--;
			}



		temp=sum;
		m=0;

		while(temp>0){
		  a[m]=(char)(temp%10)+48;
		  m++;
		  temp=temp/10;
		 }

		x=m-1;
		for(i=0;i<m;i++){
			if(a[i]!=a[x])
			  { flag=0;
				 p++;
				 break;
			  }
			else
			  flag=1;
			x--;
		 }

		if(flag==1)
		 printf("%d %lu\n",p,sum);

	  }

	 z--;
	}

  }
 }
