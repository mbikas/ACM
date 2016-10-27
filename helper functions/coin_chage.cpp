
 
#include <stdio.h> 
// 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent 

int main(){ 
    
	const int money[5]={50,25,10,5,1}; 
    int value,i,j; 

    int ways[305]={1}; 
    ways[0] = 1; 
    for (i=0;i<5;i++) 
        for (j = money[i];j<=300;j++) 
            ways[j] += ways[j - money[i]]; 

    while (scanf("%d",&value)==1){ 
        if (ways[value]==1) printf("There is only 1 way to produce %d cents change.\n",value); 
        else printf("There are %d ways to produce %d cents change.\n",ways[value],value); 
    } 
    return 0; 
} 
