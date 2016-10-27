#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define sz  10005

typedef struct{
	char a[27];
}word;

word words[sz],word1[sz];

long n;
long int binsearch(char search[],long index);
int comp1(void const *A, void const *B);
int one_letter_missing(char str[],char dic[]);
int less_word(char str[],char dic[]);
int more_word(char str[],char dic[]);
int wrong(char str[],char dic[]);
int access_dic(char str[]);
int adjacent(char x[],char b[]);


void main()
{
	char str[27];
	long i,query;
	int p=0;

	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf(" %s",str);
			strcpy(words[i].a,str);
			strcpy(word1[i].a,str);
		}

		qsort(word1,n,sizeof(word),comp1);

		scanf("%ld",&query);

		while(query>0)
		{
			scanf(" %s",str);

			p = binsearch(str,n);

			if(p!=-1)
			  printf("%s is correct\n",str);

			else
			{  p = access_dic(str);
			   
			   if(p==0)
				   printf("%s is unknown\n",str);
			}
			query--;
		}
	
	}//end of while
}//main


int access_dic(char str[])
{    
	   long i;
	   int p;
	   char dic[27];
				
				for(i=0;i<n;i++)
				{
					strcpy(dic,words[i].a);

					//printf("%s\n",dic);

					p = one_letter_missing(str,dic);
					if(p==1)
					{
						printf("%s is a misspelling of %s\n",str,dic);
						return 1;						
					}
					p = wrong(str,dic);
					if(p==1)
					{
						printf("%s is a misspelling of %s\n",str,dic);
						return 1;					
					}
					p =adjacent(str,dic);
					if(p==1)
					{
						printf("%s is a misspelling of %s\n",str,dic);
						return 1;				
					
				    }	
					
				}//end of dic for

				return 0;
}



int one_letter_missing(char str[],char dic[])
{
	int len,dic_len,p=0;

	len = strlen(str);
	dic_len = strlen(dic);
	//printf("%s %s\n",dic,str);

	if(dic_len-len==1)
	{
		//printf("%s %s\n",dic,str);
		p = less_word(str,dic);
		if(p==1)
			return 1;
	}
	else if(len - dic_len==1)
	{
	    p = more_word(str,dic);
		if(p==1)
			return 1;
	}



	return 0;

}

int wrong(char str[],char dic[])
{

	
	int len1,len2,i,p;

	len1 = strlen(str);
	len2 = strlen(dic);
	if(len1!=len2)
		return 0;

		
    

	
	p=0;

	for(i=0;i<len1;i++)
	{
		if(str[i]!=dic[i])
			p++;		
	}

	if(p==1)
		return 1;

	return 0;

}





long int binsearch(char search[],long index){ 
   long int high,low,mid; 
    
   low=0; 
   high=index-1; 
   while(low<=high)
   { 
       
      mid=(low+high)/2; 

      if(strcmp(word1[mid].a,search)>0) 
         high=mid-1; 
      else if(strcmp(word1[mid].a,search)==0)
	  {          
         return mid; 
      } 
      else 
         low=mid+1; 

   } 
    
   return -1; 

} 


int comp1(void const *A, void const *B)
{

	word *a = (word*)A;
	word *b = (word*)B;

	return (strcmp(a->a,b->a));

}

int less_word(char str[],char dic[])
{
	int len,i,j,x,len1,flag;
	char temp[27];
	len=strlen(dic);
	len1 =strlen(str);
	//printf("%s %s\n",str,dic);

	x=0;
	flag=0;
	j=0;
	for(i=0;i<len-1;i++)	
	{
		
		if(dic[i]!=str[i])
		{	
			flag=1;
			temp[x++]=dic[i];

			for(j=i;j<len1;j++)
				temp[x++] =str[j];
			break;
		}
		else
			temp[x++]=str[i];
	}

	temp[x]='\0';
	//printf("%s\n",temp);

	if(flag==0)
		return 1;
	
	if(strcmp(temp,dic)==0)
		return 1;
	return 0;

}

int more_word(char str[],char dic[])
{
	int len,i,j,x,len1,flag;
	char temp[27];
	len=strlen(dic);
	len1 =strlen(str);
	//printf("%s %s\n",str,dic);

	x=0;
	flag=0;
	j=0;
	for(i=0;i<len1-1;i++)	
	{
		
		if(dic[i]!=str[i])
		{	
			flag=1;
			temp[x++]=str[i];

			for(j=i;j<len;j++)
				temp[x++] =dic[j];
			break;
		}
		else
			temp[x++]=dic[i];
	}

	temp[x]='\0';
	//printf("%s\n",temp);

	if(flag==0)
		return 1;
	
	if(strcmp(temp,str)==0)
		return 1;
	return 0;
}



int adjacent(char x[],char b[])
{
	int len,i,on,off,len1;
	char temp,a[27];

	on=1;
	off=0;

	strcpy(a,x);
	len=strlen(x);
	len1 = strlen(b);
	if(len!=len1)return 0;

	for(i=0;i<len;i++)
	{
		if(a[i]==b[i])
			continue;

		else if((a[i] != b[i]) && on)
		{
			if(i+1<len)
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				on=off;
				i=i-1;
			}
			else
				return 0;         // wrong 
		}
		else
			break;
	}
	if(i==len)
		return 1;
	return 0;
}