#include<stdio.h>
#include<string.h>
#define sz 105

int number_compare(char num1[],char num2[]);
void delete_leadingzero(char x[]);

void main()
{

	int index;
	char num1[105],num2[105];

	
   while(scanf(" %s %s",num1,num2)==2)
   {
	   delete_leadingzero(num1);
	   delete_leadingzero(num2);
	
	   index = number_compare(num1,num2);
	   printf("%s--%s == %d\n",num1,num2,index);




   }//end of while

}//end of main


                                                     
//compare num2 with num1//////                         
//     return 0 if  num2 = num1  //
//     return 1 if  num2 > num1  //
//     return -1 if num2 < num1  // 
int number_compare(char num1[],char num2[])
{
	long len1,len2,i,flag;


	len1 = strlen(num1);
	len2 = strlen(num2);

	if(len2 > len1)
		return 1;
	
	else if(len1 == len2)
	{
		flag = 2;
	                                    
		for(i=0;i<len1;i++)
		{
		
			if(num1[i]>num2[i])
			{	flag =1;
				break;
			}
			else if(num1[i]<num2[i])
			{  flag=0;
			   break;
			}
			else
              flag  = -1;
		}

		if(flag==-1)
			return 0;
		if(flag==1)
	        return -1;
		if(flag==0)
			return 1;
	
	
	}
	return -1;

}



void delete_leadingzero(char x[])
{

	long p,len,i,j;
	char temp[sz];

	p= strlen(x);
	
	if(p==1)
		return;
	len =0;
	for(i=0;i<p-1;i++)
	{
				if(x[i]!='0')
				break;		
	}
	for(j=i;j<p;j++)
	{
		temp[len++] = x[j];	
	}

	temp[len] = '\0';		
	strcpy(x,temp);


}
