#include<stdio.h>
#include<string.h>
#define sz 500
#define swap(a,b) a^=b^=a^=b


void reverse(char x[]);
void base_summation(char num1[],char num2[], char result[],int base);

void main()
{
	char result[sz],num1[sz],num2[sz];

	int base;
	
	
	while(scanf(" %s %s %d",num1,num2,&base)==3)
	{
	

	
		base_summation(num1,num2,result,base);
		
		printf("%s\n",result);
		
	
	
	
	}




}

void base_summation(char num1[],char num2[], char result[],int base)
{
	char temp[sz];
	int x=0,len2,len1,i,p,sum,rem;

	

	
	len1= strlen(num1);
	len2 = strlen(num2);

	if(len1!=len2)
	{
			if(len1>len2)
			{
				x=0;
				p = len1 - len2;

				for(i=0;i<p;i++)
					temp[x++]='0';
				for(i=0;i<len2;i++)
					temp[x++]=num2[i];
				
				temp[x]='\0';
				strcpy(num2,temp);
			}
			else
			{
				x=0;

				p = len2 - len1;
				for(i=0;i<p;i++)
					temp[x++]='0';
				for(i=0;i<len1;i++)
					temp[x++]=num1[i];
				
				temp[x]='\0';

				strcpy(num1,temp);
			
			}
	
	
	}

	//printf("%s %s\n",num1,num2);

	rem = 0;
	x=0;
	for(i=len1-1;i>=0;i--)
	{
	
		sum = (num1[i]-'0') + (num2[i]-'0') +rem;

		p = sum % base;

		rem = sum/base;


		result[x++] =  p + 48;

		//printf("sum= %d rem=%d\n",p,rem);
	
	}

	if(rem!=0)
		result[x++] = rem + 48;
	result[x]='\0';

	reverse(result);

}


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}
