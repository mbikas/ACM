#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	bool found[1000];
	char ch;
	char input[20000];
	long long n,i,j,sum,rem,v,len,test,val[1000];


	gets(input);
	sscanf(input,"%lld",&test);

	while(test--)
	{
		gets(input);
		sscanf(input,"%lld",&n);

		memset(found,false,sizeof(found));
		//gets(input);
		for(i=0;i<n;i++)
		{
			gets(input);
			sscanf(input,"%c %lld",&ch,&v);
			found[ch]=true;
			val[ch] = v; 
		}

		gets(input);
		sscanf(input,"%lld",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			gets(input);
			//scanf(" %[^\n]",input);
			len = strlen(input);

			for(j=0;j<len;j++)
			{
				if(found[input[j]])
					sum+=val[input[j]];				
			}
		}

		rem = sum%100;
		sum = sum/100;

		printf("%lld.",sum);
		if(rem<10)
		{
			printf("0");
					
		}
		printf("%lld$\n",rem);

	
	}

	return 0;
}