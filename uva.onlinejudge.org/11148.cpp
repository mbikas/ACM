#include<stdio.h>
#include<string.h>
#define sz 10000


long  Gcd(long a ,long b) 
{ 
        if(b==0) 
                return a; 
        else 
             return Gcd(b,a%b); 
} 


void main()
{
	long cases,i,len,j,k,l,p,t,a,b,c;
	long num[100],dnum[100];
	char temp[25],temp1[25],ques[sz];

	scanf("%ld",&cases);

	while(cases--)
	{

		scanf(" %[^\n]",ques);
		len = strlen(ques);
		
		p=0;

        ques[len]='a';
		len++;
		ques[len]='\0';
		for(i=0;i<len;i++)
		{
			if(ques[i]>='0' && ques[i]<='9')
			{
				t=0;
				for(j=i;j<len;j++)
				{
					temp[t++]=ques[j];
					if( !(ques[j]>='0'&&ques[j]<='9') )
					{
						temp[t]='\0';
						if(ques[j]=='/')
						{
							sscanf(temp,"%ld",&a);
							t=0;
							for(k=j+1;k<len;k++)
							{
								temp1[t++]=ques[k];
								if( !(ques[k]>='0'&&ques[k]<='9') )
								{
									temp1[t]='\0';
									sscanf(temp1,"%ld",&b);
									num[p]=a;
									dnum[p]=b;
									p++;
									break;
								}							
							}
							i = k;
							break;
						}
						else if(ques[j]=='-')
						{
							sscanf(temp,"%ld",&a);
							t=0;
							
							for(k=j+1;k<len;k++)
							{
								temp1[t++]=ques[k];
								if( !(ques[k]>='0'&&ques[k]<='9') )
								{
									temp1[t]='\0';
									sscanf(temp1,"%ld",&b);
									t=0;
									for(l=k+1;l<len;l++)
									{
										temp1[t++]=ques[l];
										if( !(ques[l]>='0'&&ques[l]<='9') )
										{
											temp1[t]='\0';
											sscanf(temp1,"%ld",&c);
											num[p]=(a*c)+b;
											dnum[p]=c;
											p++;
											i=l;
											break;
										}								
									}
									break;
								
								}
							
							}
							break;

						
						}

						else
						{
							sscanf(temp,"%ld",&a);
							num[p]=a;
							dnum[p]=1;
							p++;							
							i=j;
							break;
						}										
					}//inner if

				
				
				}//inner for j			
			}//outer if		
		}//outer for i	


		a=b=1;
		
		for(i=0;i<p;i++)
		{
			//printf("%ld/%ld\n",num[i],dnum[i]);
			a = a* num[i];
			b = b*dnum[i];		
		}

		c = Gcd(a,b);		
		a = a/c;
		b = b/c;

		if(b==1)
			printf("%d\n",a);

		else if(a<b)
		{
			printf("%ld/%ld\n",a,b);
		}
		else
		{
			t = (long) (a/b);
			c = t*b;
			a = a - c;
			printf("%ld-%ld/%ld\n",t,a,b);

		
		}



	
	}//while
}//main
