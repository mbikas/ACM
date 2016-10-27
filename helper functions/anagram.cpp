#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define sz 30


int check_anagram(char word1[],char word2[]);
int comp(void const *A, void const *B);

void main()
{
	char word1[sz],word2[sz];
	int p;
	

	while( scanf(" %s %s",word1,word2)==2)
	{
	  

	  p = check_anagram(word1,word2);

	  if(p==1)
		  printf("%s = %s  -> anagram\n",word1,word2);
	  else
	      printf("%s = %s  -> not anagram\n",word1,word2);
	
	}//end of while

}//end of main


/////////return 1 if anagram ////////
//////// return 0 if not/////////////
int check_anagram(char word1[],char word2[])
{
	char a[sz],b[sz];
	int len1,len2,i;
	len1 = strlen(word1);
	len2 = strlen(word2);

	if(len1!=len2)
		return 0;

   
	for(i=0;i<len1;i++)
    a[i] = tolower(word1[i]);
	
	qsort(a,len1,sizeof(a[0]),comp);
	a[len1] = '\0';
	
	for(i=0;i<len2;i++)
    b[i] = tolower(word2[i]);
	
	qsort(b,len2,sizeof(b[0]),comp);
	b[len2] = '\0';

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
