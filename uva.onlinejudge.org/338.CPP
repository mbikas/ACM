#define SIZE 50

#include<stdio.h>
#include<string.h>

char num1[SIZE], num2[SIZE], result[2 * SIZE], step[SIZE][2 * SIZE];
int  length1, length2;

int  input(char* string);
void character_multiplication(char *num1, char *num2, char *result);
void print_result(void);
void reverse_string(char *string);
void eliminate_leading_zeros(char *number);

int main(void)
{
	while(input(num1) == 1)
	{
		if (input(num2) != 1) break;

		//Find out the result.
		character_multiplication(num1, num2, result);

		//Print the ultimate result.
		print_result();
		printf("\n\n");
	}                                       

	return 0;
}

//Input a string ignoring all the leading zeros.
int input(char* string)
{  
	int i;

	if (scanf(" %c", &string[0]) != 1) return(0);

	i = 0;
	while(string[i] == '0' || string[i] == '-')
	{
		if (scanf("%c", &string[i]) != 1) string[i] = '\n';
   }

	if (string[i] == '\n' || string[i] == ' ')
	{
		sprintf(string, "0");
		return(1);
	}

	while(string[i] != ' ' && string[i] != '\n')
	{
		if (scanf("%c", &string[++i]) != 1) string[i] = '\n';
	}

	string[i] = NULL;

	return(1);
}

//'result' = 'num1' * 'num2'.
void character_multiplication(char *num1, char *num2, char *result)
{
	int i, j, k, index, carry, temp;

	length1 = strlen(num1);
	length2 = strlen(num2);	

	//Assign all elements of 'result' of length 'length1 + length2' with '0'.
	j = length1 + length2;
	for(i = 0; i < j; i++) result[i] = '0';
   	
	//Take one digit from 'num2' one by one.
	for(i = length2 - 1, index = 0; i >= 0; i--, index++)
	{  
		if (num2[i] == '0')
		{
			sprintf(step[i], "0");
			continue;
      }

		//Multiply each digit of 'num1' by the digit taken from 'num2'.
		for(j = length1 - 1, k = 0, carry = 0; j >= 0; j--, k++)
		{
			temp = (num1[j] - '0') * (num2[i] - '0') + carry;			
			step[i][k] = temp % 10 + '0';
			carry = temp / 10;
		}

		if (carry != 0) step[i][k++] = carry % 10 + '0';
		step[i][k] = NULL;

		for(j = index, k = 0, carry = 0; step[i][k] != NULL; j++, k++)
		{
			temp = (result[j] - '0') + (step[i][k] - '0') + carry;
			result[j] = temp % 10 + '0';
			carry = temp / 10;
		}

		if (carry != 0) result[j++] = carry % 10 + '0';

		reverse_string(step[i]);
	}

	if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) sprintf(result, "0");
	else result[j] = NULL;

	reverse_string(result);

	return;
}

void print_result(void)
{
	int i, j, length, loop;	

	if (strcmp(result, "0") == 0) length = (length1 > length2) ? length1 : length2;
	else length = strlen(result);

	//Print 'num1'.
	loop = length - length1;
	for(i = 0; i < loop; i++) printf(" ");
	printf("%s\n", num1);

	//Print 'num2'.
	loop = length - length2;
	for(i = 0; i < loop; i++) printf(" ");
	printf("%s\n", num2);	

	//Print first horizontal line made up of hypens.
	loop = (length1 > length2) ? (length - length1) : (length - length2);
	for(i = 0; i < loop; i++) printf(" ");
	for(	 ; i < length; i++) printf("-");
	printf("\n");

	for(i = length2 - 1; i >= 0 && strcmp(step[i], "0") == 0; i--);

	//If we have less than or equal to 1 intermidiate steps to show, then we wont show them.
	//That time just the result will be shown.
	if (i <= 0)
	{  		
		for(j = strlen(result); j < length; j++) printf(" ");
		printf("%s\n", result);

		return;
	}

	while(i >= 0)
	{
		loop = length - strlen(step[i]) - (length2 - 1 - i);
		for(j = 0; j < loop; j++) printf(" ");
		printf("%s\n", step[i--]);

		while(i >= 0 && strcmp(step[i], "0") == 0) --i;
	}

	for(i = 0; i < length; i++) printf("-");
	printf("\n");

	loop = strlen(result);
	for(i = loop; i < length; i++) printf(" ");
	printf("%s", result);

	return;
}

//Reverse the string 'string'.
void reverse_string(char *string)
{
	int i, length, temp;

   length = strlen(string);

	for(i = 0; i < length / 2; i++)
	{
		temp = string[i];
		string[i] = string[length - i - 1];
		string[length - i - 1] = temp;
	}

	return;
}