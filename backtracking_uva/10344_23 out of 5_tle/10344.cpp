//Bikas
//10344 23 out of 5
//If WA change the line 
// if(result==23)  to   if(result==23 || result==-23)

#include<stdio.h>
#include<string.h>
#define MAX 8

typedef struct{
	char sign[6];
}OPERATOR;
OPERATOR operators[85];

typedef struct{
	int num[7];
}operand;
operand operands[125];

int noperands=0,noperators=0;
char a[MAX];
int b[MAX];
void permutation_operators(char a[],int k,int n);
void con_candidate_operators(char a[],int k,int n,char c[],int *ncan);
void con_candidate_operands(int a[],int k,int n,int c[],int *ncan);
void permutation_operands(int a[],int k,int n);
bool check_possible();
long result(int i,int j);
int N[MAX];

void main()
{
	int i,p;
	bool possible;
	
	memset(a,0,sizeof(a));
	permutation_operators(a,0,4);
	memset(a,0,sizeof(b));
	permutation_operands(b,0,5);

	//printf("noperators = %d\n",noperators);
	//printf("noperands = %d\n",noperands);

	while(1)
	{
		p=0;
	    for(i=1;i<=5;i++)
		{ scanf("%d",&N[i]);
		  if(N[i]!=0)
		  p=1;
		}
		if(p==0)break;

		possible = check_possible();
		if(possible)printf("Possible\n");
		else printf("Impossible\n");
	}
}


bool check_possible()
{
	long ans;
	int i,j;

	for(i=0;i<noperands;i++)
	{
		for(j=0;j<noperators;j++)
		{
			ans = result(i,j);
			
			//////////////////////////////////////////
			if(ans==23)
			//if(ans==23 || ans==-23)
			{
				//printf("ans = %ld\n",ans);
				//for(k=1;k<=4;k++)
				//printf("%d %c ",N[operands[i].num[k]],operators[j].sign[k]);
				//printf("%d\n",N[operands[i].num[5]]);
				return true;
			}
		}
	}
	return false;
}

long result(int i,int j)
{
	int k;
	long sum;

	sum = N[ operands[i].num[1] ];
	for(k=1;k<=4;k++)
	{
		if(operators[j].sign[k]=='*')
			sum = sum * N[ operands[i].num[k+1] ];
		else if(operators[j].sign[k]=='+')
			sum = sum + N[ operands[i].num[k+1] ];
		else if(operators[j].sign[k]=='-')
			sum = sum - N[ operands[i].num[k+1] ];
	}
	return sum;
}



void permutation_operators(char a[],int k,int n)
{
	int i,ncan;
	char c[MAX];

	if(k==n)
	{
		for(i=1;i<=k;i++)
		operators[noperators].sign[i] = a[i];
		noperators++;
	}
	else
	{
		k++;
		con_candidate_operators(a,k,n,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			permutation_operators(a,k,n);	
		}	
	}
}

void con_candidate_operators(char a[],int k,int n,char c[],int *ncan)
{
	*ncan = 0;
	c[(*ncan)++] = '*';
	c[(*ncan)++] = '+';
	c[(*ncan)++] = '-';
}


void permutation_operands(int a[],int k,int n)
{
	int i,ncan,c[MAX];

	if(k==n)
	{
		for(i=1;i<=k;i++)
		{
			//printf("%d ",a[i]);
			operands[noperands].num[i] = a[i];
		}
		//printf("\n");
		noperands++;
	}
	else
	{
		k++;
		con_candidate_operands(a,k,n,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			permutation_operands(a,k,n);	
		}
	}
}

void con_candidate_operands(int a[],int k,int n,int c[],int *ncan)
{

		int i;                      
        bool in_perm[MAX];             

        for (i=1; i<=n; i++) in_perm[i] = false;
        for (i=0; i<k; i++) in_perm[ a[i] ] = true;

        *ncan = 0;
		
        for (i=1; i<=n; i++) 
		{       if (in_perm[i] == false)
				{
					c[ *ncan] = i;
                    *ncan = *ncan + 1;					
                }
		}
}
