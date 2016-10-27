#include<stdio.h>
#include<string.h>
int binary_decimal(char binary[]);

void main()
{  	

	//freopen("740.in","r",stdin);
	//freopen("740.out","w",stdout);

	int i,ct,n=0,decimal,p;
	int shiftDown=1,shiftUp=0;

	char down[35],up[35],a[100],binary[10];

	scanf(" %[^\n]",down);
	scanf(" %[^\n]",up);


	while(scanf(" %s",a)==1)
	{
			p = strlen(a);

			shiftDown=1,shiftUp=0;
			ct=0;
			n=0;
			for(i=0;i<p;i++)
			{
					binary[n++] = a[i];
					ct++;
					if(ct==5)
					{
						binary[n]='\0';
						decimal = binary_decimal(binary);
				
						if(decimal==27)
						{
							shiftDown=1;
							shiftUp = 0;
						}
						else if(decimal==31)
						{
							shiftDown=0;
							shiftUp = 1;
						}
						else
						{				  
							if(shiftUp==1)
								printf("%c",up[decimal]);
							else
								printf("%c",down[decimal]);
						}

						n=0;
						ct=0;			
					}

			}//end of for loop

			printf("\n");
			
	}//end of while

}//end of main



int binary_decimal(char binary[]) 
{     
    
	if( strcmp(binary,"00000")==0)
		return 0;
	else if(strcmp(binary,"00001")==0)
		return 1;
	else if(strcmp(binary,"00010")==0)
		return 2;
	else if(strcmp(binary,"00011")==0)
		return 3;
	else if(strcmp(binary,"00100")==0)
		return 4;
	else if(strcmp(binary,"00101")==0)
		return 5;
	else if(strcmp(binary,"00110")==0)
		return 6;
	else if(strcmp(binary,"00111")==0)
		return 7;
	else if(strcmp(binary,"01000")==0)
		return 8;
	else if(strcmp(binary,"01001")==0)
		return 9;
	else if(strcmp(binary,"01010")==0)
		return 10;
	else if(strcmp(binary,"01011")==0)
		return 11;
	else if(strcmp(binary,"01100")==0)
		return 12;
	else if(strcmp(binary,"01101")==0)
		return 13;
	else if(strcmp(binary,"01110")==0)
		return 14;
	else if(strcmp(binary,"01111")==0)
		return 15;
	else if(strcmp(binary,"10000")==0)
		return 16;
	else if(strcmp(binary,"10001")==0)
		return 17;
	else if(strcmp(binary,"10010")==0)
		return 18;
	else if(strcmp(binary,"10011")==0)
		return 19;
	else if(strcmp(binary,"10100")==0)
		return 20;
	else if(strcmp(binary,"10101")==0)
		return 21;
	else if(strcmp(binary,"10110")==0)
		return 22;
	else if(strcmp(binary,"10111")==0)
		return 23;
	else if(strcmp(binary,"11000")==0)
		return 24;
	else if(strcmp(binary,"11001")==0)
		return 25;
	else if(strcmp(binary,"11010")==0)
		return 26;
	else if(strcmp(binary,"11011")==0)
		return 27;
	else if(strcmp(binary,"11100")==0)
		return 28;
	else if(strcmp(binary,"11101")==0)
		return 29;
	else if(strcmp(binary,"11110")==0)
		return 30;
	else if(strcmp(binary,"11111")==0)
		return 31;
	
	return -1;
	
}





