#include <stdio.h>
#define MAX 25

unsigned long long table[MAX][MAX];

void generate(void)
{
	int i, j;

	for (i = 1; i < 22; i++)
	{
		table[i][0] = 1;
		table[1][i] = 0;
	}

	for (i = 2; i < 22; i++)
		for (j = 1; j <= i; j++)
			table[i][j] = (i - 1) * table[i - 1][j - 1] + table[i - 1][j];
}

void main()
{
	int n, k;

	generate();

	while (scanf ("%d %d", &n, &k) == 2 && (n || k))
		printf ("%llu\n", table[n][k]);

}
