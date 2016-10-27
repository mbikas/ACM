#include<stdio.h>
#include<string.h>

typedef struct{
	char a[85];
} FIND;

typedef struct{
	char a[85];
}REPLACE;

FIND f[12];
REPLACE r[12];

long pattern_match(char str1[],char str2[]);


void main()
{

	//freopen("10115.in","r",stdin);
	//freopen("10115.out","w",stdout);

    long i,j,n,index,len1,len,x;
	char str[260],c;
	char strf[260],strl[260];
	long p,q;


	while(scanf("%ld",&n)==1 && n!=0)
	{
	

		for(i=0;i<11;i++)
		{
		 strcpy(f[i].a,"");
		 strcpy(r[i].a,"");
		}
		
		//////////////taking inputs/////////////

		scanf("%c",&c);
		for(i=0;i<n;i++)
		{
		 scanf("%[^\n]",f[i].a);
		 scanf("%c",&c);
		 scanf("%[^\n]",r[i].a);
         scanf("%c",&c);
		}

		scanf(" %[^\n]",str);

		/*
		for(i=0;i<n;i++)
		{
		 printf("%s\n",f[i].a);
		 printf("%s\n",r[i].a);		
		}
		printf("%s\n",str);
		*/
		//////end of input////////////////////



        // searching and replacing///////////////// 
        
		
		for(i=0;i<n;i++)
		{
			len1 = strlen(f[i].a);

			index = pattern_match(str,f[i].a);
			len = strlen(str);

			while( index!=-1)
			{
				//printf("%ld\n",index);
                
				p=0;
				for(j=0;j<index;j++)
                strf[p++] =str[j];
				
				q=0;
				for(j=index+len1;j<len;j++)
				strl[q++] = str[j];
                
				

				//  //
				len = 0;
				for(j=0;j<p;j++)
				str[len++] = strf[j];
				x = strlen(r[i].a);
				for(j=0;j<x;j++)
				str[len++] = r[i].a[j];
				for(j=0;j<q;j++)
				str[len++] = strl[j];
				str[len]='\0';
				//   //

				//printf("%s\n",str);		

				
				index = pattern_match(str,f[i].a);
			
			
			
			}
	
		}//end of for loop

		/////////////////////////////////////////////
	
		printf("%s\n",str);
	
	
	
	}//end of while


}//end of main







long pattern_match(char str1[],char str2[])
{
		char *p;
		long index;

      //pointer to pattern of str2 in str1
		//If pattern is not available NULL to (p)
		p=strstr(str1,str2);

		if(p)
		 {
			//printf(p);
			//index of pattern in str1
			index=p-str1;
		 }
		else
		 {
			//Ifpattern is not available
			index=-1;
		 }

		return index;
}
