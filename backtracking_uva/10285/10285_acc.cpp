#include<stdio.h> 
int a[101][101],R,C,max1,max2; 

void dig(int i,int j,int len) 
{ 
   if (len>max1)   max1=len; 

   if (i-1>=0 && a[i-1][j]<a[i][j])   dig (i-1,j,len+1);   // Up 
   if (i+1<R  && a[i+1][j]<a[i][j])   dig (i+1,j,len+1);   // Down 
   if (j-1>=0 && a[i][j-1]<a[i][j])   dig (i,j-1,len+1);   // Left 
   if (j+1<C  && a[i][j+1]<a[i][j])   dig (i,j+1,len+1);   // Right 

} 

void main() 
{ 
   char name[100]; 
   int i,j,N,k; 

   scanf("%d",&N); 
   for   (k=1;k<=N;k++) 
   { 
      max1=max2=0; 
      scanf("%s %d %d",&name,&R,&C); 
      for (i=0;i<R;i++)   for (j=0;j<C;j++)   scanf("%d",&a[i][j]); 

      for (i=0;i<R;i++)   for (j=0;j<C;j++) 
      { 
         dig (i,j,1); 
         if (max1>max2)   max2=max1; 
      } 
      printf("%s: %d\n",name,max2); 
   } 
} 
