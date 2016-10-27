#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(a,b) a^=b^=a^=b
#define sz 100

void sub_string(int length,char str[]);
int check_palindrome(int ct);
void reverse(char x[]);
void add(char str[]);
int check_unique(char str[]);
int comp(void const *A, void const *B);


typedef struct{
	char ch[sz];
} sub;
sub substrings[1700]; 
int ct=0;

void main()
{
	 char str[sz];
	 int i,j,p,len,length;
	 long palindrome;

	 while(scanf(" %s",str)==1)
	 {
				len = strlen(str);
				palindrome=0;

				p = check_unique(str);
				//printf("p = %d\n",p);
				palindrome  = p;

				for(i=2;i<=len;i++)
				{     ct=0;

						length = i;
						sub_string(length,str);

						p = check_palindrome(ct);

						palindrome +=p;


						//for(j=0;j<ct;j++)
						//printf("%s\n",substrings[j].ch);
						//printf("--\n");

				}

				printf("The string '%s' contains %ld palindromes.\n",str,palindrome);


	 }//end of while
}//end of main

void sub_string(int length,char str[])
{
		int p,len,ind,x,i,k,palindrome=0,j;
		char temp[sz];

		
		len = strlen(str);


		j=0;

		for(i=len;i>0;i--)
		{
			if(i<length)
			 break;
			p = i/length;
			ind =j;

			//	printf("len =%d -- sub = %d\n",i,p);


         while(p>0)
			{  	x=0;
					for(k=ind;k<(ind+length);k++)
					temp[x++]=str[k];
					temp[x]='\0';
					add(temp);
					//printf("%s\n",temp);

					ind = k;

					p--;
			}
			j++;

		}
		


}

void add(char str[])
{
  int i;
  for(i=0;i<ct;i++)
  {
		if( strcmp(substrings[i].ch,str)==0)
		 return;
  }
  strcpy(substrings[ct].ch,str);
  ct++;
  return;


}



 int check_palindrome(int ct)
 {
	 char str1[sz];
	 int i,n=0;

	 for(i=0;i<ct;i++)
	 {
			strcpy(str1,substrings[i].ch);
			reverse(str1);

			if(strcmp(str1,substrings[i].ch)==0)
			n++;

	}

	return n;
 }

void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}

int check_unique(char str[])
{

  int len,i,j,p;
  char str1[sz],ch;
  len = strlen(str);
  strcpy(str1,str);

  qsort(str1,len,sizeof(str1[0]),comp);

  p=0;

  for(i=0;i<len;i++)
  {
	  ch = str1[i];
	  for(j=i+1;j<len;j++)
	  {
		 if(ch==str1[j])
		  str1[j]=NULL;
		 else
		  { i = j-1;
			 break;
		  }
	  }
  }
	

  for(i=0;i<len;i++)
  {
		if(str1[i]!='\0')
		p++;
  }



  return p;
}



int comp(void const *A, void const *B)
{

	char *a = (char*)A;
	char *b = (char*)B;

	return *a - *b;

}


