#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 200

int number_compare(char num1[],char num2[]);
void add(char x[],char y[],char result[]);
void subtract(char x[],char y[],char result[]);
int call_div(char *number,int div,char *result);
void reverse(char x[]);
long toint(char x);
long tochar(long x);


void main()
{

	int index,rem,p;
	long test;
	char num1[sz],num2[sz];
	char sum[sz],result[sz],max[sz],min[sz];

	scanf("%ld",&test);

	while(test>0)
	{
	
			scanf(" %s %s",num1,num2);
			index = number_compare(num1,num2);
			p=1;

			//sum greater than difference
			if(index==-1)
			{
					    
					add(num1,num2,result);
					strcpy(sum,result);
					//printf("sum = %s\n",sum);
					rem = call_div(sum,2,result);
					//printf("ans = %s   rem = %d\n",result,rem);
					strcpy(max,result);
					if(rem!=0)
						p=0;					
					
		

					subtract(num1,num2,result);
					strcpy(sum,result);
					//printf("differnece = %s\n",sum);
					rem = call_div(sum,2,result);
					//printf("ans = %s   rem = %d\n",result,rem);
					strcpy(min,result);
					if(rem!=0)
						p=0;
						
					//////////////////////////
					if(p==1)
					printf("%s %s\n",max,min);
					else
					printf("impossible\n");
					//////////////////////////
					
							//or
					//printf("%s %s\n",max,min);



			  }

			//sum less than difference
			else if(index==1)
				printf("impossible\n");
	   
			//sum == differnece
			else
			{
				rem = call_div(num1,2,result);
				strcpy(max,result);
				strcpy(min,"0");		   

				printf("%s %s\n",max,min);
						//or
				//printf("impossible\n");	   
			}

			test--;
	   




   }//end of while

}//end of main


                                                     
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

// STORES THE RESULT x-y IN STRING result
// x SHOULD BE GREATER THAN y
void subtract(char x[],char y[],char result[])
{

	long i,j,k,rem,len1,len2,len;
	char tem[sz],tem2[sz];

	strcpy(tem2,y);
	len2 = strlen(tem2);
	reverse(tem2);
	len1 = strlen(x);
	for(i=len2;i<len1;i++)
	tem2[i]='0';

	for(i=len1-1,j=0,k=0;i>=0;i--,j++)
	{
			rem=0;
			if(j>=0)
				rem = toint(tem2[j]);
			if(rem>toint(x[i]))
			{
					tem[k++] = tochar(10+toint(x[i])-rem);
					tem2[j+1]= tem2[j+1]+1;

			}
			else
					tem[k++]=tochar(toint(x[i])-rem);

	}
	tem[k] = '\0';
	len = strlen(tem);
	for(i=len-1;tem[i]=='0';i--)
			tem[i]='\0';
	reverse(tem);
	strcpy(result,tem);
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

int call_div(char *number,int div,char *result)
{

	int len = strlen(number);
	int now;
	int extra;

	char res[sz];

	for(now=0,extra=0;now<len;now++)
	{
		extra = extra *10 + (number[now]-'0');
		res[now] = extra/div + '0';
		extra %= div;
	}

	res[now]='\0';
	for(now=0;res[now]=='0';now++);

	strcpy(result,&res[now]);
	if(strlen(result)==0)
		strcpy(result,"0");

	return extra;
}

