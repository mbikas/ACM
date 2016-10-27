#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define sz 8000
#define MAX 15

typedef struct{
	char name[40];
}NEWS;
NEWS news[14];

typedef struct{
	long b[sz];
	long total;  
}ANS;
ANS ans[MAX];
long t=0;

bool finished = false;     
void construct_candidates(long a[], long k, long n, long c[], long *ncandidates);
void construct_candidates3(long a[], long k, long n, long c[], long *ncandidates);
void process_solution(long a[], long k);
void backtrack1(long a[], long k,long n);
void backtrack2(long a[], long k,long n);
void backtrack3(long a[], long k,long n);
void print(long low,long high);
long low,high;
void eliminate_leading_space(char *number);
void eliminate_trailing_space(char *number);

void main()
{

	//freopen("598.in","r",stdin);
	//freopen("out1.txt","w",stdout);

	long test,n,f=0,len,i,nline=0;
	long a[MAX];	
	
	char str[100];

	gets(str);

	sscanf(str,"%ld",&test);
	gets(str);

	while(test--)
	{
		if(nline==1)printf("\n");
		else nline=1;
		n = -1;
		f=0;
		while(gets(str))
		{
			len = strlen(str);
			if(len==0)
				break;
			if(n==-1)
			{
				//printf("%s\n",str);
				eliminate_leading_space(str);
				eliminate_trailing_space(str);
				len = strlen(str);
				if(len==1)
				{
					if(str[0]=='*')
						f = 1;
					else
					{
						f=2;
						low = str[0]-'0';			
					}
				}
				else
				{	
					f=3;
					sscanf(str,"%d %d",&low,&high);
				}
			}
			else
				strcpy(news[n].name,str);
			n++;
		
		}//end of taking input of a case

		finished = false;
		for(i=0;i<=n;i++)
			a[i]=i;
		if(f==1)
		{
			t=0;
			for(i=0;i<=n;i++)
				ans[i].total=0;
			backtrack1(a,0,n);
			print(1,n);			
		}
		else if(f==2)
		{
			printf("Size %d\n",low);
			backtrack2(a,0,n);			
		}
		else
		{
			t=0;
			for(i=0;i<=n;i++)
				ans[i].total=0;
			backtrack3(a,0,n);
			print(low,high);
		}

	
	}//while
}//main


void process_solution(long a[], long k)
{
        long i;                         
		

		//for(i=1;i<=k;i++)printf("%d ",a[i]);
		//printf("\n");
        for (i=1; i<k; i++) 
		printf("%s, ",news[a[i]].name);
		printf("%s\n",news[a[k]].name);			
}



void backtrack3(long a[],long k,long n)
{
        long c[MAX];        
        long ncandidates;            
        long i,j,old;

		if(k>high)
		{
			finished = true;
			return;
		}

		
		if(k>=low && k<=high)
		{
			old = ans[k].total;
			ans[k].total +=k;
			j = old;
			for(i=1;i<=k;i++)
			{	ans[k].b[j] = a[i];
				j++;
			}
		}
		k = k+1;		
		construct_candidates3(a,k,n,c,&ncandidates);
        for (i=0; i<ncandidates;i++) 
		{
			a[k] = c[i];
            backtrack1(a,k,n);
			if(finished)return;
        }
}

void construct_candidates3(long a[], long k, long n, long c[], long *ncandidates)
{
        long i,f,j;                         
        bool in_perm[MAX]; 
		

		if(k>high)
			return;
		
		for (i=0; i<=n; i++) in_perm[i] = false;
        for (i=1; i<k; i++) in_perm[ a[i] ] = true;

		*ncandidates = 0;
		for (i=0; i<n; i++) 
		{       if (in_perm[i] == false)
				{
						
						if(k==1)
						{
							f=1;
							for(j=0;j<*ncandidates;j++)
							{
								if(strcmp(news[i].name,news[c[j]].name)==0)
								{
									f=0;
									break;							
								}
							}
							if(f==1)
								c[(*ncandidates)++]=i;						
						}
			
						else if(k>1 && i>a[k-1])
						{
							f=1;
							for(j=0;j<*ncandidates;j++)
							{
								if(strcmp(news[i].name,news[c[j]].name)==0)
								{
									f=0;
									break;							
								}
							}
							if(f==1)
								c[(*ncandidates)++]=i;	
						
						}				
                }
		}
		
}



void backtrack1(long a[],long k,long n)
{
        long c[MAX];        
        long ncandidates;            
        long i,j,old;
		
		if(k>=1)
		{
			old = ans[k].total;
			ans[k].total +=k;
			j = old;
			for(i=1;i<=k;i++)
			{	ans[k].b[j] = a[i];
				j++;
			}
		}
		k = k+1;		
		construct_candidates(a,k,n,c,&ncandidates);
        for (i=0; i<ncandidates;i++) 
		{
			a[k] = c[i];
            backtrack1(a,k,n);			
        }
}

void backtrack2(long a[],long k,long n)
{
        long c[MAX];        
        long ncandidates;            
        long i;                      

        if(k==low)
		 process_solution(a,k);
		else
		{
       
			k = k+1;
		
			construct_candidates(a,k,n,c,&ncandidates);
			for (i=0; i<ncandidates; i++) 
			{
				a[k] = c[i];
				backtrack2(a,k,n);			
			}
		}
}

void construct_candidates(long a[], long k, long n, long c[], long *ncandidates)
{
        long i,f,j;                         
        bool in_perm[MAX];        
		
		for (i=0; i<=n; i++) in_perm[i] = false;
        for (i=1; i<k; i++) in_perm[ a[i] ] = true;

		*ncandidates = 0;
		for (i=0; i<n; i++) 
		{       if (in_perm[i] == false)
				{
						
						if(k==1)
						{
							f=1;
							for(j=0;j<*ncandidates;j++)
							{
								if(strcmp(news[i].name,news[c[j]].name)==0)
								{
									f=0;
									break;							
								}
							}
							if(f==1)
								c[(*ncandidates)++]=i;						
						}
			
						else if(k>1 && i>a[k-1])
						{
							f=1;
							for(j=0;j<*ncandidates;j++)
							{
								if(strcmp(news[i].name,news[c[j]].name)==0)
								{
									f=0;
									break;							
								}
							}
							if(f==1)
								c[(*ncandidates)++]=i;	
						
						}				
                }
		}
		
}

void print(long low,long high)
{

	long i,j;
	long p;
	bool flag[MAX];

	for(i=0;i<=MAX;i++)flag[i]=true;

	for(i=low;i<=high;i++)
	{
		if(i==low)
			printf("Size %d\n",i);
		else
		{	printf("\n");
			printf("Size %d\n",i);
		}

		p=1;
		for(j=0;j<ans[i].total;j++)
		{
			if(p%i==0)
				printf("%s\n",news[ans[i].b[j]].name);
			else
				 printf("%s, ",news[ans[i].b[j]].name);
			p++;
		}
	

	}
}


void eliminate_leading_space(char *number)
{
	int i, j;

   //Discard leading zeros.
   for(i = 0; number[i] == ' '; i++);

   //If 'number' consists only of '0's.
   if (number[i] == NULL) --i;

   //Launch the digits other than leading zeros.
   for(j = 0; number[i] != NULL; i++, j++) number[j] = number[i];

   number[j] = NULL;

	return;
}

void eliminate_trailing_space(char *number)
{
	int i;

   for(i = strlen(number); i >= 2 && number[i - 1] == ' '; i--) number[i - 1] = number[i];

	return;
}



