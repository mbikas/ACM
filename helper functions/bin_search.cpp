#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>

typedef struct { 

   char a[15]; 
   char b[15];

}WORD; 

WORD word[100001]; 

long int index=0; 
int comp(const void* A, const void* B);
long int binsearch(char search[]);



int main(){ 

   char input[50]; 
   long int ind; 
   

   while(gets(input))
   { 

      if(strcmp(input,"")==0) 
         break; 
      sscanf(input,"%s %s",word[index].a,word[index].b); 
      index++; 

   } 

   qsort(word,index,sizeof(WORD),comp);
    
   while(gets(input))
   { 
       
      ind=binsearch(input); 
      if(ind!=-1){ 
          
         puts(word[ind].a); 
      } 
      else{ 
         puts("Not Found"); 
      } 
       
   } 


   return 0; 
}



int comp(const void* A, const void* B)
{
	WORD *a=(WORD*)A;
	WORD *b=(WORD*)B;
 
	return(strcmp(a->a,b->a));


}


long int binsearch(char search[]){ 
   long int high,low,mid; 
    
   low=0; 
   high=index-1; 
   while(low<=high){ 
       
      mid=(low+high)/2; 

      if(strcmp(word[mid].a,search)>0) 
         high=mid-1; 
      else if(strcmp(word[mid].a,search)==0){ 
          
         return mid; 
      } 
      else 
         low=mid+1; 


   } 
    
   return -1; 


} 