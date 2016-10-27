#include<stdio.h>


void main()
{
  char a[26],b[26];
  int sum1,sum2,i;
  float p,q;


  while( scanf(" %[^\n] %[^\n]",a,b)==2){


	 sum1=0;
	 for(i=0;a[i]!='\0';i++){
		 if( a[i]>=65 && a[i]<=90 )
		  { sum2= (int)a[i]-64;
			 sum1+=sum2;
		  }
		  else if( a[i]>=97 && a[i]<=122 )
		  { sum2= (int)a[i]-96;
			 sum1+=sum2;
		  }
		  
	  }

	 bikas:
	  p=0;
	  while(sum1>0){
		 p=p+ (sum1%10);
		 sum1=sum1/10;
		}

	  if(p>=10)
		 { sum1=p;
			goto bikas;
		 }



	  sum1=0;
	  for(i=0;b[i]!='\0';i++){
		 if( b[i]>=65 && b[i]<=90 )
		  { sum2= (int)b[i]-64;
			 sum1+=sum2;
		  }
		 else if( b[i]>=97 && b[i]<=122 )
		  { sum2= (int)b[i]-96;
			 sum1+=sum2;
		  }

	  }



	  naser:
	  q=0;
	  while(sum1>0){
		 q=q+ (sum1%10);
		 sum1=sum1/10;
		}

	  if(q>=10)
		 { sum1=q;
			goto naser;
		 }

	  

	  if(p==0&&q==0)
		p=0;          // try with p=0; // no input in alphabet

	  else{
	  if(p>q)
		  p=(q/p)*100;
	  else
		 p=(p/q)*100;
	  }
	  //p=(p/q)*100;


	  printf("%.2f %\n",p);


 }
}