//11398

#include<stdio.h>
#include<string.h>

char ans[10000];



long long anyBase_decimal(char ch[],int base) 
{  
	long long val=0; 
	long long mult=1; 
	int i; 
	for( i=strlen(ch)-1 ; i>=0 ; i--){ 
      if ( ch[i] >= '0' && ch[i] <= '9' ) 
         val += (ch[i]-'0')*mult; 
      else if ( ch[i] >= 'A' && ch[i] <= 'Z' )    
         val += (ch[i]-'A' + 10) *mult; 
      mult *= base; 
	} 
	
	return val; 
} 


int main()
{
	int ct,flag,len,n;
	char str[10000];

	long long dec;

	ct=0;
	flag=1;
	while(scanf(" %s",str)==1)
	{
		if(strcmp(str,"~")==0)break;

		if(strcmp(str,"#")==0)
		{
			//		ans
			ans[ct]='\0';

			dec = anyBase_decimal(ans,2); 
			printf("%lld\n",dec);
			ct=0;
			continue;
		}

		len = strlen(str);
		if(len==1)flag=1;
		else if(len==2)flag=0;
		else 
		{	
			n = len-2;
			if(flag==1)
			{
				while(n--)ans[ct++]='1';
			}
			else 
			{
				while(n--)ans[ct++]='0';
			
			}
		}


	
	
	}


	return 0;
}