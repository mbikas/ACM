#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 100

void sub_string(int length,char str[]);
void add(char str[]);



typedef struct{
	char ch[sz];
} sub;
sub substrings[100]; //1700
int ct=0;

void main()
{
	 char str[sz];
	 int i,j,len,length;


	 while(scanf(" %s",str)==1)
	 {
				len = strlen(str);
				for(i=1;i<=len;i++)
				{     ct=0;

						length = i;
						sub_string(length,str);

                        printf("subtrings of length %d\n",length);
						for(j=0;j<ct;j++)
						printf("%s\n",substrings[j].ch);
						printf("--\n");

				}




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

		if(length==1)
		return;


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



