#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 100000

typedef struct{
	char word[30];
}IGNORE;
IGNORE ignore[550];
int ct=0;


typedef struct{
	char key[20];
	char line[10005];
}WORD;
WORD word[505];
int total=0;


int comp(const void* A, const void* B);
int comp1(const void* A, const void* B);
int binsearch(char search[]);
void bubble_sort();

int main()


{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char str[sz],temp[sz],upper[sz],lower[sz],store[sz],test[sz];
	int val,x,len,i,j,ind;
	
	ct=0;
	while(scanf(" %s",str)==1)
	{
		if(strcmp(str,"::")==0)break;
		strcpy(ignore[ct].word,str);
		ct++;
	}
	qsort(ignore,ct,sizeof(IGNORE),comp);
	
	while(scanf(" %[^\n]",str)==1)
	{
		
		len = strlen(str);
		x=0;
		
		for(i=0;i<len;i++)
		{
			if(str[i]>='a' && str[i]<='z')
				upper[i]=str[i] - 32;
			else upper[i]=str[i];
			
			if(str[i]>='A' && str[i]<='Z')
				lower[i]=str[i] + 32;
			else lower[i]=str[i];
		}
		upper[len]='\0';
		lower[len]='\0';
		
		ind=0;
		
		for(i=0;i<=len;i++)
		{
			store[ind++]=lower[i];
			if(str[i]==' ' || str[i]=='\0')
			{
				//if(i==len)ind--;
				temp[x]='\0';
				val = binsearch(temp);
				if(val==-1)
				{
					store[ind]='\0';
					strcpy(test,store);
					
					for(j=ind-2;j>=0;j--)
					{
						if(test[j]==' ')break;
						test[j] = test[j]-32;						
					}
					
					for(j=i+1;j<len;j++)test[j]=lower[j];
					test[len]='\0';
					strcpy(word[total].key,temp);
					strcpy(word[total].line,test);
					total++;
				}
				x=0;			
			}
			else
			{
				temp[x]=lower[i];				
				x++;
			}
			
		}
	}
	
	//for(i=0;i<total;i++)
	//printf("%s\n",word[i].line);	
	//printf("--------------------------------------\n");
	
	bubble_sort();
	for(i=0;i<total;i++)
	printf("%s\n",word[i].line);
	
	return 0;
}


int comp(const void* A, const void* B)
{
	IGNORE *a=(IGNORE*)A;
	IGNORE *b=(IGNORE*)B;
	
	return(strcmp(a->word,b->word));
	
}



void bubble_sort()
{  
	
	int i,j;
	char temp[sz];
	
	
    for(i=1;i<total;i++)
	{  
		for(j=0;j<total-i;j++)
		{
			if(strcmp(word[j].key,word[j+1].key)>0)
			{ 
				strcpy(temp,word[j].key);
				strcpy(word[j].key,word[j+1].key);
				strcpy(word[j+1].key,temp);
				
				strcpy(temp,word[j].line);
				strcpy(word[j].line,word[j+1].line);
				strcpy(word[j+1].line,temp);	
				
				
			}
		}
	}
    
}







int comp1(const void* A, const void* B)
{
	WORD *a=(WORD*)A;
	WORD *b=(WORD*)B;
	
	int x=strcmp(a->key,b->key);
	//if(x==0)return strcmp(a->line,b->line);
	if(x<1)return -1;
	if(x>1)return 1;
	return 0;
}



int binsearch(char search[]){ 
	int high,low,mid; 
    
	low=0; 
	high=ct-1; 
	while(low<=high){ 
		
		mid=(low+high)/2; 
		
		if(strcmp(ignore[mid].word,search)>0) 
			high=mid-1; 
		else if(strcmp(ignore[mid].word,search)==0){ 
			
			return mid; 
		} 
		else 
			low=mid+1; 
	} 
    return -1; 
} 