#include<stdio.h>
#include<string.h>
#define MAX_SZ 13

int low,high;
bool f1,f2,f3;
typedef struct{
	int ind[5000][13];
	int len;
	}Sub;
Sub sub[13];

void con_can(int n,int k,int a[],int c[],int *ncandidate);
void process_solution(int n,int k,int a[]);
void subset(int n,int k,int a[]);
void eliminate_trailing_space(char *number);
void eliminate_leading_space(char *number);
void print(int length,int tot);
char newspaper[15][35];


void main()
	{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int i,a[MAX_SZ],len,tot,f;
	long test;
	char input[500];
	
	for(i=0;i<=12;i++)sub[i].len=0;
	memset(a,0,sizeof(a));
	subset(12,0,a);
	
	tot=1;
	f1 = f2 = f3 = f = false;
	
	gets(input);
	sscanf(input,"%ld",&test);
	gets(input);
	
	
	
	while(gets(input))
		{
		//eliminate_leading_space(input);
		//eliminate_trailing_space(input);
		len = strlen(input);
		
		if(strlen(input)==0)
			{
			
			
			if(f1){
				for(i=1;i<tot;i++){
					if(i>1)printf("\n");
					printf("Size %d\n",i);
					print(i,tot);
					}
				}
			else if(f3){
				for(i=low;i<=high;i++){
					if(i>low)printf("\n");
					printf("Size %d\n",i);
					print(i,tot);
					}
				}
			else if(f2)
				{
				printf("Size %d\n",low);
				print(low,tot);
				}
			
			tot=1;
			f = false;
			f1=f2=f3=false;
			printf("\n\n");
			continue;
			}
		
		if(f == false && len>2)
			{
			f3 = true;
			sscanf(input,"%d %d",&low,&high);
			f = true;
			}
		else if(f == false && len<=2)
			{
			if(input[0]=='*')
				{
				f1 = true;
				}
			else 
				{
				sscanf(input,"%d",&low);
				f2 = true;
				}
			f = true;
			}
		else{
			strcpy(newspaper[tot],input);
			tot++;
			}	
		
		}
	
	if(f1){
		for(i=1;i<tot;i++){
			if(i>1)printf("\n");
			printf("Size %d\n",i);
			print(i,tot);
			}
		}
	else if(f3){
		for(i=low;i<=high;i++){
			if(i>1)printf("\n");
			printf("Size %d\n",i);
			print(i,tot);
			}
		}
	else if(f2)
		{
		printf("Size %d\n",low);
		print(low,tot);
		}
	printf("\n");
	
}



void print(int length,int tot)
	{
	int i,j,p;
	bool x;
	
	
	for(i=0;i<sub[length].len;i++)
		{
		x = true;
		for(j=1;j<=length;j++)
			{
			if(sub[length].ind[i][j]>=tot){
				x = false;
				break;
				}
			}
		if(x)
			{
			p = sub[length].ind[i][1];
			printf("%s",newspaper[p]);
			for(j=2;j<=length;j++)printf(", %s",newspaper[sub[length].ind[i][j]]);
			printf("\n");
			}
		
		}
	
	
	}	


void con_can(int n,int k,int a[],int c[],int *ncandidate){
	*ncandidate=0;
	for(int i=a[k-1]+1;i<=n;i++)
		c[(*ncandidate)++]=i;
	}
void process_solution(int n,int k,int a[]){
	int i,p;
	
	if(k>0){
		
		p=sub[k].len;
		for(i=1;i<=k;i++)
			{
			sub[k].ind[p][i] = a[i];
			//	printf("%d ",sub[k].ind[p][i]);
			
			}
		//printf("\n");
		sub[k].len++;
		
		
		}
	
	
	}

void subset(int n,int k,int a[]){
	process_solution(n,k,a);
	if(n==k)return;
	
	int i,c[MAX_SZ],ncandidate;
	
	k++;
	con_can(n,k,a,c,&ncandidate);
	for(i=0;i<ncandidate;i++){
		a[k]=c[i];
		subset(n,k,a);
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
	
	for(i = strlen(number); i >= 1 && number[i - 1] == ' '; i--) number[i - 1] = number[i];
	
	return;
	}