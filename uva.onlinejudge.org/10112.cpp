#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct{

	char a;
	long x;
	long y;
} POINT;

POINT p[20]; 


void main()
{

	//freopen("10112.in","r",stdin);
	//freopen("10112.out","w",stdout);

	long n,i,j,k,l,max,temp;

	double a1,a2,a3,a4;

	int flag;
	char c[5];

	while(scanf("%ld ",&n)==1 && n!=0)
	{
	
        max  = 0 ;
		
		for(i=0;i<n;i++)
		scanf("%c %ld %ld ",&p[i].a,&p[i].x,&p[i].y);
		
		//for(i=0;i<n;i++)
		//printf("%c %ld %ld\n",p[i].a,p[i].x,p[i].y);
		
		
		for(i=0;i<n-2;i++)
		{
		  for(j=i+1;j<n-1;j++)
		  {

           for(k = j+1;k<n;k++)
		   {
             a4 = 0.5 * ((p[k].y - p[i].y)*(p[j].x - p[i].x) - (p[j].y - p[i].y)*(p[k].x - p[i].x));
		     a4 = fabs(a4);
		     temp = (long)a4; 
		     flag  = 1 ;
		   
		     for(l=0;l<n;l++)
			 {
			  if(l!=i && l!=j && l!=k)
			  {
					
					a1 = 0.5 * ((p[l].y - p[i].y)*(p[j].x - p[i].x) - (p[j].y - p[i].y)*(p[l].x - p[i].x)); 
					a2 = 0.5 * ((p[l].y - p[i].y)*(p[k].x - p[i].x) - (p[k].y - p[i].y)*(p[l].x - p[i].x)); 
					a3 = 0.5 * ((p[l].y - p[k].y)*(p[j].x - p[k].x) - (p[j].y - p[k].y)*(p[l].x - p[k].x)); 
               
					a1 = fabs(a1);
					a2 = fabs(a2);
					a3 = fabs(a3);
					

					//printf("%c %c %c %c %ld\n",p[i].a,p[j].a,p[k].a,p[l].a,temp);

					
					if((a1+a2+a3-a4)>0.000001)
						flag = 1;
					else 
					{   flag = 0;
					    break;
					}	
			   
			  } 
			   
			 }//end of 4th loop 
		   
		   
			 if(flag==1)
			 {   if(temp>max)
					{
						max = temp;
						c[0] = p[i].a;
						c[1] = p[j].a;
						c[2] = p[k].a;
						//printf("%c %c %c %ld\n",p[i].a,p[j].a,p[k].a,temp);
					}			   
			}		   




		   }//end of 3rd loop
		  
		  }//end of 2nd loop
		
		
		}//end of 1st loop


		

		printf("%c%c%c\n",c[0],c[1],c[2]);
		

	
	
	
	
	} // end of while

}//end of main