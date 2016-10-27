#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <stdlib.h> 
#define MAX 5010 
#define MAXSZ 200 

char *str_add(char fib1[],char fib2[],long len1,long len2); 
long check_length(char fibonacci[],char range[],long len); 

char *fib[MAX],A[MAXSZ],B[MAXSZ]; 
void main() 
{ 

long i,j,len1,len2,A_len,B_len,fib_len,check; 
long start,end,dif; 
char *ptr,fib1[MAXSZ],fib2[MAXSZ]; 

for(i=0;i<3;i++) 
  fib[i]=(char *)malloc(3*sizeof(char)); 

fib[0][0]='1'; 
fib[0][1]='\0'; 
fib[1][0]='1'; 
fib[1][1]='\0'; 
fib[2][0]='2'; 
fib[2][1]='\0'; 

 for(i=3;i<=500;i++) 
    { 
    fib[i]=(char *)malloc(MAXSZ*sizeof(char)); 

    len1=strlen(fib[i-1]); 
    len2=strlen(fib[i-2]); 
    strcpy(fib1,fib[i-1]); 
    strcpy(fib2,fib[i-2]); 
    ptr=str_add(fib1,fib2,len1,len2); 
    strcpy(fib[i],ptr); 
    } 


for(;;) 
  { 
  scanf("%s %s",A,B); 
  if(!strcmp(A,"0") && !strcmp(B,"0")) 
     break; 

  A_len=strlen(A); 
  B_len=strlen(B); 

  start=0; 
  end=0; 
  for(i=1;i<=500;i++) 
      { 
      fib_len=strlen(fib[i]); 
      if(fib_len<A_len) 
         continue; 

      if(fib_len==A_len) 
          { 
          check=check_length(fib[i],A,fib_len); 
          if(check>=0) 
              { 
              start=i; 
              break; 
              } 
          else if(check<0) 
              continue; 

          } 
      if(fib_len>A_len) 
       start=i; 
      break; 
      } 

  for(j=start;j<=500;j++) 
      { 

      fib_len=strlen(fib[j]); 
      if(fib_len<B_len) 
           continue; 

      if(fib_len==B_len) 
           { 
           check=check_length(fib[j],B,fib_len); 
           if(check==0) 
               { 
               end=j; 
               break; 
               } 
           else if(check>0) 
               { 
               end=j-1; 
               break; 
               } 

           else if(check<0) 
               continue; 

           } 

       if(fib_len>B_len) 
        end=j-1; 
       break; 
       } 
  dif=end-start+1; 
  printf("%ld\n",dif); 

  } 
} 

char *str_add(char fib1[],char fib2[],long len1,long len2) 
{ 

long sum,max,min,dif,a,re,qu,i,j,k,x,y; 
char *result; 

result=(char *)malloc(MAXSZ*sizeof(char)); 

if(len1>=len2) 
 { 
 max=len1; 
 min=len2; 
 dif=max-min; 

 for(a=min-1;a>=0;a--) 
   fib2[a+dif]=fib2[a]; 
   fib2[max]='\0'; 

 for(a=0;a<dif;a++) 
   fib2[a]='0'; 

 } 
else if(len1<len2) 
 { 
 max=len2; 
 min=len1; 
 dif=max-min; 

 for(a=min-1;a>=0;a--) 
   fib1[a+dif]=fib1[a]; 
   fib1[max]='\0'; 

 for(a=0;a<dif;a++) 
   fib1[a]='0'; 

 } 


qu=0; 
i=MAXSZ-1; 
for(a=max-1;a>=0;a--) 
  { 
  sum=qu+(fib1[a]-48)+(fib2[a]-48); 

  if(sum>=10) 
    { 
    qu=sum/10; 
    re=sum%10; 
    } 
  else if(sum<10) 
    { 
    qu=0; 
    re=sum; 
    } 
  result[i--]=(char)(re+48); 
  if(a==0 && qu!=0) 
    { 
    for(;;) 
        { 
        x=qu/10; 
        y=qu%10; 
        result[i--]=(char)(y+48); 
        if(x==0) break; 
        qu=x; 
        } 
    } 
  } 
j=i+1; 
k=MAXSZ-1-j; 

for(i=j;i<=MAXSZ;i++) 
  result[i-j]=result[i]; 

result[k+1]='\0'; 

return result; 
} 

long check_length(char fibonacci[],char range[],long len) 
{ 
long a,mark=0; 
if(!strcmp(fibonacci,range)) return 0; 
for(a=0;a<len;a++) 
  { 
  if(fibonacci[a]>range[a]) 
     { 
     mark=1; 
     break; 
     } 
  else if(fibonacci[a]<range[a]) 
     { 
     mark=-1; 
     break; 
     } 
  } 
return mark; 
} 
