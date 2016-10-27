            //Acm 10473 Simple Base Conversion
				//Solved By Bikas CSE Sust

  #include<stdio.h>
  #include<string.h>
  #include<math.h>

  long hexa_to_decimal(char a[]);
  void decimal_hexadecimal(long p);

  void main()
  {  long p;
	  char line[20];

	  while(scanf(" %s",line)==1)
	  {


	  if(line[0]=='-')
		break;

	  if(strlen(line)>=3 && line[0] == '0' && line[1] == 'x') //then num is in hexdecimal system
	  //if( (line[0] == '0'&& line[1]=='X') || (line[0] == '0'&& line[1]=='x') )
		  {

				p=hexa_to_decimal(line);
            printf("%ld\n",p);
		  }
		  else //decimal system
		  {

				sscanf(line,"%ld",&p);
				decimal_hexadecimal(p);

		  }
	  }
  }



//returning the decimal of equivalent (char) Hexadecimal number
 long hexa_to_decimal(char a[])
 {
	 int m,x,i,p;
	 long decimal=0;
	 m=strlen(a);
	 x=m-3;

	 for(i=2;i<m;i++)
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


void decimal_hexadecimal(long p)
{ int x,i=0;
  char a[11];

  while(p>0)
  {
	x=(int)(p%16);
	
	if(x==15)a[i]='F';
	else if(x==14)a[i]='E';
	else if(x==13)a[i]='D';
	else if(x==12)a[i]='C';
	else if(x==11)a[i]='B';
	else if(x==10)a[i]='A';
	else a[i]=x+48;
	p=p/16;
	i++;
  }

  printf("0x");
  for(x=i-1;x>=0;x--)
	printf("%c",a[x]);

  printf("\n");


}
