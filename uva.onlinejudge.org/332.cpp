#include<stdio.h>
#include<math.h>
#include<string.h>
#define sz 20

long GCD(long a ,long b);
int double_int(char num[],char result[]);
 
 
void main()
{
	//freopen("332.in","r",stdin);
	//freopen("new.out","w",stdout);
	
	char fraction[sz],result[sz];
	int point,j,i,k;

	long p,q,dnum,gcd,count=1;



	while(scanf("%d",&j)==1 && j != -1)
	{ 
		scanf(" %s",fraction);


		point  = double_int(fraction,result);		
		
		sscanf(result,"%lu",&p);
			
		//printf("%lu\n",p);
		

		if(p==0)
		{	printf("Case %lu: 0/1\n",count);
			count++;
			continue;
		}

		if(j==0)
			q=0;
		else
		{
			q = p;
			for(i=0;i<j;i++)
				q = q/10;
		}

		//printf("point =%d  p = %lu  q =%lu\n",point,p,q);
		
		
		p = p-q;


		if(j==0)
			dnum = (long)(pow(10,point));
		else
		{

			k = point - j;
			i = k+j;
			dnum = (long)( (long)pow(10,i) - (long)pow(10,k) );

		}
		

		

		gcd = GCD(p,dnum);

		if(gcd!=0)
		{

			p =  (long)(p/gcd);
			dnum = (long)(dnum/gcd);
		}
	

		printf("Case %lu: %lu/%lu\n",count,p,dnum);

		count++;


	}

}


long GCD(long a ,long b)
{ 
        if(b==0) 
                return a; 
        else 
             return GCD(b,a%b); 
} 




int double_int(char num[],char result[])
{
	
	int len,ct,i,p,x;
	char temp[sz];
	
	
	len = strlen(num);
	p=0;
	ct=0;
	
	x=0;
	for(i=0;i<len;i++)
	{
		if(p==1)
			ct++;
		if(num[i]!='.')
			temp[x++]=num[i];
		else
			p=1;	
	
	}


	//while(temp[x-1]=='0')
	//{ x--;
	//  ct--;
	//}
	//if(x==0)
	//	temp[x++]='0';

	temp[x]='\0';
	
	

	for(i=0;i<x-1;i++)
	{
		if(temp[i]!='0')
			break;
	}

	len=0;
	for(p=i;p<x;p++)
	{
	  result[len++] = temp[p];	
	}
	result[len] = '\0';	

	//printf("%s\n",result);



	return ct;
}

 

