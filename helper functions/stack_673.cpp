#include<iostream>
using namespace std;

#define size 150

class stack{
	
	public:
	
		char arr[size];
		int tos;

	

		void init()
		{
			tos=0;
		}

		void push(char ch)
		{
			//if(tos==size)
              //cout <<"STACK FULL"<<endl;
			arr[tos]=ch;
			tos++;
		}

		char pop()
		{
			/*
			if(tos==0)
			{
				cout << "STACK EMPTY"<<endl;
				return 0;
			}
			*/
			tos--;
			return arr[tos];
			
		}
};

int main()
{
	stack s1;

	int i,m;
	long n;
	char a[size],c;

	

	

	scanf("%ld",&n);

	while(n>0)
	{
		s1.init();
		scanf(" %s",a);

		m=strlen(a);

		for(i=0;i<m;i++)
		{
			if(a[i]=='(' || a[i]=='[')	
				s1.push(a[i]);
			else if(a[i]==')')
			{
				
				c = ' ';
				while(c!='(' && s1.tos>=0)
					c = s1.pop();
			}
		
			else if(a[i]==']')
			{
				
				c = ' ';
				while(c!='[' && s1.tos>=0)
					c = s1.pop();
			}
		}
			
		

		
		//printf("%d\n",s1.tos);
	

		if(s1.tos==0)
			printf("Yes\n");
	    else
			printf("No\n");
	

		n--;
	}


	return 0;
}