#include<stdio.h>
#include<string.h>

class BigInteger{
	
	public:
				
			BigInteger();
			int setbychar(const char *num);
			int add(BigInteger &a1,BigInteger &a2);
			const char *print();
			~BigInteger();

	private:
			
			int size;
			char *content;
};

BigInteger::BigInteger() : size(0),content(0){}

int BigInteger::setbychar(const char *num)
{
	size = strlen(num);
	content = new char[size+1];
	strcpy(content,num);
	return 0;
}

int BigInteger::add(BigInteger &a1,BigInteger &a2)
{
	char *temp;
	int i,j,k,c,t;
	size = a1.size>a2.size ? a1.size : a2.size;
	size++;
	temp = new char[size+1];
	memset(temp,32,sizeof(temp));
	i = a1.size - 1;
	j = a2.size - 1;

	k = size-1;
	temp[size]='\0';
	c=0;
	while(i>=0||j>=0||c!=0)
	{
			t=c;
			c=0;
			if(i>=0)
			{
				t+=a1.content[i]-48;
				i--;
			}
			if(j>=0)
			{
				t+=a2.content[j]-48;
				j--;			
			}
			c = t/10;
			t = t%10;
			temp[k--]=t+48;
			
	}

	if(k>=0)
		strcpy(temp,temp+k+1);
	size -= k+1;
	if(content!=NULL)
		delete content;
	content = temp;
	return 0;
}

const char* BigInteger::print()
{
	return content;
}

BigInteger::~BigInteger()
{
	if(content!=NULL)
		delete content;

}


void main()
{
	int i;

	BigInteger a[5001];
	a[0].setbychar("0");
	a[1].setbychar("1");

	for(i=2;i<=5000;i++)
		a[i].add(a[i-1],a[i-2]);

	while(scanf("%d",&i)==1)
	  printf("The Fibonacci number for %d is %s\n",i,a[i].print());

}