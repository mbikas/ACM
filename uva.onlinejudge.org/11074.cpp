#include<stdio.h>

void main()
{

	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);

	long S,T,N,n1,n2,i,j,len,cases=1;

	int f=0;


	while(scanf("%ld %ld %ld",&S,&T,&N)==3 && (S!=0||T!=0||N!=0))
	{
		//if(f==1)printf("\n");
		//else f=1;
		printf("Case %ld:\n",cases++);

		n1 = N+1;
		len = T*(N+1) + S*N;

		while(n1>0)
		{
				for(i=0;i<T;i++)
				{
					for(j=0;j<len;j++)
					printf("*");
					printf("\n");
				}

				if(n1>1)
				{
					for(i=0;i<S;i++)
					{
						for(j=0;j<T;j++)
						printf("*");
						
						n2=N;
						while(n2>0)
						{
							for(j=0;j<S;j++)
								printf(".");
							for(j=0;j<T;j++)
								printf("*");
							n2--;
						}
						printf("\n");			
					}
				}

				n1--;

				
		
		
		}	

		printf("\n");
	
	}//while
}//main