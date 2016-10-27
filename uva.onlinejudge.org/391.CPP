#define ON  '1'
#define OFF '0'

#include<stdio.h>

char html;

void handle_command(void);

int main(void)
{
	char ch;

	html = ON;

	while(scanf("%c", &ch) == 1)
	{
		if (ch == '\\') handle_command();
		else printf("%c", ch);
	}

	return(0);
}

void handle_command(void)
{
	char ch;
	int  dot;

	if (scanf("%c", &ch) != 1) return;

	if (ch == '*')
	{
		if (html == ON) html = OFF;
		else html = ON;

		return;
	}

	if (html == OFF)
	{
		printf("\\%c", ch);
		return;
   }

	if (ch != 'b' && ch != 'i' && ch != 's')
	{
		printf("%c", ch);
		return;
   }	

	if (ch == 's')
	{
		dot = 0;

		if (scanf("%c", &ch) != 1) return;

		while((ch >= '0' && ch <= '9') || ch == '.')
		{
			if (ch == '.')
			{
				if (dot > 0) break;
				else ++dot;
			}

			if (scanf("%c", &ch) != 1) return;
		}

		if (ch == '\\') handle_command();
		else printf("%c", ch);
	}

	return;
}