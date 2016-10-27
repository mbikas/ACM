#include<stdio.h>
void solveTowers(int count,char source,char destination,char spare);

void main()
{
	int n;
    while(scanf("%d",&n)==1)
    solveTowers(n,'A','B','C');



}









void solveTowers(int count,char source,char destination,char spare)
{
   if (count==1)
     printf("Move top disc from pole %c to pole %c\n",source,destination);
   else
   {
      solveTowers(count-1,source,spare,destination);
      solveTowers(1,source,destination,spare);
      solveTowers(count-1,spare,destination,source);
   }
}

