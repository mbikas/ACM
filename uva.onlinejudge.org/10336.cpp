#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 105

int Row,Col,total;
int  region[sz][sz];
char color[sz][sz];

void backtrack(int a[sz][2],int k,int digit);
void con_candidate(int a[sz][2],int k,int digit,int c[sz][2],int *ncan);
int comp(void const *A, void const *B);

typedef struct{
	char ch;
	int freqs;
}ANS;
ANS ans[30];



void main()
{

	int test,i,j,p,cases=1;
	int a[sz][2],digit,freq[30];
	char r;

	scanf("%d",&test);
	

	while(test--)
	{
		scanf("%d %d",&Row,&Col);
	
		memset(freq,0,sizeof(freq));
		memset(region,false,sizeof(region));

		for(i=0;i<Row;i++)
		{
			for(j=0;j<Col;j++)
			{
				scanf(" %c",&r);
				region[i][j]=(r-96);

			}	
		}

		p=0;
		for(i=0;i<Row;i++)
		{
			for(j=0;j<Col;j++)
			{
				if( region[i][j]!=0)
				{
					memset(color,'w',sizeof(color));
					
					a[1][0] = i;
					a[1][1] = j;
					
					color[i][j]='b';
					digit = region[i][j];
					region[i][j]=0;
					backtrack(a,1,digit);
					freq[digit]++;			
					
				}			
			}		
		}

		//printf("p === %d\n",p);



		for(i=1;i<=26;i++)
		{
			//printf("%c %d\n",(i+96),freq[i]);
			if(freq[i]!=0)
			{	ans[p].ch   = i+96;
				ans[p].freqs = freq[i];	
				p++;
			}		
		}

		//for(i=0;i<p;i++)
		//	printf("%c: %d\n",ans[i].ch,ans[i].freqs);

		qsort(ans,p,sizeof(ANS),comp);


		printf("World #%d\n",cases++);

		for(i=0;i<p;i++)
			printf("%c: %d\n",ans[i].ch,ans[i].freqs);
		


	}//end of while
}//end of main



int comp(void const *A, void const *B)
{
	int diff;

	ANS *a = (ANS*)A;
	ANS *b = (ANS*)B;

	diff =  (b->freqs - a->freqs );

	if(diff<0)return -1;
	if(diff>0)return 1;

	if(b->ch>a->ch)return -1;
	if(b->ch<a->ch)return 1;
	return 0;


}

void backtrack(int a[sz][2],int k,int digit)
{
	int c[sz][2];
	int i,ncan;

	k++;
	con_candidate(a,k,digit,c,&ncan);
	for(i=0;i<ncan;i++)
	{
		a[k][0] = c[i][0];
		a[k][1] = c[i][1];
		backtrack(a,k,digit);
	}
}

void con_candidate(int a[sz][2],int k,int digit,int c[sz][2],int *ncan)
{
	int row,col,R,C;

	*ncan = 0;
	row = a[k-1][0];
	col = a[k-1][1];
	

	//upper
    R = row-1;
	C = col;
	if( (R>=0) && region[R][C]== digit && color[R][C] == 'w')
	{
		c[(*ncan)][0] = R;
		c[(*ncan)][1] = C;
		color[R][C]='b';
		region[R][C]=0;
		(*ncan)++;
		total++;
	}
	//lower    
	R = row+1;
	C = col;
	if( (R<Row ) && region[R][C]== digit && color[R][C] == 'w')
	{
		c[(*ncan)][0] = R;
		c[(*ncan)][1] = C;
		color[R][C]='b';
		region[R][C]=0;
		(*ncan)++;
		total++;
	}

	//right
    R = row;
	C = col+1;
	if( (C<Col ) && region[R][C]== digit && color[R][C] == 'w')
	{
		c[(*ncan)][0] = R;
		c[(*ncan)][1] = C;
		color[R][C]='b';
		region[R][C]=0;
		(*ncan)++;
		total++;
	}

	//left    
	R = row;
	C = col-1;
	if( (C>=0) && region[R][C]== digit && color[R][C] == 'w')
	{
		c[(*ncan)][0] = R;
		c[(*ncan)][1] = C;
		color[R][C]='b';
		region[R][C]=0;
		(*ncan)++;
		total++;
	}
}

