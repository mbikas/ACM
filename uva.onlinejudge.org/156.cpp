#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define sz 100

typedef struct{
   char word[sz];
   int flag;

}Dictionary;
Dictionary dic[1005];

int nword=0;

void check_word(char word[]);
int check_anagram(char word1[],char word2[]);
int comp(void const *A, void const *B);
int comp1(void const *A, void const *B);
void output();

void main()
{
	char word[sz];
	

	while( scanf(" %s",word)==1)
	{
	  if(strcmp(word,"#")==0)
	  {
	    output();
		break;	  
	  }

	  check_word(word);
	
	
	}//end of while

}//end of main



void check_word(char word[])
{
	int i,flag=1,valid;

	
	for(i=0;i<nword;i++)
	{   
		    flag =1;
         
		
			valid = check_anagram(dic[i].word,word);

			if(valid==1)
			{	flag=0;
				dic[i].flag = 0;
				break;
			}
		
	}

	if(flag==1)
	{
	  
	  strcpy( dic[nword].word,word);
	  dic[nword].flag = 1;
	  nword++;	
	}






}

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

	//printf("%d %d\n",len1,len2);

   
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

void output()
{
    int i;
	qsort(dic,nword,sizeof(Dictionary),comp1);

	for(i=0;i<nword;i++)
	{  if(dic[i].flag==1)
	    printf("%s\n",dic[i].word);
	}



}

int comp1(void const *A, void const *B)
{

	Dictionary *a = (Dictionary*)A;
	Dictionary *b = (Dictionary*)B;

	return ( strcmp(a->word, b->word) );
	
}