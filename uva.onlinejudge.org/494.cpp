//Acm 494 KinderGarten Counting Game
//solved by Bikas CSE SUST
 #include<stdio.h>

 void main()
 {
  int flag;
  long p;
  char ch;

  p=0;
  while ( scanf("%c",&ch)!=EOF){

	 if( (ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z') )
		  flag=1;

	 else
	  {
		 if(flag==1)
			p++;

		 flag=0;
		 if(ch=='\n')
		  {
			printf("%ld\n",p);
			p=0;
		  }
	  }

  }
}
