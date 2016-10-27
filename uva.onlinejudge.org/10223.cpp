#include<stdio.h>
#include<string.h>

void main()
{
	//freopen("e.txt","w",stdout);
	char message[5000],temp[5000];
	
	long test,m=1,i,len,p,f2,ct=0;
	bool flag,f=false;
	
	gets(message);
	sscanf(message,"%ld",&test);
	//printf("\"");
	
	while(test--)
	{
		gets(message);
		len=strlen(message);
		message[len]=' ';
		
		flag=false;
		
		if(f)
			printf("\n");
		else
			f=true;
		
		f2=0;
		ct=0;
		p=0;
		printf("Message #%ld\n",m++);
		for(i=0;i<=len;i++)
		{
			if(message[i]!=' ')
			{
				temp[p++]=message[i];			
			}
			else
			{
				
				
				
				temp[p]='\0';
				
				
				if(!strcmp(temp,".-"))
					printf("A");
				
				else if(!strcmp(temp,"-..."))
					printf("B");
				
				else if(!strcmp(temp,"-.-."))
					printf("C");
				
				else if(!strcmp(temp,"-.."))
					printf("D");
				
				else if(!strcmp(temp,"."))
					printf("E");
				
				else if(!strcmp(temp,"..-."))
					printf("F");
				
				else if(!strcmp(temp,"--."))
					printf("G");
				
				else if(!strcmp(temp,"...."))
					printf("H");
				
				else if(!strcmp(temp,".."))
					printf("I");
				
				else if(!strcmp(temp,".---"))
					printf("J");
				
				else if(!strcmp(temp,"-.-"))
					printf("K");
				
				else if(!strcmp(temp,".-.."))
					printf("L");
				
				else if(!strcmp(temp,"--"))
					printf("M");
				
				else if(!strcmp(temp,"-."))
					printf("N");
				
				else if(!strcmp(temp,"---"))
					printf("O");
				
				else if(!strcmp(temp,".--."))
					printf("P");
				
				else if(!strcmp(temp,"--.-"))
					printf("Q");
				
				else if(!strcmp(temp,".-."))
					printf("R");
				
				else if(!strcmp(temp,"..."))
					printf("S");
				
				else if(!strcmp(temp,"-"))
					printf("T");
				
				else if(!strcmp(temp,"..-"))
					printf("U");
				
				else if(!strcmp(temp,"...-"))
					printf("V");
				
				else if(!strcmp(temp,".--"))
					printf("W");
				
				else if(!strcmp(temp,"-..-"))
					printf("X");
				
				else if(!strcmp(temp,"-.--"))
					printf("Y");
				
				else if(!strcmp(temp,"--.."))
					printf("Z");
				
				else if(!strcmp(temp,"-----"))
					printf("0");
				else if(!strcmp(temp,".----"))
					printf("1");
				
				else if(!strcmp(temp,"..---"))
					printf("2");
				
				else if(!strcmp(temp,"...--"))
					printf("3");
				
				else if(!strcmp(temp,"....-"))
					printf("4");
				
				else if(!strcmp(temp,"....."))
					printf("5");
				
				else if(!strcmp(temp,"-...."))
					printf("6");
				
				else if(!strcmp(temp,"--..."))
					printf("7");
				
				else if(!strcmp(temp,"---.."))
					printf("8");
				
				else if(!strcmp(temp,"----."))
					printf("9");
				
				else if(!strcmp(temp,".-.-.-"))
					printf(".");
				
				else if(!strcmp(temp,"--..--"))
					printf(",");
				
				else if(!strcmp(temp,"..--.."))
					printf("?");
				
				else if(!strcmp(temp,".----."))
					printf("'");
				
				else if(!strcmp(temp,"-.-.--"))
					printf("!");
				
				else if(!strcmp(temp,"-..-."))
					printf("/");
				
				else if(!strcmp(temp,"-.--."))
					printf("(");
				
				else if(!strcmp(temp,"-.--.-"))
					printf(")");
				
				else if(!strcmp(temp,".-..."))
					printf("&");
				
				else if(!strcmp(temp,"---..."))
					printf(":");
				
				else if(!strcmp(temp,"-.-.-."))
					printf(";");
				
				else if(!strcmp(temp,"-...-"))
					printf("=");
				
				else if(!strcmp(temp,".-.-."))
					printf("+");
				
				else if(!strcmp(temp,"-....-"))
					printf("-");
				
				else if(!strcmp(temp,"..--.-"))
					printf("_");
				
				else if(!strcmp(temp,".-..-."))
					printf("\"");
				
				else if(!strcmp(temp,".--.-."))
					printf("@");
				
				
				
				if(i!=0 && i!=len && message[i-1]==' ')
				{
					printf(" ");
					message[i]='a';					
				}
				
				p=0;
			}
			
			
		}
		
		printf("\n");
		
	}
}