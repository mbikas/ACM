
#include <stdio.h> 
// 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent 

void main(){ 
    
	const int money[5]={50,25,10,5,1}; 
    long value,i,j; 

    long ways[7555]={0}; 
    ways[0] = 1; 
    for (i=0;i<5;i++) 
        for (j = money[i];j<=7500;j++) 
            ways[j] += ways[j - money[i]]; 

    while (scanf("%ld",&value)==1)
	     printf("%lld\n",ways[value]); 
    


}
