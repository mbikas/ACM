#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long min(long n,long m)
{
	if(n>m)return m;
	if(n<m)return n;
	return m;
}
int main()
{
	char buf[1000],*p,HASH[35][7],string[1000];
	long i,j,n,c[35],hash_code,C,len,biggest;
	
	while(gets(buf)) 
	{ 
		strcpy(string,buf);
		p=strtok(buf," \n");
		n=0;
		while(p){
			strcpy(HASH[n++],p);
			p=strtok(NULL," \n");
		}
		
		for (i=0; i<n; i++) 
		{ 
			hash_code = 0; 
			len=strlen(HASH[i]);
			for(j=0; j<len; j++){ 
				hash_code = hash_code*32 + (HASH[i][j]-'a'+1);
			}
			c[i]=hash_code;
			
		} 		
		C=1;
		for (;;) 
		{ 
			biggest=-1; 
			for ( i=0; i<n; i++) 
				for (j=i+1; j<n; j++) 
					if (i!=j && ((C/c[i])%n == (C/c[j])%n)){
						biggest=min((C/c[i]+1)*c[i],(C/c[j]+1)*c[j]);						
					}					
					if(biggest==-1)
						break;
					C=biggest; 
		}
		printf("%s\n%ld\n\n",string,C); 
	} 
	
	return 0;
} 