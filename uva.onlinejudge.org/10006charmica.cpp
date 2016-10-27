#include<stdio.h>
#include<math.h>

long num;

int is_prime(void);
int is_carmichael(void);
int modulus(long n, long power);

int main(void)
{
	while(scanf("%ld", &num)==1)
	{


		if (num == 0) break;

		if (is_prime())
		{
			printf("%d is normal.", num);
		}

		else
		{
		  if (is_carmichael()==0)
			 printf("The number %d is a Carmichael number.", num);
		  else
          printf("%d is normal.", num);

		}

		printf("\n");
	}

	return 0;
}

int is_prime(void)
{
	int i;

	if (num == 2) return(1);

	for(i = 3; i <= sqrt(num); i += 2)
	{
		if (num % i == 0) return(0);
	}

	return(1);
}

int is_carmichael(void)
{
	long i;

	for(i = 2; i < num; i++)
	{
		if (i != modulus(i, num)) return(0);
	}

	return(1);
}

int modulus(long n, long power)
{
	long mod;

	if (n == 0)   return(n);
	if (power == 1) return(n);

	mod = (n * n) %num;

	mod = modulus(mod, power / 2);

	if (power % 2 == 1)
	{
		mod = mod * n;
		mod = mod % num;
	}

	return(mod);
}