#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 100

typedef struct{
	char dept[100];
	char first[50];
	char title[100];
	char last[50];
	char address[200];
	char home_phone[50];
	char work_phone[50];
	char campus_box[30];
}person;
person persons[10001];
long len=0;
char dep[100];          
int flag=1;

int comp(void const *A, void const *B);
void format(char a[]);

void main()
{

	//freopen("450.in","r",stdin);
	//freopen("450.out","w",stdout);

	int n,ct;

	//////////////////////
	char a[100005];
	/////////////////////

	while(  scanf("%d\n",&n)==1)
	{

			ct=0;
	
			while(gets(a))
			{
						if(strlen(a)==0) 
						{	flag=1;
							ct++;
						}
		
						else   
						{   
							format(a);
							flag=0;				
						}		

						if(ct==n)break;	
	
		
			}

			qsort(persons,len,sizeof(person),comp);

			for(ct=0;ct<len;ct++)
			{   printf("----------------------------------------\n");
				printf("%s %s %s\n",persons[ct].title,persons[ct].first,persons[ct].last);
				printf("%s\n",persons[ct].address);
				printf("Department: %s\n",persons[ct].dept);
				printf("Home Phone: %s\n",persons[ct].home_phone);
				printf("Work Phone: %s\n",persons[ct].work_phone);
				printf("Campus Box: %s\n",persons[ct].campus_box);
			}

			len =0;
			flag=1;
	
	}

}


void format(char a[])
{
		long i,p,x,ct=1;
		char temp[sz];
		
		

		if(flag==1)
			strcpy(dep,a);

		else
		{
				p= strlen(a);
				a[p]=',';

				strcpy(persons[len].dept,dep);
	
				x=0;
				for(i=0;i<=p;i++)
				{
						if(a[i]!=',')
						{
							temp[x]=a[i];
							x++;
						}
						else
						{	
							//while (a[i+1]==' ')i++;
							temp[x]='\0';
		    
							///Title, First Name, Last Name, Street Address, 
							//	Home Phone, Work Phone, and Campus Mailbox.
							if(ct==1)
								strcpy(persons[len].title,temp);			
							else if(ct==2)
								strcpy(persons[len].first,temp);
							else if(ct==3)
								strcpy(persons[len].last,temp);
							else if(ct==4)
								strcpy(persons[len].address,temp);
							else if(ct==5)
								strcpy(persons[len].home_phone,temp);
							else if(ct==6)
								strcpy(persons[len].work_phone,temp);
							else if(ct==7)
								strcpy(persons[len].campus_box,temp);

							ct++;
							x=0;
						 }
				}//end of for loop

				len++;
		}

}

int comp(void const *A, void const *B)
{
	person *a = (person*)A;
	person *b = (person*)B;

	return ( strcmp(a->last,b->last) );



}
