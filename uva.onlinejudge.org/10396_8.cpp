#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(a,b) a^=b^=a^=b

void multiply(char a[],char b[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);
void check(char c[]);

typedef struct{
	char a[20];
}NUM;
NUM num[3000];
int p=0;


int comp(void const *A, void const *B)
{
	char *a = (char*)A;
	char *b = (char*)B;
	return *a - *b;
}

int comp1(void const *A, void const *B)
{

	NUM *a = (NUM*)A;
	NUM *b = (NUM*)B;

	return (strcmp(a->a,b->a));

}

void main()
{
	freopen("8.txt","w",stdout);

	 char num1[20],num2[20],result[20],temp1[20],temp2[20];
	 long i,j,k,l,m,n,f,o,q,n1,n2;
	for(i=1;i<=9;i++)
	{	for(j=0;j<=9;j++)
		{
		  for(m=0;m<=9;m++)
		  {
			  for(o=0;o<=9;o++)
			  {
		   num1[0]=i+48;
		   num1[1] = j+48;
		   num1[2] = m +48;
		   num1[3] = o +48;
		   num1[4]='\0';

		   for(k=1;k<=9;k++)
		   {	for(l=0;l<=9;l++)
				{ for(n=0;n<=9;n++)
					{			
						for(q=0;q<=9;q++)
						{
					///////////////////
					num2[0]=  k+48;
					num2[1] = l+48;
					num2[2] = n+48;
					num2[3] = q+48;
					num2[4]='\0';
					multiply(num1,num2,result);
                    
					f=1;						
					n1 = num1[3]-'0';
					n2 = num2[3]-'0';
					if(n1==0 && n2==0)
						f=0;

					
					if(strlen(result)==8 && (result[7]-'0')%2==0 && f==1)
					{	strcpy(temp1,result);
						qsort(temp1,8,sizeof(temp1[0]),comp);
						temp2[0]=num1[0];
						temp2[1]=num1[1];
						temp2[2]=num1[2];
						temp2[3]=num1[3];
						temp2[4]=num2[0];
						temp2[5]=num2[1];
						temp2[6]=num2[2];
						temp2[7]=num2[3];
						temp2[8]=0;
						qsort(temp2,8,sizeof(temp2[0]),comp);
						//printf("Biks\n");
						if(strcmp(temp1,temp2)==0)
						{
							//printf("bikas");
							
							check(result);
							if(p>=2353)goto bikas;
							
						}
						//printf("%s %s  = %s\n",num1,num2,result);
					}
					///////////////////		   
			
				}
		   }
		   }
			}
		   }
		  }
	
		}	
	}

bikas:

	qsort(num,p,sizeof(NUM),comp1);

	n=0;
	for(i=0;i<p;i++)
	{	
		printf("%s,",num[i].a);
		n++;
		if(n%100==0)
		printf("\n");
	}

	//printf("%ld\n",p);
}


void check(char c[])
{

	long i;
	for(i=0;i<p;i++)
	{
		if(strcmp(num[i].a,c)==0)
			return;
	}
	strcpy(num[p].a,c);
	p++;
	//printf("%s %ld\n",c,p);
}



void multiply(char a[],char b[],char result[])
{

	long i,j,k,index,carry,mul,len1,len2;

	if(strcmp(a,"0")==0 || strcmp(b,"0")==0)
	{
	  strcpy(result,"0");
	  return;
	}

	len1=strlen(a);
	len2=strlen(b);
	j = len1+len2;
	for(i=0;i<j;i++)
		result[i]='0';

	index=-1;

	for(i=len2-1;i>=0;i--)
	{
			index++;
			carry=0;
			for(j=len1-1,k=index;j>=0;j--,k++)
			{
					mul = toint(a[j])*toint(b[i]) + toint(result[k])+carry;
					carry = mul/10;
					result[k]=tochar(mul%10);

			}

			result[k]=tochar(carry%10);

	}

	if(carry!=0)
	  k++;
	result[k]='\0';
	reverse(result);

	return;

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