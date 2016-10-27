#include<iostream>
using namespace std;


int main()
{
	long j,P,D,I,n;

	while(cin >> n && n!=-1)
	{

		while(n>0)
		{
	
            cin >> D >> I;
			//scanf("%ld %ld",&D,&I);
			P=1;
			for (j=0;j<D-1;j++) {
			
				P=I%2!=0 ? 2*P : 2*P+1; /* go to left or right? */
				I=(I+1)/2; /* round up */
				}

			//printf("%ld\n",P);
			cout << P <<"\n";


			n--;
		}

	}


 return 0;
}


