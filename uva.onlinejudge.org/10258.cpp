#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

	int name;
	long penelty;
	int prob_no[10];
	char status[10];
	int total;
	
}contest;
contest contests[105];

int max;
int comp(const void* A, const void* B);
void read_inputs();
void read_string();


void main()
{

	//freopen("10258.in","r",stdin);
	//freopen("10258.out","w",stdout);

	int i,j,test;
	char c;	

	scanf("%d%c",&test,&c);

	while(test>0)
	{
	
		scanf("%c",&c);

		for(i=0;i<101;i++)
		{
			contests[i].penelty = 0;
			contests[i].name =0;
			contests[i].total=0;
			for(j=0;j<10;j++)
			contests[i].prob_no[j] = 0;
			for(j=0;j<10;j++)
			contests[i].status[j] = 'I';
		}
		

		if(test==1)
           read_inputs();
	    else
		   read_string();
	

		qsort(contests,max+1,sizeof(contest),comp);


		for(i=0;i<=max;i++)
		{
	
			if(contests[i].name!=0)
			printf("%d %d %d\n",contests[i].name,contests[i].total,contests[i].penelty);

			//interchange

			//if(contests[i].total!=0)
			//printf("%d %d %d\n",contests[i].name,contests[i].total,contests[i].penelty);

		}


		test--;
		if(test!=0)
		printf("\n");
	
	}//end of while

}//end of main


int comp(const void* A, const void* B)
{
	contest *a=(contest*)A;
	contest *b=(contest*)B;

	if(a->total > b->total) return(-1);
	if(a->total < b->total) return(1);

	if(a->penelty > b->penelty) return(1);
	if(a->penelty < b->penelty) return(-1);

	

	return 0;


}




//taking input as a string /////
// if enter is found as string that indicates the end of input set////
///else tokenizing the string//////////////////

void read_string()
{
	
	int problem,name,time,p,n,x,i;
	char status,str[30],c,temp[15];
	
	

	

	
      while(scanf("%[^\n]",str)==1)
	  {
		 scanf("%c",&c);
	     p = strlen(str);

		 if(strlen(str)==0)break;
		 
	     n=0;
		 x = 0;
		 for(i=0;i<p;i++)
		 {
		   if(str[i]!=' ')
			   temp[n++] = str[i];
		   else
		   {
		      temp[n]='\0';
			  if(x==0)
			  sscanf(temp,"%d",&name);
			  else if(x==1)
			  sscanf(temp,"%d",&problem);
			  else if(x==2)
			  sscanf(temp,"%d",&time);
			  n=0;
			  x++;		   
		   }		 
		 }

		 status = str[p-1];
		 
		 
		 if(name>max)max = name; 
		    

			if(status=='I')
			{
				if(contests[name].status[problem]!='C')
					contests[name].prob_no[problem] += 20;
				contests[name].name = name;

			}
			else if(status=='C')
			{
				if(contests[name].status[problem] !='C')
				{
					contests[name].penelty += contests[name].prob_no[problem] + time;
					contests[name].total++;
				}
				contests[name].status[problem] = 'C';
				contests[name].name = name;
			
			}
			else
			{
				
				contests[name].name = name;
			
			}

			
		}
	

}


///normally taking the inputs////////////
void read_inputs()
{
	
	int name,problem,time;
	char status;

	
	max=0;

	while( (scanf("%d %d %d %c\n",&name,&problem,&time,&status)) !=EOF )
	{
		    if(name>max)max = name; 
		    

			if(status=='I')
			{
				if(contests[name].status[problem]!='C')
					contests[name].prob_no[problem] += 20;
				contests[name].name = name;

			}
			else if(status=='C')
			{
				if(contests[name].status[problem] !='C')
				{
					contests[name].penelty += contests[name].prob_no[problem] + time;
					contests[name].total++;
				}
				contests[name].status[problem] = 'C';
				contests[name].name = name;
			
			}
			else
			{
				
				contests[name].name = name;
			
			}	

	}
	

}



