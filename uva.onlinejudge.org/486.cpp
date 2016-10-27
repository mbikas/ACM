#include<stdio.h>
#include<string.h>

char b[36][12]={"negative","zero","one","two","three","four","five","six","seven",
				"eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
				"sixteen","seventeen","eighteen","nineteen","twenty","thirty","forty",
				"fifty","sixty","seventy","eighty","ninety"};
long num[33]={-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90};
void get_num(char c[]);
long ct,total,val,sum[50],minus;


void main()
{
	char a[80000],*p='\0';
	long n,i;


	while(gets(a))
	{
	
		if(strcmp("zero",a)==0)
		{
			printf("0\n");
			continue;
		}
		val=total=ct=minus=n=0;
		
		p=strtok(a," \b\r\t");
		while(p)
		{
			get_num(p);
			p=strtok(NULL," \b\r\t"); 							
		}

		sum[ct++]=total;
		for(i=0;i<ct;i++)
		n+=sum[i];
		printf("%ld\n",n);
	
	
	}
}


void get_num(char c[])
{
	int i;
		if(strcmp("negative",c)==0 && minus==0)
		{
			printf("-");
			minus=1;
			return;
		}
		
		for(i=2;i<29;i++)
		{	if(strcmp(b[i],c)==0)
			{	
				val=num[i];
				break;
			}
		}

		if(strcmp("hundred",c)==0)
		{
			total=val*100;
			val=0;
		}
		else if(strcmp(c,"thousand")==0)
		{
			sum[ct++]=total*1000;
			val=total=0;
		}
		else if(!strcmp(c,"million"))
		{
			sum[ct++]=total*1000000;
			val=total=0;
		}
		total=total+val;
}
