#define SIZE 100
#define LEN  10000

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct phrase
{
   char array[LEN + 1];
};

phrase string[SIZE + 1];
int  num;

int is_anagram(char *string1, char *string2);
int ascend_sort(const void* a, const void* b);

int main(void)
{
	int  i, j, test_case;
	char ch;

	scanf(" %d", &test_case);

	//This is only for ignoring the last carrige return pressed to terminate 'test_case'.
	scanf("%c", &ch);
   scanf("%c", &ch);

	while(test_case--)
   {
		for(num = 0; gets(string[num].array) != NULL && string[num].array[0] != NULL; num++);

		qsort(string, num, sizeof(phrase), ascend_sort);
		
      for(i = 0; i < num; i++)
	   {
		   for(j = i + 1; j < num; j++)
		   {
			   if (is_anagram(string[i].array, string[j].array))
			   {
				   printf("%s = %s\n", string[i].array, string[j].array);
			   }

            //This is for not counting the anagramness for the equal string again.
		      while((j + 1) < num && strcmp(string[j].array, string[j + 1].array) == 0) ++j;
		   }

         //This is for not counting the anagramness for the equal string again.
		   while((i + 1) < num && strcmp(string[i].array, string[i + 1].array) == 0) ++i;
	   }

      if (test_case != 0) printf("\n");
	}

	return(0);
}

int ascend_sort(const void* a, const void* b)
{
   phrase *temp1 = (phrase*)a, *temp2 = (phrase*)b;

   return(strcmp(temp1 -> array, temp2 -> array));
}

//Return '1' if 'string1' & 'string2' are ananagram & '0' otherwise.
int is_anagram(char *string1, char *string2)
{
	int i, repeat1[52], repeat2[52];

	//Initialize the instance of all characters in 'string1' and 'string2' with 0.
	for(i = 0; i < 52; i++) repeat1[i] = repeat2[i] = 0;

	//Find out the instance of each character in 'string1'.
	for(i = 0; string1[i] != NULL; i++)
	{
		if (string1[i] != ' ')
		{
			if (string1[i] >= 'A' && string1[i] <= 'Z') ++repeat1[string1[i] - 'A'];
			else ++repeat1[string1[i] - 'a' + 26];
      }
	}

	//Find out the instance of each character in 'string2'.
	for(i = 0; string2[i] != NULL; i++)
	{
		if (string2[i] != ' ')
		{
			if (string2[i] >= 'A' && string2[i] <= 'Z') ++repeat2[string2[i] - 'A'];
			else ++repeat2[string2[i] - 'a' + 26];
      }
	}

   //Check all the occurances.
   for(i = 0; i < 52; i++) if (repeat1[i] != repeat2[i]) break;

   if (i == 52) return(1);
   else return(0);
}