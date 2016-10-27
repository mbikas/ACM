#include<stdio.h>
#include<string.h>
#define sz 100

void tokenize1(char current[]);
void tokenize2(char current[]);
int c_date,c_month,c_year;
int b_date,b_month,b_year;


int main()
{
	int test;
	long days[]={0,31,59,90,120,151,181,212,243,273,304,334,365},cases=1,year,day1,day2;
	char current[sz],birth[sz];
	scanf("%d",&test);

	while(test--)
	{
		scanf(" %[^\n]",current);
		scanf(" %[^\n]",birth);

		tokenize1(current);
		tokenize2(birth);
 	
		//printf("%d %d %d\n",c_date,c_month,c_year);
		//printf("%d %d %d\n",b_date,b_month,b_year);

		year=c_year-b_year;
		day1=days[c_month-1]+c_date;
		day2=days[b_month-1]+b_date;
		if(c_month>2)
		{
			if(c_year%100==0)
			{
				if(c_year%400==0)
					day1++;
			}
			else if(c_year%4==0)
				day1++;
		}

		if(b_month>2)
		{
			if(b_year%100==0)
			{
				if(b_year%400==0)
					day2++;
			}
			else if(b_year%4==0)
				day2++;
		}

		if(day1-day2<0)
			year--;

		if(year<0)
			printf("Case #%ld: Invalid birth date\n",cases++);

		else if(year>130)
			printf("Case #%ld: Check birth date\n",cases++);

		else
			printf("Case #%ld: %ld\n",cases++,year);



	}


	return 0;
}

void tokenize1(char current[])
{
	int i,j,len;
	char temp[10];

	temp[0]=current[0];
	temp[1]=current[1];
	temp[2]='\0';
	sscanf(temp,"%d",&c_date);

	temp[0]=current[3];
	temp[1]=current[4];
	temp[2]='\0';
	sscanf(temp,"%d",&c_month);

	temp[0]=current[6];
	temp[1]=current[7];
	temp[2]=current[8];
	temp[3]=current[9];
	temp[4]='\0';
	sscanf(temp,"%d",&c_year);
}

void tokenize2(char current[])
{
	int i,j,len;
	char temp[10];

	temp[0]=current[0];
	temp[1]=current[1];
	temp[2]='\0';
	sscanf(temp,"%d",&b_date);

	temp[0]=current[3];
	temp[1]=current[4];
	temp[2]='\0';
	sscanf(temp,"%d",&b_month);

	temp[0]=current[6];
	temp[1]=current[7];
	temp[2]=current[8];
	temp[3]=current[9];
	temp[4]='\0';
	sscanf(temp,"%d",&b_year);
}
