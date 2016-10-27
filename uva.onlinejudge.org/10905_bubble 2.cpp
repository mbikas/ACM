#include<stdio.h>
#include<string.h>
#define sz 1000 // 100

typedef struct{
	char a[sz];
}number;

number num[52];

int best(char x[],char y[]);
int number_compare(char num1[],char num2[]);


void main()
{
	int i,n,j,p;
	char temp[sz];

	while(scanf("%d",&n)==1 && n!=0)
	{
	
		for(i=0;i<n;i++)
		scanf(" %s",num[i].a);


		for(i=1;i<n;i++)
		{  
			for(j=0;j<n-i;j++)
			{
				p = best(num[j].a,num[j+1].a);

				if(p==1)
				{
				   strcpy(temp,num[j].a);
				   strcpy(num[j].a,num[j+1].a);
				   strcpy(num[j+1].a,temp);
				}
			}
		}
		


		for(i=0;i<n;i++)
				printf("%s",num[i].a);
		printf("\n");
	

	
	
	}



}


//return 1 if x is best 0 otherwise
int best(char x[],char y[])
{
	
	char num1[sz],num2[sz],temp[sz];
	int p,q,i,len=0;

	p = strlen(x);
	q = strlen(y);

	for(i=0;i<p;i++)
		temp[len++]=x[i];
	for(i=0;i<q;i++)
		temp[len++]=y[i];
	temp[len]='\0';
	strcpy(num1,temp);

	len=0;
	for(i=0;i<q;i++)
		temp[len++]=y[i];
	for(i=0;i<p;i++)
		temp[len++]=x[i];
	temp[len]='\0';
	strcpy(num2,temp);

	p = number_compare(num1,num2);

	
	if(p==1)
		return 1;
	else
		return 0;

	



}


//compare num2 with num1//////                         
//     return 0 if  num2 = num1  //
//     return 1 if  num2 > num1  //
//     return -1 if num2 < num1  // 
int number_compare(char num1[],char num2[])
{
	long len1,len2,i,flag;


	len1 = strlen(num1);
	len2 = strlen(num2);

	if(len2 > len1)
		return 1;
	
	else if(len1 == len2)
	{
		flag = 2;
	                                    
		for(i=0;i<len1;i++)
		{
		
			if(num1[i]>num2[i])
			{	flag =1;
				break;
			}
			else if(num1[i]<num2[i])
			{  flag=0;
			   break;
			}
			else
              flag  = -1;
		}

		if(flag==-1)
			return 0;
		if(flag==1)
	        return -1;
		if(flag==0)
			return 1;
	
	
	}
	return -1;

}