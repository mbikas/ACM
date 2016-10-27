
#include<stdio.h> 

long int stack[10000]; 

main() 
{ 
  long int Z, I, M, L,ct=1; 
  int count, i;
  
  //#ifndef ONLINE_JUDGE 
  //  freopen("350.in","r",stdin); 
  //  freopen("350.out","w",stdout); 
  //#endif 
  while(scanf("%ld %ld %ld %ld",&Z,&I,&M,&L)==4) 
  { 
    if(Z==0 && I==0 && M==0 && L==0) break; 
    count=0; 
    while(1) 
    { 
      stack[count]=L; 
      L=(Z*L+I)%M; 
      count++; 
      for(i=0;i<count;i++) 
       if(stack[i]==L) 
         goto cetak; 
    } 
    cetak : 
    printf("Case %ld: %d\n",ct,count-i); 
	ct++;
  } 
  return 0; 
} 