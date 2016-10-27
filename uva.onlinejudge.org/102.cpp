			   // ACM 102 Ecological Bin Packing
               // Solved By  Bikas Cse Sust

#include<stdio.h>
void main()
{
  unsigned long b1,b2,b3,g1,g2,g3,c1,c2,c3,p,m,temp;

  while(scanf("%lu%lu%lu%lu%lu%lu%lu%lu%lu",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9){

		p=1;
		m=b2+b3+c1+c3+g1+g2;

		temp=b2+b3+g1+g3+c1+c2;
		if(temp<m)
		{ m=temp;
		  p=2;
		}


		temp=c2+c3+b1+b3+g1+g2;
		if(temp<m)
		{ m=temp;
		  p=3;
		}


		temp=c2+c3+g1+g3+b1+b2;
		if(temp<m)
		{ m=temp;
		  p=4;
		}


		temp=g2+g3+b1+b3+c1+c2;
		if(temp<m)
		{ m=temp;
		  p=5;
		}


		temp=g2+g3+c1+c3+b1+b2;
		if(temp<m)
		{ m=temp;
		  p=6;
		}


		if(p==1)
		  printf("BCG %lu\n",m);

		else if(p==2)
		  printf("BGC %lu\n",m);

		else if(p==3)
		  printf("CBG %lu\n",m);

		else if(p==4)
		  printf("CGB %lu\n",m);

		else if(p==5)
		  printf("GBC %lu\n",m);

		else
		  printf("GCB %lu\n",m);


  }
}