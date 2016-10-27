
#include<stdio.h> 
#include<string.h> 
#define MAX 205 // size of each sequence 

char str1[MAX],str2[MAX]; // the sequences 

/* ********************************************* */ 

/* This function calculate the LCS length */ 

/* Input : Tow Sequence and an bool I. If */ 

/* I is FALSE(0) then the function */ 

/* do not print the LCS and if */ 

/* TRUE(1) then print using the */ 

/* above p_lcs function */ 

/* Output: None */ 

/* ********************************************* */ 

int LCS_LNT(bool I) 

{ 

		int c[MAX][MAX]={0},b[MAX][MAX]={0},l1,l2; 

		l1 = strlen(str1)+1; 
		l2 = strlen(str2)+1;
		
		register int i,j; 

		for(i=1;i<l1;i++) 
		{ 
			for(j=1;j<l2;j++) 
			{ 
				if( str1[i-1] == str2[j-1] ) 
				{ 
					c[i][j] = c[i-1][j-1] + 1; 
					b[i][j] = 1; 
				} 

				else if(c[i-1][j] >= c[i][j-1]) 

				{ 
					c[i][j] = c[i-1][j]; 
					b[i][j] = 2; 

				} 

				else c[i][j] = c[i][j-1]; 

			} 
		} 

		return c[l1-1][l2-1];	

} 



/* a sample main function */ 

void main(void) 

{ 
	int len;
	long ct=1;

	while(gets(str1))
	{
		if(strcmp(str1,"#")==0)break;
		
		gets(str2);
		len = LCS_LNT(1); 
		printf("Case #%ld: you can visit at most %d cities.\n",ct,len);
		ct++;
	} 

} 

