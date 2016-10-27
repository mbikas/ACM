#include <stdio.h> 
#include <string.h> 

long cache[105][105]; 

long sum(int N, int K) 
{ 
   int i; 
   long summ=0; 

   if(cache[N][K]!=-1) return cache[N][K]; 
   if(N==0||K==0) return 1; 
   if(K==1) return 1; 
   if(K==2) return N+1; 
    
   for(i=0;i<=N;i++) 
      summ+=sum(N-i,K-1)%1000000; 
   cache[N][K]=summ;    
return summ; 
} 

void main() 
{ 
   int N,K; 
   int i,j; 
   for(i=0;i<101;i++) 
	    memset(cache, -1, sizeof(cache));
   
   while(scanf("%d %d",&N,&K)==2) 
   { 
      if(!N && !K) break;
	  
	  printf("%ld\n",sum(N,K)%1000000 ); 
   } 

}