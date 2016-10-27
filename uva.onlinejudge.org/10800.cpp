#define SIZE 110

#include<stdio.h>
#include<string.h>

int  start_x, start_y, min, max;
char result[SIZE][SIZE];

int main(void)
{
	int  i, j, k, kase, test_case;
	char ch, prev_ch;

	scanf(" %d", &test_case);	

	for(kase = 1; kase <= test_case; kase++)
	{
		memset(result, ' ', sizeof(result));
		start_y = min = max = 52;
		start_x = 1;
		prev_ch = NULL;

		scanf(" %c", &ch);

		while(ch != '\n')
		{
			if (ch == 'R')
			{
				if (prev_ch == 'R') result[--start_y][start_x] = '/';
				else result[start_y][start_x] = '/';
			}

			else if (ch == 'F')
			{
				if (prev_ch == 'F' || prev_ch == 'C') result[++start_y][start_x] = '\\';
				else result[start_y][start_x] = '\\';
			}

			else if (ch == 'C')
			{
				if (prev_ch == 'R') result[--start_y][start_x] = '_';
				else result[start_y][start_x] = '_';
			}

			if (start_y < min) min = start_y;
			if (start_y > max) max = start_y;

			start_x++;
			prev_ch = ch;

			scanf("%c", &ch);
		}
      
		printf("Case #%d:\n", kase);
		for(i = min; i <= max; i++)
		{
			printf("|");
			for(j = start_x; j >= 0 && result[i][j] == ' '; j--);
			for(k = 0; k <= j; k++) printf("%c", result[i][k]);

			printf("\n");
		}

      printf("+");
		for(i = 0; i <= start_x; i++) printf("-");
		printf("\n\n");
	}

	return(0);
}
