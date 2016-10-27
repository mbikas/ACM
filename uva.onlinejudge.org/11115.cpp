#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 1000

void character_multiplication(char *num1, char *num2, char *result);
void reverse_string(char *string);

void main()
{
	//freopen("out1.txt","w",stdout);

	char a[sz],b[sz],res[sz];
	 int nep,cd,i; 

	while(scanf("%d %d",&nep,&cd)==2)
	{
		if(nep==0 && cd==0)break;

		if(cd==0)
		{
			printf("1\n");
			continue;		
		}
	
        if(cd==1)
		{
				printf("%d\n",nep);
				continue;
		
		}
		
		strcpy(res,"0");
		sprintf(b,"%d",nep);
		strcpy(a,b);
		for(i=0;i<cd-1;i++)
		{
			character_multiplication(a,b,res);
			//strcpy(a,res);
			strcpy(b,res);
		}
		printf("%s\n",res);
	
	}



}

//Reverse the string 'string'.
void reverse_string(char *string)
{
	long i, length;

	for(i = 0, length = strlen(string); i < length / 2; i++)
	{
		string[i] ^= string[length - i - 1] ^= string[i] ^= string[length - i - 1];
	}

	return;
}


//'result' = 'num1' * 'num2'.
//'result' is created in reverse order. So, we reverse it again by calling 'reverse_string()'
//at the last portion of this function.
void character_multiplication(char *num1, char *num2, char *result)
{
	long i, j, k, index, carry, temp, length1, length2;

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

	reverse_string(result);

	return;
}