#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NMAX 28

long count=0;
char word[10],str[100000];


char ch[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


bool finished = false;     /* found all solutions yet? */
long is_a_solution(long a[], long k, long n);
void construct_candidates(long a[], long k, long n, long c[], long *ncandidates);
void process_solution(long a[], long k);
void backtrack(long a[], long k,long n);
void generate_permutations(long n);



void main()
{
	//freopen("417.in","r",stdin);
	//freopen("417_11.out","w",stdout);

	long n,i,ct;
	


	while(scanf(" %[^\n]",str)==1)
	{
		count=0;
		ct=0;
		finished=false;
		n = strlen(str);	

		if(n>4)ct = 17901;
		else if(n>3)ct = 2951;
		else if(n>2)ct = 351;
		else if(n>1)ct = 26;
		else if(n==1)ct=0;

		//for(i=1;i<=n;i++)
		generate_permutations(n);		
		if(finished)
			printf("%ld\n",(count+ct));
		else
			printf("0\n");
		

	
	}
}


void process_solution(long a[], long k)
{
		  long i,p=0;

		  
		  
		 for (i=1; i<=k; i++)
		 { //printf("%c",ch[a[i]-1]);
		   word[p++]= ch[a[i]-1];
		 }
		 word[p]='\0';
		 //printf("\n");
		 count++;


		 if(strcmp(word,str)==0)
		 {
			finished = true;
		 }
		 
			
		  

			

}

long is_a_solution(long a[], long k, long n)
{
        return (k == n);
}

void generate_permutations(long n)
{
        long a[NMAX],i;                    /* solution vector */

		for(i=0;i<NMAX;i++)
			a[i]=i;
        backtrack(a,0,n);
}



void backtrack(long a[], long k,long n)
{
		  long c[NMAX];        /* candidates for next position */
		  long ncandidates;             /* next position candidate count */
		  long i;                       /* counter */

        if (is_a_solution(a,k,n))
		    process_solution(a,k);
        else {
                k = k+1;
				construct_candidates(a,k,n,c,&ncandidates);
                for (i=0; i<ncandidates; i++) {
                        a[k] = c[i];
                        backtrack(a,k,n);
                        if (finished) return;   /* terminate early */
                }
        }
}

void construct_candidates(long a[], long k, long n, long c[], long *ncandidates)
{
        long i,f;                          /* counter */
		long in_perm[NMAX];             /* who is in the permutation? */

		for (i=1; i<NMAX; i++) in_perm[i] = 0;
		for (i=0; i<k; i++) in_perm[ a[i] ] = 1;

        *ncandidates = 0;
		
		for (i=1; i<=26; i++)
		{  
			if (in_perm[i] == 0)//for unique data
			{
					f=1;				
					if(k>=2 && ch[i-1]<ch[a[k-1]-1])
						f=0;
					//printf("%d",i);
					if(f==1)

                    {    c[ *ncandidates] = i;
						*ncandidates = *ncandidates + 1;
					}
			}
		}
		  /*
		if(k==2)
		{
		
			for(i=0;i<*ncandidates;i++)
				printf("%c",ch[c[i]-1]);
				printf("\n");
		}
		*/
		//printf("\n");

}



