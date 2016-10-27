#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>

typedef struct{ 

   char word[15];
   char meaning[25]; 

}DIC; 

DIC dic[100001]; 

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
      sscanf(input,"%s %s",dic[index].meaning,dic[index].word); 
      index++; 

   } 

   qsort(dic,index,sizeof(DIC),comp);
    
   while(gets(input))
   { 
       
      ind=binsearch(input); 
      if(ind!=-1){ 
          
         puts(dic[ind].meaning); 
      } 
      else{ 
         puts("eh"); 
      } 
       
   } 


   return 0; 
}



int comp(const void* A, const void* B)
{
	DIC *a=(DIC*)A;
	DIC *b=(DIC*)B;
 
	return(strcmp(a->word,b->word));


}


long int binsearch(char search[]){ 
   long int high,low,mid; 
    
   low=0; 
   high=index-1; 
   while(low<=high){ 
       
      mid=(low+high)/2; 

      if(strcmp(dic[mid].word,search)>0) 
         high=mid-1; 
      else if(strcmp(dic[mid].word,search)==0){ 
          
         return mid; 
      } 
      else 
         low=mid+1; 


   } 
    
   return -1; 


} 