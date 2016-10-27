#include<stdio.h>
#include<string.h>
#define sz 1000

void main()
{
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	long test,i,p,len,len_subs;
	char input[sz],blank[sz],substitute[sz],ans[sz],plain[sz];
	bool flag[200];
	long pos[1000];

	memset(flag,false,sizeof(flag));
	gets(input);
	sscanf(input,"%ld",&test);
	gets(blank);

	p=1;
	while(test>1)
	{
		gets(input);
		len = strlen(input);
		if(len==0)
		{
			//output
			printf("\n");
			memset(flag,false,sizeof(flag));
			p=1;
			test--;
			continue;
		}
		if(p==1)
		{
			strcpy(plain,input);
			p++;
		}
		else if(p==2)
		{
			strcpy(substitute,input);
			len_subs=strlen(substitute);
			printf("%s\n%s\n",substitute,plain);
			for(i=0;i<len;i++)
			{
				flag[plain[i]]=true;
				pos[plain[i]]=i;

			}
			p++;
		}
		else
		{
			strcpy(ans,input);
			for(i=0;i<len;i++)
			{
				if(flag[input[i]] && pos[input[i]]<len_subs)
					ans[i] = substitute[pos[input[i]]];		
			}		
			printf("%s\n",ans);
		}	
	}

	///////////////final input//////////
		gets(plain);
		gets(substitute);
		len_subs=strlen(substitute);
		printf("%s\n%s\n",substitute,plain);
		len=strlen(plain);
		for(i=0;i<len;i++)
		{
				flag[plain[i]]=true;
				pos[plain[i]]=i;

		}
		
		while(gets(input))
		{
			strcpy(ans,input);
			len=strlen(input);
			for(i=0;i<len;i++)
			{
				if(flag[input[i]] && pos[input[i]]<len_subs)
					ans[i] = substitute[pos[input[i]]];		
			}		
			printf("%s\n",ans);
		}	
	

	///////////////////////////////////



}