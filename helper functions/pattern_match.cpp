#include<stdio.h>
#include<string.h>

#define sz 100

char str1[sz],str2[sz];

long pattern_match(char str1[],char str2[]);

void main()
{
	long index;

	while(scanf(" %s %s",str1,str2)==2)
	{
		index=pattern_match(str1,str2);
		printf("%s is in index %ld\n",str2,index);

	 }

}

long pattern_match(char str1[],char str2[])
{
		char *p;
		long index;

      //pointer to pattern of str2 in str1
		//If pattern is not available NULL to (p)
		p=strstr(str1,str2);

		if(p)
		 {
			//printf(p);
			//index of pattern in str1
			index=p-str1;
		 }
		else
		 {
			//Ifpattern is not available
			index=-1;
		 }

		return index;


}

