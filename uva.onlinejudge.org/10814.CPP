#define SIZE 100

char ch, num[SIZE], den[SIZE], result[SIZE], mod[SIZE], temp1[SIZE], temp2[SIZE];

#include<stdio.h>
#include<string.h>

void character_subtraction(char *num1, char *num2, char *result);
void character_multiplication(char *num1, char *num2, char *result);
int find_division_time(char *dividend, char *divisor);
void character_division(char *num1, char *num2, char *result, char *mod);
void multiply_by_integer(char *num, int multiplier, char* result);
void reverse_string(char *string, int length);
int compare_number(char *dec1, char *dec2);

int main(void)
{
	int test_case;

	scanf(" %d", &test_case);

	while(test_case--)
	{
		scanf(" %s %c %s", num, &ch, den);

		strcpy(temp1, num);
		strcpy(temp2, den);

		if (compare_number(num, den) < 0)
		{
			strcpy(result, num);
			strcpy(num, den);
			strcpy(den, result);
		}

		character_division(num, den, result, mod);
		while(mod[0] != '0')
		{
			strcpy(result, den);
			strcpy(den, mod);
			strcpy(num, result);
			character_division(num, den, result, mod);
		}
		character_division(temp1, den, result, mod);
		printf("%s / ", result);
		character_division(temp2, den, result, mod);
		printf("%s\n", result);
	}

	return(0);
}

//Reverse the string 'string' where function is provided with the length of 'string'.
void reverse_string(char *string, int length)
{
	int i;

	for(i = 0; i < length / 2; i++)
	{
		string[i] ^= string[length - i - 1] ^= string[i] ^= string[length - i - 1];
	}

	return;
}

//Return '0' if  'dec1' == 'dec2', positive if 'dec1' > 'dec2', negative if 'dec1' < 'dec2'.
int compare_number(char *dec1, char *dec2)
{
	int length1, length2, result;

	//If one of the number is negative, process them here.
	if (dec1[0] != '-' && dec2[0] == '-') return(1);
	if (dec1[0] == '-' && dec2[0] != '-') return(-1);

	//If the numbers are not having equal sign, they will not come here.
	length1 = strlen(dec1);
	length2 = strlen(dec2);

	if (length1 == length2) result = strcmp(dec1, dec2);
   else result = length1 - length2;

   //If both the number are negative.
   if (dec1[0] == '-') return(-result);
   else return(result);
}

void multiply_by_integer(char *num, int multiplier, char* result)
{
	int i, index, carry, mul;

	if (multiplier == 0)
	{
		sprintf(result, "0");
   	return;
	}

	for(i = strlen(num) - 1, carry  = index = 0; i >= 0; i--)
	{
		mul = (num[i] - '0') * multiplier + carry;
		carry = mul / 10;
		result[index++] = mul % 10 + '0';
	}

	while(carry != 0)
	{
		result[index++] = carry % 10 + '0';
		carry /= 10;
	}

	if (index == 0) result[index++] = '0';
	result[index] = NULL;

	reverse_string(result, index);

	return;
}

//We are assuming 'num1' > 'num2' (if not we swap them) & performing 'num1' - 'num2'.
//If 'num1' < 'num2', then we add a '-' at the 1st of 'result' (i.e., the result is negative).
void character_subtraction(char *num1, char *num2, char *result)
{
	int  i, j, k;
	char *swap;

   //If 'num1' < 'num2', then swap them and put '-' at the first of the 'result'.
	if (compare_number(num1, num2) < 0)
	{
		swap = num1; num1 = num2; num2 = swap;
      sprintf(result, "-%s", num1);
	}

	else strcpy(result, num1);

	for(i = strlen(result) - 1, j = strlen(num2) - 1; j >= 0; i--, j--)
	{
      if (result[i] >= num2[j])
      {
         result[i] = result[i] - num2[j] + '0';
      	continue;
      }

		result[i] = (result[i] + 10) - num2[j] + '0';
		for(k = i - 1; k > 0 && result[k] == '0'; k--) result[k] = '9';
		result[k] -= 1;
	}

   //Ignoring all the leading zeros.
   for(i = (result[0] == '-') ? 1 : 0; result[i] == '0'; i++);

   //If the result is 0, then previous loop will end in 'NULL'.
   if (result[i] == NULL) --i;

   //Launch all the digits other than leading zeros.
   for(j = (result[0] == '-') ? 1 : 0;	result[i] != NULL; j++, i++) result[j] = result[i];

   result[j] = NULL;

	return;
}

//'result' = 'num1' * 'num2'.
//'result' is created in reverse order. So, we reverse it again by calling 'reverse_string()'
//at the last portion of this function.
void character_multiplication(char *num1, char *num2, char *result)
{
	int i, j, k, index, carry, temp, length1, length2;

	//If any number is 0, then the result is 0.
	if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
	{
		sprintf(result, "0");
		return;
   }

	length1 = strlen(num1);
	length2 = strlen(num2);

	//Assign all elements of 'result' of length 'length1 + length2' with '0'.
	j = length1 + length2;
	for(i = 0; i < j; i++) result[i] = '0';

	//Take one digit from 'num2' one by one.
	for(i = length2 - 1, index = 0; i >= 0; i--, index++)
	{
		if (num2[i] == '0') continue;

		//Multiply each digit of 'num1' by the digit taken from 'num2'.
		for(j = length1 - 1, k = index, carry = 0; j >= 0; j--, k++)
		{
			temp = (num1[j] - '0') * (num2[i] - '0') + (result[k] - '0') + carry;
			carry = temp / 10;
			result[k] = temp % 10 + '0';
		}

		if (carry != 0) result[k++] = carry % 10 + '0';
	}

	if (k == 0) result[k++] = '0';
	result[k] = NULL;

	reverse_string(result, k);

	return;
}

//'result' = 'num1' / 'num2'.
//'mod'    = 'num1' % 'num2'.
void character_division(char *num1, char *num2, char *result, char *mod)
{
	int i, index = 0;

	//Launch the very first 'length2' characters in 'mod'.
	for(i = 0; num1[i] != NULL && num2[i] != NULL; i++) mod[i] = num1[i];
	mod[i] = NULL;

	//If 'mod' >= 'num2'.
	if (compare_number(mod, num2) >= 0)
	{
		result[index++] = find_division_time(mod, num2) + '0';
	}

	//Launch the rest characters one by one.
	while(num1[i] != NULL)
	{
		strncat(mod, &num1[i++], 1);
		result[index++] = find_division_time(mod, num2) + '0';
	}

	if (index == 0) result[index++] = '0';
	result[index] = NULL;

	return;
}

//It return the divison time required to divide 'devidend' by 'divisor'.
int find_division_time(char *dividend, char *divisor)
{
	int  num, length1, length2;
	char sub[SIZE + 1], mul[SIZE + 3];

	length1 = strlen(dividend);
	length2 = strlen(divisor);

	if (length1 < length2) return(0);

	//Launch the first 1 or 2 digits of the dividend.
	num = dividend[0] - '0';
	if (length1 > length2 && length1 > 1) num = num * 10 + (dividend[1] - '0');

	num = num / (divisor[0] - '0');
	multiply_by_integer(divisor, num, mul);

	while(compare_number(mul, dividend) > 0)
	{
		--num;
		multiply_by_integer(divisor, num, mul);
	}

	character_subtraction(dividend, mul, sub);
	strcpy(dividend, sub);

	return(num);
}