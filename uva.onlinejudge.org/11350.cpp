//11350 Stern-Brocot Tree
#include<stdio.h>
#include<string.h>

int main()
{
	long long ln,ld,rn,rd,cn,cd,i,j,len,test;
	char input[100];

	//scanf("%ld",&test);

	gets(input);
	sscanf(input,"%lld",&test);

	while(test--)
	{
		gets(input);

		ln=0;
		ld=1;

		rn=1;
		rd=0;

		cn=1;
		cd=1;

		len=strlen(input);

		for(i=0;i<len;i++)
		{
			if(input[i]=='R')
			{
				ln=cn;
				ld=cd;

				cn=ln+rn;
				cd=ld+rd;
			}
			else if(input[i]=='L')
			{
				rn=cn;
				rd=cd;

				cn=ln+rn;
				cd=ld+rd;
			}
		}
		printf("%lld/%lld\n",cn,cd);
	}

	return 0;
}