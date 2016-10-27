//DECIMAL TO ANYBASE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define swap(a,b) a^=b^=a^=b
#define sz 1000   

void decimal_anybase(char n[], int base, char result[]); 
int call_div(char *number,int div,char *result);
void reverse(char x[]);

int main()
{  	
	int n,len,i,ind,d[5],aux,dest,bit,beg;
	char result[sz],m[sz];

	while(scanf("%d %s",&n,m)==2)
	{
		if(n==0 && strcmp(m,"0")==0)break;
		decimal_anybase(m,2,result);
		len = strlen(result);
		
		if(len<n)
		{
			ind=0;
			for(i=0;i<n-len;i++)m[ind++]='0';
			for(i=0;i<len;i++)m[ind++]=result[i];
			m[ind]='\0';
			len = ind;
			strcpy(result,m);
		}
		len = strlen(result);

		//printf("res = %s\n",result);


		d[0]=d[1]=d[2]=0;
		beg=0, aux=1, dest=2;

		for(bit=0;bit<n;bit++)
		{
			if(result[bit]=='0')
			{
				d[beg] = d[beg]+1;
				swap(aux,dest);
				/*i = aux;
				aux = dest;
				dest = i;
				*/
				
			}
			else if(result[bit]=='1')
			{
				d[dest]=d[dest]+1;
				swap(aux,beg);
				/*i = aux;
				aux = beg;
				beg = i;
				*/
			}		
		}
		if(n%2==0)
			printf("%d %d %d\n",d[0],d[1],d[2]);
		else
			printf("%d %d %d\n",d[0],d[2],d[1]);

	
	}

	return 0;
}




void reverse(char x[])
{
	
	int len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}


void decimal_anybase(char n[], int base, char result[])
{
	
	int i=0,j;	
	char res[sz];
	
	
	
	
	
	do{
		j = call_div(n,base,res);
		//j=n%base;
		result[i++]=(j<10) ? (j+'0'): ('A'+j-10);
		strcpy(n,res);
	}while(strcmp(n,"0")!=0);
	
	
	result[i]='\0';
	reverse(result);
}





int call_div(char *number,int div,char *result)
{

	int len = strlen(number);
	int now;
	int extra;

	char res[sz];

	for(now=0,extra=0;now<len;now++)
	{
		extra = extra *10 + (number[now]-'0');
		res[now] = extra/div + '0';
		extra %= div;
	}

	res[now]='\0';
	for(now=0;res[now]=='0';now++);

	strcpy(result,&res[now]);
	if(strlen(result)==0)
		strcpy(result,"0");

	return extra;
}