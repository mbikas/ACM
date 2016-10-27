#include<stdio.h>
#include<string.h>
#define sz 105

char org[sz][sz],change[sz][sz];

//char consonant[]={'b',''};
char vowel[]={'a','e','i','o','u'};

int main()
{
	char word[sz];
	int i,len,n,query;
	bool found;

	while(scanf("%d %d",&n,&query)==2)
	{
		for(i=0;i<n;i++)
		scanf(" %s %s",org[i],change[i]);

		while(query--)
		{

			scanf(" %s",word);

			found = false;

			for(i=0;i<n;i++)
			{
				if(strcmp(word,org[i])==0)
				{
					printf("%s\n",change[i]);
					found = true;
					break;
				}
				
			}
			if(found)continue;
			len = strlen(word);

		

			if(word[len-1]=='y' && (word[len-2]>='a' && word[len-2]<='z') && word[len-2]!='a' && word[len-2]!='e' && word[len-2]!='i' && word[len-2]!='o' && word[len-2]!='u')
			{
				for(i=0;i<len-1;i++)printf("%c",word[i]);
				printf("ies\n");
				continue;			
			}

			//if the word ends in "o", "s","ch", "sh" or "x", append "es" to the word.
			if(word[len-1]=='o' || word[len-1]=='s' || (word[len-2]=='c' && word[len-1]=='h') || (word[len-2]=='s' && word[len-1]=='h') || word[len-1]=='x')
			{
				printf("%s",word);
				printf("es\n");
				continue;			
			}

			printf("%s",word);
			printf("s\n");


			
		
		}
		
	
	
	}
		return 0;

}

