#include<stdio.h>
#include<string.h>
#define sz 1000
#define swap(a,b) a^=b^=a^=b


long n1,n2;
long get_next_num(char a[],long i,long len);
long get_first_num(char a[],long i,long len);
long long get_minvalue(char a[],long len);
long long get_maxvalue(char a[],long len);
void reverse(char x[]);


void main()
{


	long test,len;
	char str[sz],a[sz];
	long long max,min;

	scanf("%ld\n",&test);

	while(test--)
	{

		gets(a);
		strcpy(str,a);

		len =strlen(a);

		max = get_maxvalue(a,len);
		min = get_minvalue(str,len);	

		printf("The maximum and minimum are %lld and %lld.\n",max,min);
	
	}



}



long long get_maxvalue(char a[],long len)
{

	long i,j,p,q,x,f;
	long long mul=0,sum=1;
	char num[10];

	for(i=0;i<len;i++)
	{

		if(a[i]=='+')
		{
			
			p = i;
			while(1)
			{
			    p= get_next_num(a,p,len);
				mul = mul + n1;	
				
				//printf("%ld = n1 = %ld\n",p,n1);
				if(p==len-1)
					break;
				if(a[p+1]=='+')
				  p++;					
				else
					break;
				
			}		
			q = get_first_num(a,i,len);
			//printf("n2 = %ld\n",n2);
			mul = mul + n2;
			//printf("mul = %lld\n",mul);
			sum *= mul;
			mul = 0;

			for(j=q;j<=p;j++)
				a[j]=' ';
			i = p;
		}	
	}	

	//printf("%ld\n",sum);
	//printf("%s\n",a);
	x=0;
	f=0;
	for(i=0;i<=len;i++)
	{
		
		if(a[i]>='0' && a[i]<='9')
		{
			f=1;
			num[x++]= a[i];
		}
		else
		{
		  if(f==1)
		  {
			num[x]='\0';
			sscanf(num,"%ld",&p);
			//printf("p = %ld\n",p);
			sum *=p;
		  }

		  f=0;
		  x=0;
		}		
	}
	

	//printf("%lld\n",sum);
	return sum;
}





long long get_minvalue(char a[],long len)
{

	long i,j,p,q,x,f;
	long long mul=1,sum=0;
	char num[10];

	for(i=0;i<len;i++)
	{

		if(a[i]=='*')
		{
			
			p = i;
			while(1)
			{
			    p= get_next_num(a,p,len);
				mul = mul * n1;	
				
				//printf("%ld\n",n1);
				if(p==len-1)
					break;
				if(a[p+1]=='*')
				  p++;					
				else
					break;
				
			}		
			q = get_first_num(a,i,len);
			//printf("%ld\n",n2);
			mul = mul * n2;
			//printf("mul = %lld\n",mul);
			sum += mul;
			mul = 1;

			for(j=q;j<=p;j++)
				a[j]=' ';
			i = p;
		}	
	}	

	//printf("%ld\n",sum);
	//printf("%s\n",a);
	x=0;
	f=0;
	for(i=0;i<=len;i++)
	{
		
		if(a[i]>='0' && a[i]<='9')
		{
			f=1;
			num[x++]= a[i];
		}
		else
		{
		  if(f==1)
		  {
			num[x]='\0';
			sscanf(num,"%ld",&p);
			//printf("p = %ld\n",p);
			sum +=p;
		  }

		  f=0;
		  x=0;
		}		
	}
	

	//printf("%lld\n",sum);

	return sum;
}



long get_next_num(char a[],long i,long len)
{
	
	long j,x=0;
	char num[10];
	for(j = i+1;j<len;j++)
	{
		if(a[j]>='0' && a[j]<='9')
		{
			num[x++] = a[j];
			if(j==len-1)
			{
				num[x]='\0';
				sscanf(num,"%ld",&n1);
				return j;			
			}	
		}
		else
		{
			num[x]='\0';
			sscanf(num,"%ld",&n1);
			return j-1;
		}	
	}

	return j-1;

}


long get_first_num(char a[],long i,long len)
{

	long j,x=0;
	char num[10];

	for(j = i-1;j>=0;j--)
	{
		if(a[j]>='0' && a[j]<='9')
		{
			num[x++] = a[j];
			if(j==0)
			{
				num[x]='\0';
				reverse(num);
				sscanf(num,"%ld",&n2);
				return j;
			
			}	
		}
		else
		{
			
			num[x]='\0';
			reverse(num);
			sscanf(num,"%ld",&n2);
			return j+1;
		}	
	}
	return j+1;

}


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}