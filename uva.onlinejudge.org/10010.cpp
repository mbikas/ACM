#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
	char col[52];
}ROW;
ROW row[52];

char str[10000],ch;
bool check_row_right(long r,long c,long len1,long rows);
bool check_row_left(long r,long c,long len1,long rows);
bool check_col_down(long r,long c,long len1,long rows);
bool check_col_up(long r,long c,long len1,long rows);
bool check_right_up(long r,long c,long len1,long rows);
bool check_left_up(long r,long c,long len1,long rows);
bool check_right_down(long r,long c,long len1,long rows);
bool check_left_down(long r,long c,long len1,long rows);

void main()
{
	
	long i,j,query,test,r,c,f,len,len1,ff=0;
	bool flag;

	scanf("%ld",&test);

	while(test--)
	{

		if(ff==1)printf("\n");
		else ff=1;
		scanf("%ld %ld",&r,&c);

		for(i=0;i<r;i++)
		{
			scanf(" %[^\n]",row[i].col);
			len = strlen(row[i].col);
			for(j=0;j<len;j++)
			row[i].col[j] = tolower(row[i].col[j]);
		}


		scanf("%ld",&query);
		while(query--)
		{
			scanf(" %[^\n]",str);
			len1 = strlen(str);
			for(i=0;i<len1;i++)
			str[i] = tolower(str[i]);
			
			ch = str[0];
			f=0;
			for(i=0;i<r;i++)
			{
				len = strlen(row[i].col);
				for(j=0;j<len;j++)
				{	if(row[i].col[j]==ch)
					{	flag = check_row_right(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}
						flag = check_row_left(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}
						flag = check_col_down(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}
						flag = check_col_up(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}

						flag = check_row_right(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}

						flag = check_right_up(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}

						flag = check_left_up(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}

						flag = check_right_down(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}
						flag = check_left_down(i,j,len1,r);
						if(flag)
						{
							printf("%ld %ld\n",i+1,j+1);
							f=1;
							break;
						}

					}				
				}
				if(f==1)break;
			}
		}
	
	
	
	}//while
}//main


bool check_row_right(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);	
	x = len - c;
	if(x<len1)return false;
	
	j=0;
	for(i=c;i<len;i++)
	{
		if(row[r].col[i]!=str[j])return false;
		j++;
		if(j==len1)break;	
	}
	return true;
}

bool check_row_left(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);	
	x = c+1;
	if(x<len1)return false;
	
	j=0;
	for(i=c;i>=0;i--)
	{
		if(row[r].col[i]!=str[j])return false;
		j++;
		if(j==len1)break;	
	}
	return true;
}


bool check_col_down(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);	
	x = rows - r;
	if(x<len1)return false;
	
	j=0;
	for(i=r;i<rows;i++)
	{
		if(row[i].col[c]!=str[j])return false;
		j++;
		if(j==len1)break;	
	}
	return true;
}

bool check_col_up(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);	
	x = r+1;
	if(x<len1)return false;
	
	j=0;
	for(i=r;i>=0;i--)
	{
		if(row[i].col[c]!=str[j])return false;
		j++;
		if(j==len1)break;	
	}
	return true;
}


bool check_right_up(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);
	x = r+1;
	if(x<len1)return false;
	x = len-c;
	if(x<len1)return false;
	
	j=0;
	for(i=r;i>=0;i--)
	{
		if(row[i].col[c]!=str[j])return false;
		j++;
		c++;
		if(j==len1)break;	
	}
	return true;
}

bool check_left_up(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);
	x = r+1;
	if(x<len1)return false;
	x = c+1;
	if(x<len1)return false;
	
	j=0;
	for(i=r;i>=0;i--)
	{
		if(row[i].col[c]!=str[j])return false;
		j++;
		c--;
		if(j==len1)break;	
	}
	return true;
}


bool check_right_down(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);
	x = len-c;
	if(x<len1)return false;
	x = rows-r;
	if(x<len1)return false;
	
	j=0;
	for(i=r;i<rows;i++)
	{
		if(row[i].col[c]!=str[j])return false;
		j++;
		c++;
		if(j==len1)break;	
	}
	return true;
}

bool check_left_down(long r,long c,long len1,long rows)
{
	long len,x,i,j;

	len = strlen(row[r].col);
	x = c+1;
	if(x<len1)return false;
	x = rows-r;
	if(x<len1)return false;
	
	j=0;
	for(i=r;i<rows;i++)
	{
		if(row[i].col[c]!=str[j])return false;
		j++;
		c--;
		if(j==len1)break;	
	}
	return true;
}