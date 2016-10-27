#include<stdio.h> 
#include<string.h> 
#define YES 1 
#define NO 0 
#define MIN(a,b) ((a)<=(b) ? (a) : (b)) 
#define ABS(a,b) ((a)<=(b) ? (b)-(a) : (a)-(b)) 
void main(void) 
{ 
int n,x,len,y,found,z,ansx1,ansy1,ansx2,ansy2,a,b,c; 
char data[100][101],s[101]; 
scanf("%d",&n); 
for(x=0;x<n;x++) 
   scanf("%s",data[x]); 
while(1) 
   { 
    scanf("%s",s); 
    if(s[0]=='0') 
      break; 
    len=strlen(s); 
    found=NO; 
    for(x=0;x<n && !found;x++) 
      for(y=0;y<=n-len && !found;y++) 
   { 
    for(z=0;z<len;z++) 
      if(s[z]!=data[x][y+z]) 
        break; 
    if(z==len) 
      { 
       found=YES; 
       ansx1=x+1,ansy1=y+1; 
       ansx2=x+1,ansy2=y+len; 
      } 
    for(z=0;z<len && !found;z++) 
      if(s[len-z-1]!=data[x][y+z]) 
        break; 
    if(z==len) 
      { 
       found=YES; 
       ansx1=x+1,ansy1=y+len; 
       ansx2=x+1,ansy2=y+1; 
      } 
   } 
    for(x=0;x<n && !found;x++) 
      for(y=0;y<=n-len && !found;y++) 
   { 
    for(z=0;z<len;z++) 
      if(s[z]!=data[y+z][x]) 
        break; 
    if(z==len) 
      { 
       found=YES; 
       ansx1=y+1,ansy1=x+1; 
       ansx2=y+len,ansy2=x+1; 
      } 
   } 
    for(x=0;x<2*n-1 && !found;x++) 
      { 
       if(x<=n) 
        // y=0,z=3-x; 
	    y=0,z=n-1-x;
       /////////////////////////
	   
	   
	   else 
    y=x-n-1,z=0; //y=x-3,z=0; 
       c=MIN(n-y,n-z); 
       if(len>c) 
    continue; 
       for(b=0;b<c-len+1 && !found;b++,y++,z++) 
    { 
     for(a=0;a<len;a++) 
       if(s[a]!=data[y+a][z+a]) 
         break; 
     if(a==len) 
       { 
        found=YES; 
        ansx1=y+1,ansy1=z+1; 
        ansx2=y+len,ansy2=z+len; 
       } 
     for(a=0;a<len && !found;a++) 
       if(s[len-a-1]!=data[y+a][z+a]) 
         break; 
     if(a==len) 
       { 
        found=YES; 
        ansx1=y+len,ansy1=z+len; 
        ansx2=y+1,ansy2=z+1; 
       } 
    } 
      } 
    for(x=0;x<2*n-1 && !found;x++) 
      { 
       if(x<n) 
    y=0,z=x; 
       else 
    y=x-n-1,z=n-1; //y=x-3,z=3; 
       c=ABS(y,z); 
       if(len>c+1) 
    continue; 
       for(b=0;b<c-len+2 && !found;b++,y++,z--) 
    { 
     for(a=0;a<len;a++) 
       if(s[a]!=data[y+a][z-a]) 
         break; 
     if(a==len) 
       { 
        found=YES; 
        ansx1=y+1,ansy1=z+1; 
        ansx2=y+len,ansy2=z-len+1; 
       } 
     for(a=0;a<len && !found;a++) 
       if(s[len-a-1]!=data[y+a][z-a]) 
         break; 
     if(a==len) 
       { 
        found=YES; 
        ansx1=y+len,ansy1=z-len+1; 
        ansx2=y+1,ansy2=z+1; 
       } 
    } 
      } 
    if(!found) 
      printf("Not found\n"); 
    else 
      printf("%d,%d %d,%d\n",ansx1,ansy1,ansx2,ansy2); 
   } 
} 