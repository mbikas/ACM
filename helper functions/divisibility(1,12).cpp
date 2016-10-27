#include<stdio.h>
#include<string.h>

bool num[15];

bool check(char n[],int divisor);
void separating_int(char a[]);

int main()
{
	int i,test;
	bool possible;
	char input[100000],n[1009];

	gets(input);
	sscanf(input,"%d",&test);

	while(test--)
	{
		gets(n);
		

		memset(num,false,sizeof(num));
		gets(input);
		separating_int(input);

		if(strcmp(n,"0")==0)
		{
			printf("0 - Wonderful.\n");
			continue;
		}

		possible = true;
		for(i=2;i<=12;i++)
		{
			if(num[i])
			{
				possible = check(n,i);
				if(!possible)break;
			}
		}
		if(!possible)
			printf("%s - Simple.\n",n);
		else printf("%s - Wonderful.\n",n);

				
	
	}	

	return 0;
}

bool check(char n[],int divisor)
{
	int i,j,len,sod,p,sod1,sod2,count;
	len = strlen(n);
	char temp[10];
	bool f;

	sod=0;
	for(i=0;i<len;i++)
	sod += (n[i]-'0');

	if(divisor==2)
	{
		if ( (n[len-1]-'0') % 2 ==0 ) return true;
		return false;
	}
	if(divisor==3)
	{
		if ( sod % 3 ==0 ) return true;
		return false;
	}

	if(divisor==4)
	{
		p=0;

		if(len==1){
			temp[0] = n[len-1];
			temp[1]='\0';
		}
		else
		{	
			temp[0] = n[len-2];
			temp[1] = n[len-1];
			temp[2]='\0';
		}
		sscanf(temp,"%d",&p);

		if ( p % 4 ==0 ) return true;
		return false;
	}

	if(divisor==5)
	{
		if ( n[len-1]=='0' || n[len-1]=='5') return true;
		return false;
	}
	if(divisor==6)
	{
		if ( sod % 3 ==0 && (n[len-1]-'0')%2==0) return true;
		return false;
	}

	///////////////
	if(divisor==7)
	{
		f=true;
		char c;
		
		sod1=0;

		count=0;
		for(i=len-1;i>=0;i--)
		{
			if(count==3)
			{
				temp[count]=0;
				c=temp[0];
				temp[0]=temp[2];
				temp[2]=c;

				sscanf(temp,"%d",&p);
				if(f)
					sod1+=p;
				else sod1-=p;
				
				f=!f;

				count=0;
				//temp[count++]=n[i];
				i++;
			}
			else
			{
				temp[count++]=n[i];
			}
		}

		if(count!=0)
			{
				temp[count]=0;
				for(i=0,j=count-1;i<count/2;i++,j--)
				{
					c=temp[i];
					temp[i]=temp[j];
					temp[j]=c;
				}
				sscanf(temp,"%d",&p);
				if(f)
					sod1+=p;
				else sod1-=p;
				
				

				count=0;
			}

		if(sod1%7==0)return true;
		return false;

	}


	if(divisor==8)
	{
		p=0;

		if(len==1){
			temp[0] = n[len-1];
			temp[1]='\0';
		}
		else if(len==2)
		{	
			temp[0] = n[len-2];
			temp[1] = n[len-1];
			temp[2]='\0';
		}
		else
		{	
			temp[0] = n[len-3];
			temp[1] = n[len-2];
			temp[2] = n[len-1];
			temp[3]='\0';
		}
		sscanf(temp,"%d",&p);

		if ( p % 8 ==0 ) return true;
		return false;
	}

	if(divisor==9)
	{
		if ( sod % 9 ==0 ) return true;
		return false;
	}

	if(divisor==10)
	{
		if ( n[len-1]=='0') return true;
		return false;		
	}

	if(divisor==11)
	{
		sod1=sod2=0;
		for(i=0;i<len;i+=2)
			sod1+= (n[i]-'0');
		for(i=1;i<len;i+=2)
			sod2+= (n[i]-'0');
		sod1 = sod2 - sod1;
		if(sod1<0)sod1 = sod1 * -1;
		if (  sod1%11 == 0 ) return true;
		return false;		
	}

	if(divisor==12)
	{
		if ( check(n,3) && check(n,4)) return true;
		return false;		
	}


	return false;

}





 void separating_int(char a[])
 {
	  int p,x,i,val;
	  char temp[5];
	   p=strlen(a);
	  a[p]=' ';
	  bool first=true;

	  //separating A
	  /////////////////////////////////
	  x=0;
	  for(i=0;i<=p;i++)
		 {
			if(a[i]!=' ')
			 {
				temp[x]=a[i];
				x++;
			 }
			else
			 { while (a[i+1]==' ')i++;
				temp[x]='\0';
				sscanf(temp,"%d",&val);
				//printf("%d ",val);
				if(first)first = false;
				else num[val]=true;
				x=0;
			 }
		 }
		///////////////////////////////////////
 }