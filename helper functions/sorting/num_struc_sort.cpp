
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	
	char c[100];
}word;
word words[20];

int comp(void const *A, void const *B);

void main()
 {	
	int n,i;
	
	while( scanf("%d",&n)==1)
	 {
		for(i=0;i<n;i++)
		scanf (" %s",words[i].c);

		qsort(words,n,sizeof(word),comp);

		for(i=0;i<n;i++)
		printf("%s\n",words[i].c);

	 }

}




int comp(void const *A, void const *B)
{

	word *a = (word*)A;
	word *b = (word*)B;

	long lena=strlen(a->c),flag;
 	long lenb=strlen(b->c);

	if( (a->c[0]=='-')^(b->c[0]=='-'))return a->c[0]-b->c[0];
	
	if(lena!=lenb)flag=lena-lenb;
 	else flag=strcmp(a->c,b->c);
 	if(a->c[0]=='-')flag*=-1;
	return flag;



}