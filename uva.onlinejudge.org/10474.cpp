#include<stdio.h>
#include<stdlib.h>

#define sz 100000

int a[sz+1];

int comp(const void* a, const void* b);
int binary_search(int a[],int m,int item);

void main()
{

	//freopen("10474.in","r",stdin);
	//freopen("10474.out","w",stdout);
	int i,n,m,item,count=1,index;

	while(scanf("%d %d",&n,&m)==2 && (m!=0||n!=0) )
	{
		
		for(i=0;i<n;i++)scanf("%d",&a[i]);

		qsort(a,n,sizeof(a[0]),comp);

		

		printf("CASE# %d:\n",count);


		while(m>0)
		{
		
		 scanf("%d",&item);

		 index = binary_search(a,n,item);

		 if(index!=-1)
		 {  
			 printf("%ld found at %ld\n",item,index);

		 
		 }
		 else
		   printf("%ld not found\n",item);

		 

		 m--;
		
		}


		count++;
	}


}




int comp(const void* a, const void* b)
{
 
	int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}


int binary_search(int a[],int m,int item)
{
	int beg,mid,end;

	beg=0;
	end=m-1;
	mid=(int)( (beg+end)/2 );

	while(beg<=end && a[mid]!=item )
	{
		if(item<a[mid] )
			end=mid-1;
		else
			beg=mid+1;

		mid=(int)( (beg+end)/2 );
	}

	if(a[mid]==item)
	{ 
		for(int i=mid-1;i>=0;i--)
		{
			if(a[i]==item)
				mid = i;
			else
				break;
	  
		}
		return mid+1;
	}
	
	return -1;

}
