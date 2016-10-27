//acm 630 Anagrams (II)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comp(void const *A, void const *B);
int check_anagram(char word1[],char word2[])
{
	char a[30],b[30];
	int len1,len2,i;
	len1 = strlen(word1);
	len2 = strlen(word2);

	if(len1!=len2)
		return 0;

	//printf("%d %d\n",len1,len2);

	strcpy(a,word1);
	strcpy(b,word2);
	
	
	qsort(a,len1,sizeof(a[0]),comp);
	//a[len1] = '\0';
	
	
	
	qsort(b,len2,sizeof(b[0]),comp);
	//b[len2] = '\0';

	//printf("%s %s\n",word1,word2);

	if(strcmp(a,b)==0)
	return 1;

	return 0;
	
}

int comp(void const *A, void const *B)
{

	char *a = (char*)A;
	char *b = (char*)B;

	return *a - *b;
}
void main()
{

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int m,n,count,total,count2;
	char word[1005][25],tword[30];
	scanf("%d",&m);
	for(count=0;count<m;count++)
	{
		scanf("%d",&n);
		for(count2=0;count2<n;count2++)
			scanf("%s",word[count2]);

		while(scanf("%s",tword)==1)
		{
			if(strcmp(tword,"END")==0)
				break;

			total=0;
			printf("Anagrams for: %s\n",tword);
			for(count2=0;count2<n;count2++)
			{
				if(check_anagram(word[count2],tword))
				{
					total++;
					printf("%3d) %s\n",total,word[count2]);
				}
			}

			if(total==0)
				printf("No anagrams for: %s\n",tword);
		}


		if(count<m-1)
			printf("\n");
	}

	//scanf(" %s",tword);
}