#include<iostream>
#include<cstdio>
using namespace std;

void string_sort(int n);
int binary_search(long n);

 typedef struct
 {
	char c[20];
	long salary;
  }dictionary;

 dictionary d[1001];

char word[50];



void main()
{
	long i,n,m;
	int p;
	double total;

	while(scanf("%ld %ld",&n,&m)==2)
	{
		for(i=0;i<n;i++)
		 scanf (" %s %ld",d[i].c,&d[i].salary);

		 string_sort(n);

		//for(i=0;i<n;i++)
		//printf("%s %ld\n",d[i].c,d[i].salary);
		

		while(m>0)
		{
			total =0;
			
			while(scanf(" %s",word)==1)
			{
		
				if(strlen(word)==1 && word[0]=='.')
				break;
                
				p= binary_search(n);

				if(p!=-1)
				  total = total + d[p].salary;
				
				//cout << p <<" ";

						 
			}

		
			printf("%.0lf\n",total);

            
			m--; 

		}



	}


}


void string_sort(int n)
  {
	 char temp[20];
	 int  i,j;
	 long num;


	  for(i=1;i<n;i++)
	  for(j=0;j<n-i;j++)
		{
		  if( strcmp( d[j].c,d[j+1].c)>0)
			{
			  strcpy(temp ,d[j].c);
			  strcpy(d[j].c,d[j+1].c);
			  strcpy(d[j+1].c,temp);

			  num = d[j].salary;
			  d[j].salary = d[j+1].salary;
			  d[j+1].salary = num;

			}
		}
  }


int binary_search(long n)
{
 
	int beg,end,mid;
	beg = 0;
	end = n;

	mid = (int)((beg+end)/2);

	while(beg<=end && (strcmp(d[mid].c,word)!=0) )
	{
		if( strcmp(word,d[mid].c) < 0 )
			end = mid-1;
		else
			beg = mid+1;

		mid = (int)((beg+end)/2);

	
	}


	if( strcmp(d[mid].c,word)==0  )
		return mid;
    
	return -1;

}