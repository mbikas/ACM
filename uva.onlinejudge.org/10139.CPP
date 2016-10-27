//Acm 10139 Factovisor
//solved by Bikas CSE SUST

//Before sqrt(2 ^ 31 - 1) there are 4792 primes.
#define SIZE 4793

#include<stdio.h>
#include<math.h>

long int primes[SIZE], fact, num;
int  prime_num;

void find_all_primes_below(long int num);
long int number_of_divisors(long int num, long int divisor);
long int number_of_primes(long int& num, long int divisor);
int  is_prime(long int num);
int  is_divisible(long int fact, long int num);

int main(void)
{
	find_all_primes_below(sqrt(pow(2, 31) - 1));

	while(scanf(" %ld %ld", &fact, &num) == 2)
	{
		if (is_divisible(fact, num)) printf("%ld divides %ld!", num, fact);
		else printf("%ld does not divide %ld!", num, fact);

		printf("\n");
	}

	return(0);
}

//Find all the prime numbers below 'num'.
void find_all_primes_below(long int num)
{
	long int i;

	prime_num = 0;
	primes[prime_num++] = 2;

	for(i = 3; i <= num; i += 2)
	{
		if (is_prime(i)) primes[prime_num++] = i;
	}

	return;
}

//Return '1' if 'num' is prime else return '0'.
int is_prime(long int num)
{
	int i, loop;

	loop = sqrt(num);

	for(i = 0; i < prime_num && primes[i] <= loop; i++)
   {
		if(num % primes[i] == 0) return(0);
   }

   return(1);
}

int is_divisible(long int fact, long int num)
{
	long int i, loop, temp;

	if (fact == 0 && num == 1) return(1);
	if (num == 0) return(0);
	if (num <= fact) return(1);

	loop = sqrt(num);

	for(i = 0; i < prime_num && primes[i] <= loop && primes[i] <= fact; i++)
	{
		if (num % primes[i] == 0)
      {
			//If the number of 'primes[i]' in number is less than that of the factorial.
			//In the function 'number_of_primes()' 'num' will be divided by 'primes[i]'.
			if (number_of_primes(num, primes[i]) > number_of_divisors(fact, primes[i])) return(0);
			loop = sqrt(num);
		}
	}

	//At last num will be 1 oa will yield a prime. If it is not 1, then we are examining again.
	if (num != 1)
	{
		if (number_of_divisors(fact, num) < 1) return(0);
	}

	return(1);
}

long int number_of_divisors(long int num, long int divisor)
{
	long int sum;

	sum = num = num / divisor;

	while(num >= divisor)
	{
		num /= divisor;
		sum += num;
	}

	return(sum);
}

long int number_of_primes(long int& num, long int divisor)
{
	long int count;

	count = 0;

	while(num % divisor == 0)
	{
		num /= divisor;
		++count;
	}

	return(count);
}