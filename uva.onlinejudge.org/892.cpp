#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define swap(a,b) a^=b^=a^=b
#define sz 200

void reverse(char x[]);

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int i,j,len,ct,total;
	char line[sz],ans[sz],pre[sz];
	ct=0;

	while(gets(line))
	{
		if(strcmp(line,"#")==0)break;
		
		len = strlen(line);
		total=j=0;
		

		if(ct!=0)
		{
			for(j=0;j<len;j++)
			{
				if(line[j]==' ')
				{
					pre[ct]='\0';
					printf("%s\n",pre);
					ct=0;
					break;
				}
				if(isalpha(line[j]))pre[ct++]=line[j];
			}
		
		}

		for(i=j;i<len;i++)
		{
			if(isalpha(line[i]) || line[i]==' '){
				ans[total++]=line[i];
			}
			else
			{
				if(line[i]=='-')
				{
					while(ans[total-1]!=' ')
					{
					    pre[ct++]=ans[total-1];
						total--;
					}
					pre[ct]='\0';
					reverse(pre);
				}			
			}		
		}
		//ans[total++]='X';
		ans[total]='\0';
		printf("%s\n",ans);
	
	}

	return 0;
}


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}