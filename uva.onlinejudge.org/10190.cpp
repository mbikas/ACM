#include<stdio.h> 
#include<math.h> 

int main() 
{
long n,m,j,p,kk,i;
double k;

while(scanf("%ld %ld",&n,&m)!=EOF){p=1;
if(n==1 || m==1 || n==0 || m==0) {printf("Boring!\n");continue;}


for(i=1;;i++) {
k=pow(m,i); 
if(k==n) {
for(j=i;j>=0;j--) {kk=pow(m,j);printf("%ld ",kk);} 
printf("\n");break; 
} 
else if(k>n) {printf("Boring!\n");break;} 
} 

} 
return 0; 
}
