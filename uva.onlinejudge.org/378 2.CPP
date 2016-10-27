#define PARALLEL 1
#define LINE 2

#include<stdio.h>

long int x1, y1, x2, y2, x3, y3, x4, y4;
double x, y;

int  find_intersecting_point(void);
long int  find_gcd(long int divisor, long int dividend);
void reduce_equation(long int *num1, long int *num2, long int *num3);

int main(void)
{
	int i, status, test_case;

	scanf(" %d", &test_case);

	printf("INTERSECTING LINES OUTPUT\n");

	for(i = 0; i < test_case; i++)
	{
		scanf(" %ld %ld %ld %ld %ld %ld %ld %ld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

		status = find_intersecting_point();

		if (status == PARALLEL) printf("NONE");
		else if (status == LINE) printf("LINE");
		else printf("POINT %.2lf %.2lf", x, y);

		printf("\n");
	}

	printf("END OF OUTPUT\n");

	return(0);
}

int find_intersecting_point(void)
{
	long int a1, a2, b1, b2, c1, c2, denominator;

	//Parameter of equation 1.
	a1 = y1 - y2;
	b1 = x1 - x2;
	c1 = x1 * (y1 - y2) - y1 * (x1 - x2);	

	//Reduce equation 1.
	reduce_equation(&a1, &b1, &c1);

	//Parameter of equation 2.
	a2 = y3 - y4;
	b2 = x3 - x4;
	c2 = x3 * (y3 - y4) - y3 * (x3 - x4);

	//Reduce equation 2.
	reduce_equation(&a2, &b2, &c2);

	if (a1 == a2 && b1 == b2 && c1 == c2) return(LINE);
	if (a1 == a2 && b1 == b2) return(PARALLEL);

	denominator = b1 * a2 - a1 * b2;
	x = ((double)b1 * c2 - c1 * b2) / denominator;
	y = ((double)a1 * c2 - c1 * a2) / denominator;

	return(0);
}

void reduce_equation(long int *num1, long int *num2, long int *num3)
{
	long int gcd;

	//Determine the gcd of the 1st 2 numbers.
	if ((*num1) == 0 && (*num2) == 0) gcd = 1;
	else if ((*num1) == 0 && (*num2) != 0) gcd = (*num2);
	else if ((*num1) != 0 && (*num2) == 0) gcd = (*num1);
	else gcd = find_gcd(*num1, *num2);

	//Determine the total gcd.
	if ((*num3) != 0) gcd = find_gcd(gcd, (*num3));

	(*num1) = (*num1) / gcd;
	(*num2) = (*num2) / gcd;
	(*num3) = (*num3) / gcd;

	return;
}

//'divisor' < 'dividend'. Return 'gcd' of 'dividend' & 'divisor'.
long int find_gcd(long int divisor, long int dividend)
{
	long int temp;

	if (divisor > dividend)
	{
		temp = dividend;
		dividend = divisor;
		divisor  = temp;
	}

	while(dividend % divisor != 0)
	{
		temp = divisor;
		divisor  = dividend % divisor;
		dividend = temp;
	}

	return(divisor);
}