#include <stdio.h>
 
void move(n,A,C,B)
int n,A,B,C; /* number to move, source pole, destination pole and
		spare pole respectively */
{
if (n==1){printf("Move from %d to %d.\n",A,C);}
else     {move(n-1,A,B,C);move(1,A,C,B);move(n-1,B,C,A);}
}

void main()
{
   int n;
	while(scanf("%d",&n)==1)
	 move(n,1,3,2);


}
