#include<stdio.h>
#include<string.h>
#define sz 10

long count=0;
long total=0;
long ans[500];

int temp [362980][10];
void precalculation();
bool check_turnaround(int temps[],int n);


void con_can(int n,int k,int a[],int c[],int *ncandidate)
{
	int i;
	*ncandidate=0;
	bool used[10];

	memset(used,false,sizeof(used));
	
	for(i=1;i<k;i++)used[a[i]]=true;
	for(i=1;i<=9;i++)
	{
		if(used[i]==false)
			c[(*ncandidate)++]=i;
	}
}

void perm(int n,int k,int a[])
{
	int i,c[sz],ncandidate;
	
	if(k==n)
	{
		/*for(i=1;i<=k;i++)
		printf("%d ",a[i]);
		printf("\n");
		*/
		for(i=1;i<=k;i++)
		temp[total][i]=a[i];
		total++;

		
	}
	else
	{
		
		
		k++;
		con_can(n,k,a,c,&ncandidate);
		for(i=0;i<ncandidate;i++)
		{
			a[k]=c[i];
			perm(n,k,a);
		}
	}
}


int main()
{
	int i;
	long n,cases=1;
	

	precalculation();
	
	while(scanf("%ld",&n)==1 && n)
	{
		for(i=0;i<count;i++)
		{
			if(ans[i]>=n)
			{
				printf("Case %ld: %ld\n",cases++,ans[i]);
				break;
			}
		}	
	}

	return 0;
	
	
}

void precalculation()
{
	int a[10],n,i,j;
	count=0;
	char num[10];

	for(n=1;n<=9;n++)
	{
		total=0;
		perm(n,0,a);	
		
		for(i=0;i<total;i++)
		{
			if( check_turnaround(temp[i],n) )
			{
				for(j=1;j<=n;j++)num[j-1]=(temp[i][j]) + '0';
				num[n]='\0';
				sscanf(num,"%ld",&ans[count]);
				count++;
			}		
		}		
	}
}

bool check_turnaround(int temps[],int n)
{

		int digits,x,y,ct,i;
		bool digit[10];

		//for(i=1;i<=n;i++)printf("%d ",temps[i]);
		memset(digit,false,sizeof(digit));

		for(i=1;i<=n;i++)digit[temps[i]]=true;


		digits=0;
		ct=temps[1];
		x=1;
		y=2;
		while(1)
		{
			while(x<ct)
			{
				x++;
				y++;
				if(y==n+1)y=1;				
			}

			if(digit[temps[y]]==false)return false;
			else
			{
				digits++;
				if(digits==n)return true;
				digit[temps[y]]=false;
				ct = temps[y];
				y = y+1;
				if(y>n)y=1;
				x=1;				
			}	
		}
}