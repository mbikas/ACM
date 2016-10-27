//acm 10260 Soundex
//solved by Bikas CSE SUST
#include<stdio.h>
#include<string.h>
void main()
{
		int group[26],count,pre,temp;
		char word[20];

		group[0]=group[4]=group[8]=group[14]=group[20]=group[7]=group[22]=group[24]=0;

		group[1]=group[5]=group[15]=group[21]=1;

		group[2]=group[6]=group[9]=group[10]=group[16]=group[18]=group[23]=group[25]=2;

		group[3]=group[19]=3;

		group[11]=4;

		group[12]=group[13]=5;

		group[17]=6;

		while(scanf(" %s",word)==1)
		{
				  count=0;
				  pre=0;
				  for(count=0;count<strlen(word);count++)
				  {

								  temp=group[word[count]-65];
								  if(temp!=0)
								  {
											  if(pre!=temp)
														printf("%d",temp);


								  }
                          pre=temp;

				  }
				  printf("\n");
		}
}