							  // Acm 713 Adding Reverse Number
							  // Solved By Bikas Cse Sust
#include<stdio.h>
#include<string.h>

#define swap(a,b) a^=b^=a^=b
#define sz 1000


void add(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);
void delete_leadingzero(char x[]);

void main()
{
		//freopen("713.txt","r",stdin);
		//freopen("out1.txt","w",stdout);

		long testCase;  
		char num1[sz],num2[sz],result[sz];

		scanf("%ld",&testCase);

		while(testCase>0)
		{

			scanf(" %s %s",num1,num2);

			if( (strcmp(num1,"0")==0) && (strcmp(num2,"0")==0) )
				printf("0\n");
			else
			{

			//delete_leadingzero(num1);
			//delete_leadingzero(num2);
			

			reverse(num1);
			reverse(num2);

			

		
			add(num1,num2,result);

			delete_leadingzero(result);
			
			reverse(result);
			delete_leadingzero(result);

			printf("%s\n",result);

			}

			testCase--;

		}

	
}



//TAKES TWO STRINGS x AND y AND PUTS THERE SUM IN ANOTHER STRING result
void add(char x[],char y[],char result[])
{

	long i,j,k,t1,t2,carry,len1,len2;
	char tem[sz];
	len1 = strlen(x);
	len2 = strlen(y);
	carry=k=0;
	for(i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
	{
			t1=t2=0;
			if(i>=0)
			t1=toint(x[i]);
			if(j>=0)
			t2=toint(y[j]);
			tem[k++]=tochar((t1+t2+carry)%10);
			carry= (t1+t2+carry)/10;

	}

	while(carry!=0)
	{
			tem[k++]=tochar(carry%10);
			carry/=10;
	}
	tem[k]='\0';
	reverse(tem);
	strcpy(result,tem);

}


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
	swap(x[i],x[j]);

	
}

long toint(char x)
{
  return (x-'0');
}


long tochar(long x)
{
  return (x+'0');
}


void delete_leadingzero(char x[])
{

	long p,len,i,j;
	char temp[sz];

	p= strlen(x);
	
	if(p==1)
		return;
	len =0;
	for(i=0;i<p-1;i++)
	{
				if(x[i]!='0')
				break;		
	}
	for(j=i;j<p;j++)
	{
		temp[len++] = x[j];	
	}

	temp[len] = '\0';		
	strcpy(x,temp);


}