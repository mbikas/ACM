#include<stdio.h> 
#include<string.h>

char str1[20], str2[20];

void srev(char val[]) 
{ 
int l,i; 
char t; 
l = strlen(val) - 1; 
for(i=0;i<l;i++) 
{ 
t = val[i]; 
val[i] = val[l]; 
val[l] = t; 
l--; 
} 
} 

int main()
{



long x;

while(scanf("%ld",&x)==1)
{ 
	 sprintf(str1,"%ld",x);

    //printf("**%s**\n",str1);

	 srev(str1);

	 sscanf(str1,"%ld",&x);

	 printf("%ld\n",x);
} 


return 0; 
}
