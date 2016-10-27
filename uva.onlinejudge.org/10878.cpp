#include<stdio.h>
#include<string.h>
#define sz 2005

void main()
{
	int j,len,x,i,num;
	
	
	char tape[1000],bin[1000];
	
	scanf(" %[^\n]",tape);
	while(scanf(" %[^\n]",tape)==1)
	{
		if(tape[0]=='_')break;
		
		
		
		len =strlen(tape);
		x=0;
		num = 0;
		for(i=0;i<len;i++)
		{
			if(tape[i]=='o'){
				bin[x++]='1';
				break;
			}
		}
		for(j=i+1;j<len-1;j++)
		{
			if(tape[j]=='o')bin[x++]='1';
			if(tape[j]==' ')bin[x++]='0';		
		}
		bin[x]='\0';
		
		
		
		num=1;
		for(i=0;i<x-1;i++)
		num = num*2 + (bin[i+1]-'0'); 
	
		
		//printf("bin = %s num = %d\n",bin,num);
		
		printf("%c",num);
		
	}	

	//printf("\n");
}
