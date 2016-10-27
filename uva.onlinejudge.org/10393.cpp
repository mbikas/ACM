#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//char finger[12][7];

char finger[12][8]={	{' '},{'q','a','z'},{'w','s','x'},{'e','d','c'},{'r','f','v','t','g','b'},{' '},
				{' '},{'y','h','n','u','j','m'},{'i','k',','},{'o','l','.'},{'p',';','/'}
			};
char ans[1001][51];
char ans1[1001][51];
bool can_type[130];

int comp(void const *A, void const *B)
{

	char *a = (char*)A;
	char *b = (char*)B;
	return (strcmp(a,b));

}


int main()
{
	bool possible;
	char word[55];
	int p,len,i,j,n,total,f;

	while(scanf("%d %d",&f,&n)==2)
	{
		//printf("%d\n",strlen(finger[f]));
		memset(can_type,true,sizeof(can_type));
		for(i=0;i<f;i++)
		{
			scanf("%d",&p);
			len = strlen(finger[p]);
			for(j=0;j<len;j++)
			{
				can_type[finger[p][j]]=false;		
			}
		}

		
		total=0;
		for(i=0;i<n;i++)
		{
			possible = true;
			scanf(" %s",word);
			len = strlen(word);
			for(j=0;j<len;j++)
			{
				if(can_type[word[j]]==false)
				{
					possible = false;
					break;
				}		
			}

			if(possible)
			{
				j = strlen(ans[total-1]);
				if(len>j)
				{
					total=0;
					strcpy(ans[total],word);
					total++;
				}
				if(len==j)
				{
					strcpy(ans[total],word);
					total++;				
				}
				//printf("%s\n",word);
				
			}
		}
		qsort(ans,total,sizeof(ans[0]),comp);

		n=0;
		if(total>0){
			strcpy(ans1[0],ans[0]);
			n=1;
		}
		for(i=1;i<total;i++)
		{
			if(strcmp(ans[i],ans[n-1])!=0)
			{
				strcpy(ans1[n],ans[i]);
				n++;				
			}
		}



		printf("%d\n",n);
		for(i=0;i<n;i++)
		printf("%s\n",ans[i]);


	
	}

	return 0;
}