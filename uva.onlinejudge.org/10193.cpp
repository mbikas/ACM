#include<stdio.h>
#include<string.h>
#include<math.h>
#define sz 35

long  Gcd(long a ,long b);
long binary_to_long(char ch[]);


void main()
{
	long test,num1,num2,gcd,cases=1;
	char s1[sz],s2[sz];

	scanf("%ld",&test);

	while(test--)
	{
		scanf(" %[^\n] %[^\n]",s1,s2);
		num1 = binary_to_long(s1);
		num2 = binary_to_long(s2);

		gcd = Gcd(num1,num2);

		if(gcd<=1)
			printf("Pair #%ld: Love is not all you need!\n",cases++);
		else
			printf("Pair #%ld: All you need is love!\n",cases++);	
	}
}



long binary_to_long(char ch[])
{
	int len, i, p;
	long num=0;

	len = strlen(ch);

	for(i=0;i<len;i++)
	{
		p = ch[i] - '0';

		num = num + p * ( (long)pow(2,len-i-1));
	}

	return num;
}


long  Gcd(long a ,long b) 
{ 
        if(b==0) 
                return a; 
        else 
             return Gcd(b,a%b); 
} 