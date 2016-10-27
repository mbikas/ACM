#include<stdio.h>
#include<string.h>
#define sz 13

int face[24][6]={	{0,1,2,3,4,5},{0,2,4,1,3,5},{0,4,3,2,1,5},{0,3,1,4,2,5},
					{1,5,2,3,0,4},{1,2,0,5,3,4},{1,0,3,2,5,4},{1,3,5,0,2,4},
					{2,1,5,0,4,3},{2,5,4,1,0,3},{2,4,0,5,1,3},{2,0,1,4,5,3},
					{3,1,0,5,4,2},{3,0,4,1,5,2},{3,4,5,0,1,2},{3,5,1,4,0,2},
					{4,0,2,3,5,1},{4,2,5,0,3,1},{4,5,3,2,0,1},{4,3,0,5,2,1},
					{5,1,3,2,4,0},{5,3,4,1,2,0},{5,4,2,3,1,0},{5,2,1,4,3,0}
				};


void paint_cube(char org[],char painted[],int zero,int one,int two,int three,int four,int five)
{
	painted[0]=org[zero];
	painted[1]=org[one];
	painted[2]=org[two];
	painted[3]=org[three];
	painted[4]=org[four];
	painted[5]=org[five];
	painted[6]='\0';
	return;
}
 
int main()
{
	char color[sz],paint1[sz],paint2[sz];
	int i,j;
	bool found;

	while(scanf(" %s",color)==1)
	{
		for(i=0;i<6;i++)paint1[i]=color[i];
		paint1[6]='\0';
		j=0;
		for(i=6;i<12;i++)paint2[j++]=color[i];
		paint2[j]='\0';


		found = false;
		for(i=0;i<24;i++)
		{
			paint_cube(paint1,color,face[i][0],face[i][1],face[i][2],face[i][3],face[i][4],face[i][5]);	
			if(strcmp(color,paint2)==0)
			{
				printf("TRUE\n");
				found=true;
				break;
			}
		}
		
		if(!found)printf("FALSE\n");
	}

	return 0;
}