#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	//freopen("b.out","w",stdout);

	char line[1000],word[100],temp[500];
	long test,len,c,cases=1,i,j,p;
	bool f=false;

	gets(word);
	sscanf(word,"%ld",&test);
	gets(word);
	while(test--)
	{
		//gets(word);
		if(f)printf("\n");
		else f = true;
		printf("Case #%ld:\n",cases++);
		while(gets(word))
		{
			len=strlen(word);
			if(len==0)
				break;
			//printf("%s\n",word);
			c=1;
			p = 0;
			word[len]=' ';
			for(i=0;i<=len;i++)
			{
				if(word[i]!=' ')temp[p++]=word[i];
				else
				{
					temp[p]='\0';
					if(p>=c)
					{
						printf("%c",temp[c-1]);
						c++;
					}
					p=0;

					//printf("%s\n",temp);
				
				}
			}

			printf("\n");


		}

		
	

	}


}