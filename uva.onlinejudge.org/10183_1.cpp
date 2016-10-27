#include<stdio.h>
#include<string.h>
#define sz 110

#define swap(a,b) a^=b^=a^=b
#define limit 500

void add(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);

typedef struct{
	char num[sz];
	
	
}FIB;

FIB fib[502];	
	
void fibnacci();



int main()
{

	char from[110],to[110],temp1[110];
	int temp,lenf,lent,i; 
	int total=0; 

	fibnacci();

	

    while(scanf(" %s %s",from,to)==2)
    {
		total=0;
	
		if( (strcmp(from,"0")==0) && (strcmp(to,"0")==0) ) break;
	   
		if (strlen(from)>strlen(to) || strlen(from)==strlen(to) && strcmp(from,to)>0) 
		{ 
				strcpy(temp1,from); 
				strcpy(from,to); 
				strcpy(to,temp1); 
		} 
		lenf=strlen(from); 
		lent=strlen(to); 

		
		for(i=0; i<500; ++i) //500 fibo in the array 
		{ 
			temp=strlen(fib[i].num); 
			if (temp>lenf || strcmp(fib[i].num,from)>0 && lenf==temp|| strcmp(fib[i].num,from)==0 && lenf==temp) 
			{ 
				if (lent==temp ) 
				{ 
					if (strcmp(fib[i].num,to)<0 || strcmp(fib[i].num,to)==0) 
					{ 
						total++; continue; 
					} 
				} 
				else if (temp <lent) 
				{ total++; } 
				else break; 
			} 

		} //end for 

	   
	   printf("%d\n",total);





   }//end of while
	return 0;

}


void fibnacci()
{
	int i;
	char result[sz],str1[sz],str2[sz];

	strcpy(fib[0].num ,"1");
	
	strcpy(fib[1].num ,"1");
	strcpy(fib[2].num ,"2");
	
	

	for(i=3;i<=limit;i++)
	{
		
		strcpy(str1,fib[i-1].num);
		strcpy(str2,fib[i-2].num);
		add(str1,str2,result);
		
		strcpy(fib[i].num,result);
		
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


