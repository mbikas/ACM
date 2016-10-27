#include<stdio.h>
#include<string.h>


#define sz 500

int multi[sz];
int multiply(int a[],int n,int b[],int m);/*first send big one;*/



int main()
{
	int i,j,a1[sz],b1[sz],m,n,index;
	char a[sz],b[sz];

	while(scanf(" %s %s",a,b)==2)
	{

	  j = strlen(a);
	  n=0;
	  for(i=0;i<j;i++)
	  a1[n++]=(int)a[i]-48;

	  j = strlen(b);
	  m=0;
	  for(i=0;i<j;i++)
	  b1[m++]=(int)b[i]-48;

	  index = multiply(a1,n,b1,m);


	  //deleting leading zeroes
	  for(i=0;i<index-1;i++)
	  { if(multi[i]!=0) break;
	  }

	  for(j=i;j<index;j++)
	  printf("%d",multi[j]);

	  printf("\n");


	}




	return 0;

}

//multiplies two int array and return the answer as multi and arrar size
int multiply(int a[],int n,int b[],int m)/*first send big one;*/
{

	int i,j,flag,p,q,mul,rem,x,ind=0;
	int temp[sz],c[sz];

	if(m>n)
	{
		p = n;
		for(i=0;i<n;i++)
		temp[i] = a[i];


		for(i=0;i<m;i++)
		a[i] = b[i];
		n = m;

		for(i=0;i<p;i++)
		b[i] = temp[i];
		m = p;

	}

	flag=1;
	ind =0;

	for(i=m-1;i>=0;i--)
	{

			rem = 0;
			x = 0;
			p=b[i];

			if(flag!=1)c[x++] = 0;

			for(j = n-1;j>=0;j--)
			{
					q = a[j];
					mul = (p*q)+rem;
					c[x++] = mul%10;
					rem = mul/10;
					if(j==0 && rem!=0) c[x++] = rem;

			}


			if(flag==1)
			{
					for(j=0;j<x;j++)
					temp[ind++] = c[j];
					flag=2;
			}

			else
			{
					if(ind<x)
					{ 		for(j=ind;j<x;j++)
							temp[j] = 0;
					}

					ind = 0,rem = 0;
					for(j=0;j<x;j++)
					{
							p = temp[j] + c[j] + rem;
							temp[ind++] = p%10;
							rem = p/10;
							if(j==x-1 && rem!=0)temp[ind++] = rem;
					}
			}

	 }

	 p=ind;
	 ind=0;
	 for(i=p-1;i>=0;i--)
	 multi[ind++] = temp[i];

	 // printf("%d\n",ind);


	return ind;

}

