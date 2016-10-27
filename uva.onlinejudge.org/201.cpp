#include<stdio.h>
#include<string.h>
#define sz 12

bool H[sz][sz],V[sz][sz],one[sz][sz];
int n;
int check_size1();
int check_square(int size);

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,row,col,cases=1,dots,lines,value;
	char ch;
	bool found,start=false;

	while(scanf("%d",&dots)==1)
	{
		if(start)
			printf("\n**********************************\n\n");
		else start=true;

		memset(H,false,sizeof(H));
		memset(V,false,sizeof(V));
		memset(one,false,sizeof(one));

		n = dots;
		scanf("%d",&lines);
		for(i=0;i<lines;i++)
		{
			scanf(" %c %d %d",&ch,&row,&col);
			if(ch=='H')H[row][col]=true;
			else V[col][row]=true;		
		}

		printf("Problem #%d\n\n",cases++);
		found = false;
		for(i=1;i<=dots;i++)
		{
			if(i==1)value = check_size1();
			else value= check_square(i);

			if(value>0){
				printf("%d square (s) of size %d\n",value,i);
				found = true;
			}
		}
		if(!found)printf("No completed squares can be found.\n");
	}

	return 0;
}


int check_size1()
{
	int i,j,square=0;

	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			if(H[i][j] && V[i][j] && H[i+1][j] && V[i][j+1])
			{
				square++;
				one[i][j]=true;
			}
		}
	}
	return square;
}

int check_square(int size)
{
	int i,j,k,l,square=0;
	bool found;

	for(i=1;i<=n-size;i++)
	{
		for(j=1;j<=n-size;j++)
		{

			found=true;
			for(k=j;k<j+size;k++)
			{
				if(H[i][k]==false){
					found=false;
					break;
				}
			}
			for(k=i;k<i+size;k++)
			{
				if(V[k][j]==false){
					found=false;
					break;
				}
			}
			for(k=j;k<j+size;k++)
			{
				if(H[i+size][k]==false){
					found=false;
					break;
				}
			}
			for(k=i;k<i+size;k++)
			{
				if(V[k][j+size]==false){
					found=false;
					break;
				}
			}			
			if(found)square++;		
		}
	}
	return square;
}
