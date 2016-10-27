#include<stdio.h>
#include<string.h>


#define swap(a,b) a^=b^=a^=b
#define sz 1000
#define MAX 5000


int check_legal(char ch[],int base);
void decimal_anybase(unsigned long n,int b,char result[]); 
void reverse(char x[]);

void main()
{

	//freopen("11005.in","r",stdin);
	//freopen("11005.out","w",stdout);
	unsigned long test,ans[40],query,min,sum,num,cases=1;
	char result[sz];
	int cost[40],len,ind,i,j;
	


	scanf("%lu",&test);

	while(test--)
	{

		 

		 for(i=0;i<36;i++)
		 scanf("%d",&cost[i]);

		 scanf("%lu",&query);

		 printf("Case %lu:\n",cases++);

		 while(query--)
		 {
			 scanf("%lu",&num);
			 min=MAX;
			 for(i=2;i<=36;i++)
			 {
					decimal_anybase(num,i,result);

					sum=0;
					len = strlen(result);
					for(j=0;j<len;j++)
					{
						if(result[j]>='A'&&result[j]<='Z')
							ind = (result[j]-'A')+10;
						else
							ind = (result[j]-'0');
						sum = sum + cost[ind];					
					}

					if(sum<min)
						min  = sum;
					ans[i]=sum;

					//printf("%ld %ld %s\n",i,sum,result);
			 }

			 printf("Cheapest base(s) for number %lu:",num);
			 for(i=2;i<=36;i++)
			 {
				if(ans[i]==min)
					printf(" %d",i);
			 }
			 printf("\n");
		 }

		 if(test>0)
			 printf("\n");

		
	}
}
   



void reverse(char x[])
{

	int len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}


void decimal_anybase(unsigned long n,int b,char result[]) 
{     
      int j,sign; 

      int i=0; 

      if( (sign=n) <0 ) 
      n= -n;
      
	  do{     
		  j=n%b; 
          result[i++]=(j<10) ? (j+'0'): ('A'+j-10); 
      }while((n/=b)!=0); 

		
	  if(sign < 0)result[i++]='-'; 
      result[i]='\0'; 

      reverse(result); 


} 