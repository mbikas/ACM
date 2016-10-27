/* PALINDROMES */

#include<stdio.h>
#include<string.h>

	char a[5000],b[5000];
    int point,i,j,length,ptr,breaker;

	void reverse(char c[])
	{
		long len,i,mid;
		char temp;

		len=strlen(c);
		mid=len/2;
		for(i=0,len--;i<mid;i++,len--)
		{
			temp=c[i];
			c[i]=c[len];
			c[len]=temp;
		}
	}


int main()
{
	while(scanf("%s",a)==1)
	{
		breaker=point=0;

		strcpy(b,a);
		reverse(b);
		ptr=strcmp(a,b);
		if(!ptr)point=1;

		int count=0;
		length=strlen(b);
		for(i=0;i<length;i++)
			if(a[i]==' ')
				count++;

		if(count==length)continue;
        
		for(i=0;i<length;i++)
		{                                 
					 if(b[i]=='E')b[i]='3';
				else if(b[i]=='J')b[i]='L';
				else if(b[i]=='L')b[i]='J';
				else if(b[i]=='S')b[i]='2';
				else if(b[i]=='Z')b[i]='5';
				else if(b[i]=='2')b[i]='S';
				else if(b[i]=='3')b[i]='E';
				else if(b[i]=='5')b[i]='Z';
				else if(b[i]=='A' || b[i]=='H' || b[i]=='I' || b[i]=='M' || b[i]=='O' 
					 || b[i]=='T' || b[i]=='U' || b[i]=='V' || b[i]=='W' || b[i]=='X' 
					 || b[i]=='Y' || b[i]=='1' || b[i]=='8')breaker=0;
				else
				{
					breaker=1;
					break;
				}
				
		}

		if(breaker!=1)
		{
			ptr=strcmp(a,b);

			if(!ptr)
				point=point+2;
		}
		if(point==0)
			printf("%s -- is not a palindrome.\n",a);
		else if(point==1)
			printf("%s -- is a regular palindrome.\n",a);
		else if(point==2)
			printf("%s -- is a mirrored string.\n",a);
		else if(point==3)
			printf("%s -- is a mirrored palindrome.\n",a);

		printf("\n");
	}
	return 0;

}


				                                        