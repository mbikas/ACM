#include<stdio.h>
#include<string.h>

#define sz 1000002


void main()
{
	char a[sz],str[sz],old[sz];
	long i,p,Length,flag,x;


	while(scanf(" %[^\n]",a)==1)
	{
					if(strcmp(a,".")==0)break;					

					strcpy(old,"");
					p = strlen(a);
					for(Length = 1;Length<=p;Length++)
					{
						if(p%Length !=0)
							continue;
						x = (long)p/Length;
						flag=1;
						if(x==1)
						{	printf("%ld\n",x);
							break;
						}
						for(i=0;i<p;i+=Length)
						{
							strncpy(str,a+i,Length);
							str[Length]='\0';
							//printf("%s\n",str);
							if(i>0)
							{
								if(strcmp(str,old)!=0)
								{	flag=0;
									break;
								}
							
							}
							strcpy(old,str);							
						}

						if(flag==1)
						{
							printf("%ld\n",x);
							break;
						}
				
					
					}//end of for		
				
				

	
	
	}//end of while

}//end of main



