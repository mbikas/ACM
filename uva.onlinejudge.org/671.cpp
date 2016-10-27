#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 16

typedef struct{
	char word[sz];
}DIC;
DIC dic[10002],dic_sort[10002];
long n=0;

int comp(void const *A, void const *B);
int comp_char(void const *A, void const *B);
long int binsearch(char search[]);
void check_replacement(char str[]);

void main()
{
	long test,i,j;
	char newline[sz],str[sz];

	scanf("%ld\n",&test);

	while(test--)
	{

		n=0;

		while( gets(str))
		{
			if(strcmp(str,"#")==0)break;
			strcpy(dic[n].word,str);
			strcpy(dic_sort[n].word,str);
			n++;
		}

		qsort(dic_sort,n,sizeof(DIC),comp);

		while( gets(str))
		{
			if(strcmp(str,"#")==0)break;

			if(binsearch(str)!=-1)
				printf("%s is correct\n",str);
			else
			{
				printf("%s:",str);
				check_replacement(str);
				printf("\n");		
			}
			


		}



		if(test>0)
		{	
			gets(newline);
			printf("\n");
		}
	}



}

void check_replacement(char str[])
{
	long i,j,k,p,len_org,len_dic,diff;
	char temp[sz],str1[sz],temp1[sz];

	len_org = strlen(str);

	for(i=0;i<n;i++)
	{
		strcpy(temp,dic[i].word);

		len_dic=strlen(temp);

		diff = abs(len_org - len_dic);
		
		if(diff>1)continue;
		if(diff==0) //replacing one letter
		{

			strcpy(str1,str);
			strcpy(temp1,temp);

			//qsort(str1,len_org,sizeof(str1[0]),comp_char);
			//qsort(temp1,len_dic,sizeof(temp1[0]),comp_char);

			p = 0 ;

			for(j=0;j<len_org;j++)
			{
				if(str1[j]!=temp1[j])
					p++;
				if(p>1)break;
			}

			if(p==1)printf(" %s",temp);		
		  continue;
		}
		if(diff==1)
		{
			if(len_org>len_dic)//deleting one letter from given word
			{
				strcpy(str1,str);
				strcpy(temp1,temp);
				
				for(j=0;j<len_org;j++)
				{
					if(str1[j]!=temp1[j])
					{
						temp1[j] = str1[j];
						for(k=j;k<len_dic;k++)
							temp1[k+1]=temp[k];
						temp1[len_org]='\0';
						break;
					}				
				}
				if(strcmp(temp1,str1)==0)printf(" %s",temp);		
			}
			else //inserting one letter into given word
			{
				strcpy(str1,str);
				strcpy(temp1,temp);
				
				for(j=0;j<len_dic;j++)
				{
					if(str1[j]!=temp1[j])
					{
						str1[j] = temp1[j];
						for(k=j;k<len_org;k++)
							str1[k+1]=str[k];
						str1[len_dic]='\0';
						break;
					}				
				}
				if(strcmp(str1,temp1)==0)printf(" %s",temp);	
			
			}		
			continue;
		}
	
	
	
	}




}



int comp(void const *A, void const *B)
{

	DIC *a = (DIC*)A;
	DIC *b = (DIC*)B;

	return (strcmp(a->word,b->word));

}


long int binsearch(char search[]){ 
   long int high,low,mid; 
    
   low=0; 
   high=n-1; 
   while(low<=high){ 
       
      mid=(low+high)/2; 

      if(strcmp(dic_sort[mid].word,search)>0) 
         high=mid-1; 
      else if(strcmp(dic_sort[mid].word,search)==0){ 
          
         return mid; 
      } 
      else 
         low=mid+1; 


   } 
    
   return -1; 


} 



int comp_char(void const *A, void const *B)
{

	char *a = (char*)A;
	char *b = (char*)B;

	return *a - *b;

}