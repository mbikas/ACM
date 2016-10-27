#include <stdio.h>  
#include <math.h> 
#include <string.h> 


void main() 
{ 
		int s=0; 
		int b=2; 
		char c; 
		int p=131071; 
		while(scanf("%c",&c)==1) 
		{ 
			if(c=='#')
			{
				if(s==0) 
					printf("YES\n"); 
				else 
					printf("NO\n");
				
				s=0;
				
			
			}
			 
			else 
			{ 
				if(c=='1'||c=='0') 
				{ 
					s *= b; 
					s += int(c)-48; 
					s %= p; 
				} 
			} 
			
		} 

} 
