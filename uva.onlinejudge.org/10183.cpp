#include<stdio.h>
#include<string.h>

#define swap(a,b) a^=b^=a^=b
#define sz 105
#define limit 480

void add(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);
int binary_search(int m,int item);
int number_compare(char num1[],char num2[]);

typedef struct{
	char num[105];
	long length;
	
}FIB;

FIB fib[485];	
	
void fibnacci();



int main()
{

	int index1,index2,key,i,j;
	char num1[105],num2[105];

	fibnacci();

   while(scanf(" %s %s",num1,num2)==2)
   {
	
	   if( (strcmp(num1,"0")==0) && (strcmp(num2,"0")==0) ) break;
	   

	   key = strlen(num1) - 1;
	   index1 = binary_search(limit+1 ,key);	   
	   key = strlen(num2) + 1;
	   index2 = binary_search(limit+1 ,key);	  
	   
	   if(index1==0)index1++;

	     
	   for(j=index1;j<index2;j++)
	   {	   
		   if( number_compare(fib[j].num,num1) !=1)
			   break;		   
	   }

	   //printf("%d\n",j);
	   key = 0;
	   for(i=j;i<index2;i++)
	   {
	       if( number_compare(fib[i].num,num2) == -1)
			   break;
		   key++;
	   
	   }
	   
	   printf("%d\n",key);


   }//end of while

	return 0;

}


void fibnacci()
{
	long i,len;
	char result[sz],str1[sz],str2[sz];

	strcpy(fib[0].num ,"0");
	
	strcpy(fib[1].num ,"1");
	strcpy(fib[2].num ,"2");
	fib[0].length = 0;
	fib[1].length = 1;
	fib[2].length = 1;
	

	for(i=3;i<=limit;i++)
	{
		
		strcpy(str1,fib[i-1].num);
		strcpy(str2,fib[i-2].num);
		add(str1,str2,result);
		
		len = strlen(result);
		strcpy(fib[i].num,result);
		fib[i].length = len;
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



int binary_search(int m,int item)
{
	int beg,mid,end;

	beg=1;
	end=m;
	mid=(int)( (beg+end)/2 );

	while ( (beg<=end) && (fib[mid].length !=item) )
	{
		if(item<fib[mid].length )
			end=mid-1;
		else
			beg=mid+1;

		mid=(int)( (beg+end)/2 );
	}

	if(fib[mid].length==item)
		return mid;
	
	return -1;

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
