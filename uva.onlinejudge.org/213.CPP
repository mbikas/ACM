#define SIZE 260

#include<stdio.h>
#include<math.h>

char header[SIZE];

int scan_binary(int num);

int main(void)
{
	int i, length, index, back, last;

	while(scanf(" %[^\n]", header) == 1)
	{
		while((length = scan_binary(3)) > 0)
      {
			last  = pow(2, length) - 1;			
			back  = pow(2, length) - 2 - (length - 1);
			index = scan_binary(length);

			while(index != last)
			{
				index += back;
				printf("%c", header[index]);
				index = scan_binary(length);
			}
		}

		printf("\n");
	}

	return(0);
}

int scan_binary(int num)
{  
	int  i, temp;
	char ch;

	temp = 0;

	for(i = 0; i < num; i++)
	{
		scanf(" %c", &ch);
		temp = 2 * temp + (ch - '0');
	}

	return(temp);
}