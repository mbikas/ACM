/*	implementation of qsort 
   	based on multilable sorting 

	from book Programming Challenges ( section 4.5: Rating the Field)

*/ 



#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAXLENGTH	
#define BESTHEIGHT 180
#define BESTWEIGHT 75

	
typedef struct{

	char first[30];
	char last[30];
	int height;
	int weight;
}suitor;

suitor suitors[50];
int nsuitors;


void read_suitors()
{
  //char first[30],last[30];
  int height,weight;


  nsuitors = 0;

  while(scanf("%s %s %d %d\n",suitors[nsuitors].first,suitors[nsuitors].last,&height,&weight) !=EOF)
  {
	suitors[nsuitors].height = abs(height - BESTHEIGHT);
	if(weight>BESTWEIGHT)
		suitors[nsuitors].weight = weight - BESTWEIGHT;
	else
		suitors[nsuitors].weight = - weight;

	nsuitors++;

  }
}

//int suitor_compare(suitor *a, suitor *b)
//{
int comp(const void* A, const void* B)
{
	suitor *a=(suitor*)A;
	suitor *b=(suitor*)B;
	
	int result;
	
	if(a->height < b->height) return(-1);
	if(a->height > b->height) return(1);

	if(a->weight < b->weight) return(-1);
	if(a->weight > b->weight) return(1);

	if( (result = strcmp(a->last,b->last)) !=0 ) return result;
	
    return (strcmp(a->first,b->first));

}




void main()
{
	freopen("msorting.in","r",stdin);
	freopen("msorting.out","w",stdout);

	int	 i;

	//int suitor_compare();

	read_suitors();

	//qsort(suitors,nsuitors,sizeof(suitor),suitor_compare);
	qsort(suitors,nsuitors,sizeof(suitor),comp);

	for(i=0;i<nsuitors;i++)
	printf("%s, %s\n",suitors[i].last,suitors[i].first);


}