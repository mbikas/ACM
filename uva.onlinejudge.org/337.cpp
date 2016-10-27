#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 10000
#define over 0
#define insert 1

char temp[sz],line[sz];
long row,col,mode;
char a[15][15];
void flush();
void process(char line[]);
void write(char ch);

void main()
{

	//freopen("337.in","r",stdin);
	//freopen("out1.txt","w",stdout);
	 
	long test,i,j,cases=1;


	while( gets(temp) )
	{
		test = atol(temp);
		if(test==0)break;
		mode = over;
		row = col = 0;
		flush();

		while(test--)
		{
			gets(line);
			process(line);		
		}
		printf("Case %ld\n+----------+\n",cases++);
		for(i=0;i<=9;i++)
		{	printf("|");
			for(j=0;j<=9;j++)
			printf("%c",a[i][j]);
			printf("|\n");
		}
		printf("+----------+\n");
	}//while
}


void flush()
{
	long i,j;
	for(i=0;i<11;i++)
	{
		for(j=0;j<11;j++)
			a[i][j]=' ';
	}
}

void process(char line[])
{
	long i,j,len;
	len  = strlen(line);

	for(i=0;i<len;i++)
	{
		if(line[i]=='^')
		{
			//b: Move the cursor to the beginning of the current line; the cursor row does not change 
			if(line[i+1]=='b')
			{
				col = 0;
				//row = row;
				i++;
			}
			//c: Clear the entire screen; the cursor row and column do not change
			else if(line[i+1]=='c')
			{
				flush();
				i++;
			}
			//d: Move the cursor down one row if possible; the cursor column does not change 
			else if(line[i+1]=='d')
			{
				if(row<9)
					row++;
				i++;                
			}
			//e: Erase characters to the right of, and including, the cursor column on the cursor's row; the cursor row and column do not change 
			else if(line[i+1]=='e')
			{
				for(j=col;j<10;j++)a[row][j]=' ';
				i++;
			}			 
			//h: Move the cursor to row 0, column 0; the image on the screen is not changed
			else if(line[i+1]=='h')
			{
				row = 0;
				col = 0;
				i++;		
			}
			//i: Enter insert mode
			else if(line[i+1]=='i')
			{
				mode = insert;
				i++;		
			}
			//l: Move the cursor left one column, if possible; the cursor row does not change 
			else if(line[i+1]=='l')
			{
				if(col>0)col--;
				i++;		
			}
			//o: Enter overwrite mode 
			else if(line[i+1]=='o')
			{
				mode = over;
				i++;		
			}
			//r: Move the cursor right one column, if possible; the cursor row does not change 
			else if(line[i+1]=='r')
			{
				if(col<9)col++;
				i++;			
			}
			//u: Move the cursor up one row, if possible; the cursor column does not change
			else if(line[i+1]=='u')
			{
				if(row>0)row--;
				i++;
			}
			//^: Write a circumflex (  ) at the current cursor location, exactly as if it was not a special character; this is subject to the actions of the current mode (insert or overwrite)
			else if(line[i+1]=='^')
			{
				write(line[i+1]);
				i++;				
			}
			//##: Move the cursor to the row and column specified; # represents a decimal digit; the first # represents the new row number, and the second # represents the new column number 
			else if(line[i+1]>='0' && line[i+1]<='9')
			{
				row = line[i+1] - '0';
				col = line[i+2] - '0';
				i+=2;			
			}
			else
			{}
		}
		else
			write(line[i]);

	
	
	
	}//end of for
}


void write(char ch)
{
	long i;
	if(mode==over)
	 a[row][col]=ch;
	else
	{
		for(i=9;i>col;i--)
		a[row][i] =a[row][i-1];
		a[row][col] = ch;
	}
	if(col<9)col++;	
}
