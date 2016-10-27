//Acm 10042 Smith Number
//solved by Bikas CSE SUST
#include<stdio.h>
#include<math.h>

long long int num;

int is_smith_number(long long int num);
int find_prime_factors(long long int num);
int sum_of_all_digits(long long int num);

int main(void)
{
	int i, test_case;

	scanf(" %d", &test_case);

	for(i = 0; i < test_case; i++)
	{
		scanf(" %lld", &num);

		while(!is_smith_number(++num));

		printf("%lld\n", num);
	}

	return 0;
}

int is_smith_number(long long int num)
{
	int sum1, sum2;

	sum1 = sum_of_all_digits(num); 
	sum2 = find_prime_factors(num);

	if (sum1 != sum2) return(0);

	return(1);
}

int find_prime_factors(long long int num)
{
	long long int i, loop, save;
	int sum;

	save = num;
   sum = 0;

	while(2 <= sqrtl(num) && num % 2 == 0)
	{
		sum += 2;
		num = num / 2;
	}

   i = 3;
   loop = sqrtl(num);

	while(i <= loop)
   {
		if (num % i == 0)
		{
			sum += sum_of_all_digits(i);
			num = num / i;
         loop = sqrtl(num);
		}

		else
		{
			i += 2;
		}
	}

	//'save' = 'num' means 'num' is a prime and a prime is not a smith number.
	if (save == num) return(-1);

	sum += sum_of_all_digits(num);

	return(sum);
}

int sum_of_all_digits(long long int num)
{  	
	char number[12];
	int i, sum;

	sprintf(number, "%lld", num);

	sum = 0;

	for(i = 0; number[i] != NULL; i++)
	{
		sum += (number[i] - '0');
	}

	return(sum);
}