#include<stdio.h>
#include<string.h>
#define sz 10000

typedef struct{
	char a[12];
}DIC;
DIC dic[1002];
int len=0;
int how_many_word(int a[]);

void main()
{
	int i,p,a[30];
	char str[sz];

	while(scanf(" %[^\n]",dic[len].a)==1)
	{	
		if(strcmp(dic[len].a,"#")==0)break;
		len++;
	}
	


	while( scanf(" %[^\n]",str)==1 )
	{
		if(strcmp(str,"#")==0)break;

		for(i=0;i<26;i++)a[i]=0;

		p = strlen(str);
		for(i=0;i<p;i++)
		{
			if(str[i]>='a' && str[i]<='z')
				a[str[i]-'a']++;		
		}

		p = how_many_word(a);
		printf("%d\n",p);

	}
}


int how_many_word(int a[])
{
	int i,j,x,b[30],total=0,f,p;
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<26;j++)
			b[j]=a[j];

		p = strlen(dic[i].a);
		f=1;
		for(j=0;j<p;j++)
		{
			x = dic[i].a[j]-'a';
			if(b[x]>0)
				b[x]--;		
			else
			{
			   f=0;	
			   break;
			}	
		}
		if(f==1)
		{	//printf("%s\n",dic[i].a);
			total++;
		}
	}

	return total;

}

