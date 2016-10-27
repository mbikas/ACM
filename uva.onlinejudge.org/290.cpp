#include<stdio.h>
#include<string.h>
//////////////////////
#define sz 10000
/////////////////////////

#define swap(a,b) a^=b^=a^=b


void reverse(char x[]);
void base_summation(char num1[],char num2[], char result[],int base);
int palindrome(char a[]);
int check_legal(char ch[],int base);

void main()
{
	char result[sz],num1[sz],num2[sz],num[sz];

	int base,p,x,ct;
	
	
	while(scanf(" %s",num)==1)
	{

		
		

		for(base=15;base>=2;base--)
		{
				strcpy(num1,num);
				strcpy(num2,num);
				reverse(num2);

				x = check_legal(num,base);
				
				ct=0;

				
				if(x==1)
				{


					if(palindrome(num)!=1)
					{
	
						while(1)
						{
							base_summation(num1,num2,result,base);
							//printf("%s\n",result);
							p = palindrome(result);
							if(p==1)
							{   ct++;
								//printf("%d base=%d\n",ct,base);
								if(base==2)
									printf("%d\n",ct);
								else
									printf("%d ",ct);
								break;
							}
							else
								ct++;

							strcpy(num1,result);
							strcpy(num2,result);
							reverse(num2);

							if(ct>100)
							{	if(base==2)
									printf("?\n");
								else
									printf("? ");
								break;
							}
						}
					}
					else
					{
						if(base==2)
						printf("%d\n",ct);
						else
						printf("%d ",ct);
					}
				}


				else
				{
					if(base==2)
						printf("?\n");
					else
						printf("? ");
					
				}
				

				
		}
		
	
	
	
	}




}



int palindrome(char a[])
{


	char temp[sz];

	strcpy(temp,a);

	reverse(temp);

	if(strcmp(temp,a)==0)
		return 1;

	return 0;
}

int check_legal(char ch[],int base)
{
	int m,p,i;

	m = strlen(ch);

	for(i=0;i<m;i++)
	{
		if(ch[i]>='A' && ch[i]<='Z')
		  p = (int)ch[i]-55;
		else if(ch[i]>='0'&& ch[i]<='9')
		  p = (int)ch[i]-'0';
		else
		  return 0;

		if(p>=base)
		 return 0;
	}

	return 1;

}
void base_summation(char num1[],char num2[], char result[],int base)
{
	int x=0,len,i,p,sum,rem,n1,n2;
	len= strlen(num1);	
	rem = 0;
	x=0;

	for(i=len-1;i>=0;i--)
	{
		if(num1[i]>='0'&&num1[i]<='9')
			n1 = (int)num1[i]-48;
		else if(num1[i]>='A'&&num1[i]<='Z')
			n1 = (int)num1[i]-55;
		
		if(num2[i]>='0'&&num2[i]<='9')
			n2 = (int)num2[i]-48;
		else if(num2[i]>='A'&&num2[i]<='Z')
			n2 = (int)(num2[i])-55;
		//printf("%d %d\n",n1,n2);	
		
		sum = n1 + n2 +rem;
		p = sum % base;
		rem = sum/base;
		if(p<10)
			result[x++] =  p + 48;
		else
			result[x++] =  p + 55;
		//printf("sum= %d rem=%d\n",p,rem);	
	}

	if(rem!=0)
	{
		if(rem<10)
			result[x++] =  rem + 48;
		else
			result[x++] =  rem + 55;
	   	
	}
	result[x]='\0';
	reverse(result);
	//printf("%s\n",result);
}

void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}
