#include <stdio.h> 

int N,AnswerKey[20],Answer[20],AnswerTable[20],TranslatedAnswer[20]; 

int CalculateGrade(int i) 
{ 
int k,m,Sum,Max; 
Sum=0; 
for(k=i+1;k<N;k++) 
{ 
if(TranslatedAnswer[k]>TranslatedAnswer[i]) 
Sum++; 
} 
if(0==Sum) 
{ 
return 1; 
} 
else 
{ 
Max=0; 
for(k=i+1;k<N;k++) 
{ 
if(TranslatedAnswer[k]>TranslatedAnswer[i]) 
{ 
m=CalculateGrade(k); 
if(m>Max) 
{ 
Max=m; 
} 
} 
} 
return 1+Max; 
} 
} 

main() 
{ 
int i,k,m; 

scanf("%d",&N); 

for(i=0;i<N;i++) 
{ 
scanf("%d",&AnswerKey[i]); 
} 

while(scanf("%d",&Answer[0])!=EOF) 
{ 
for(i=1;i<N;i++) 
{ 
scanf("%d",&Answer[i]); 
} 

for(i=0;i<N;i++) 
{ 
TranslatedAnswer[Answer[i]-1]=AnswerKey[i]; 
} 

m=0; 
for(i=0;i<N;i++) 
{ 
k=CalculateGrade(i); 
if(k>m)m=k; 
} 
printf("%d\n",m); 
} 
} 
