#include<stdio.h>
#include<string.h>

char name[11][14];               
                                  
int  No_of_people;
                         
int find_name(char a[])
{
	int i,j;
	
	for(i=0;i< No_of_people;i++)
	{
		j = strcmp(name[i],a);
			if(j==0)
			break;
	}
   return i;
}

void main()
{	
	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	char c, dumy[13], nline;
	
	long int  spent[10], gotten[10],f=0;
	
	int  money, i, j, how_many_frnd, index,value;

	for(;scanf("%d%c",&No_of_people,&nline)==2;)
	{
		for(i=0;i<No_of_people;i++)
			scanf("%s%c",name[i],&c);

		if(f==1)printf("\n");
		else f=1;

		for(i=0;i<10;i++)
		{
		 spent[i] = gotten[i] = 0;
       }

		for(i=0;i<No_of_people;i++)
		{
			scanf("%s%c%d%c%d%c", dumy, &c, &money, &c, &how_many_frnd, &c);

			value = 0;

			if(how_many_frnd>0)
			value = money/how_many_frnd;

			money = (-1)* value* how_many_frnd;

			index = find_name(dumy) ;

			spent[index] = money ;

			for(j=0;j<how_many_frnd;j++)
			{
				scanf("%s%c",dumy,&c);

				index = find_name(dumy);
				
				gotten[index] = value + gotten[index] ;
			}
		}

		for(i=0;i<No_of_people;i++)
			printf("%s %ld\n",name[i],(spent[i]+gotten[i]));

	//	printf("\n");
	}
}
			

