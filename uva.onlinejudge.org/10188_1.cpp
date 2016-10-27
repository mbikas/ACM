#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 12005 //100*120

char *strncat(char *string1, char *string2, int length);
int PE(char *correct,char *output);

int comp(void const *A, void const *B)
{	char *a = (char*)A;
	char *b = (char*)B;
	return *a - *b;
}

void main()
{
	char correct[sz],output[sz],a[125];
	long i,n,m,len;
	long cases=1;
	

	while (gets(a) != NULL) 
	{ 
		n = atol(a); 
		if (n == 0) break; 
		
		for(i=0;i<n;i++)
		{
			gets(a);
			if(i==0)
				strcpy(correct,a);
			else
			{
				len = strlen(a);
				strncat(correct,a,len);
			}		
		}
		gets(a); 
		m = atol(a);	
		for(i=0;i<m;i++)
		{
			gets(a);
			if(i==0)
				strcpy(output,a);
			else
			{
				len = strlen(a);
				strncat(output,a,len);
			}		
		}

		if(m==n && strcmp(correct,output)==0)
			printf("Run #%ld: Accepted\n",cases++);
		else
		{
			//if(m==n && PE(correct,output)==1)
			if(PE(correct,output)==1)
				printf("Run #%ld: Presentation Error\n",cases++);
			else
				printf("Run #%ld: Wrong Answer\n",cases++);	
		}
	
	
	
	}
}


int PE(char *correct,char *output)
{
	long i,len,p;
	char temp1[sz],temp2[sz];
	len = strlen(correct);
	p=0;
	for(i=0;i<len;i++)
	{
		if(correct[i]>='0'&&correct[i]<='9')
			temp1[p++]=correct[i];	
	}
	temp1[p]='\0';
	qsort(temp1,p,sizeof(temp1[0]),comp);

	p=0;
	len = strlen(output);
	for(i=0;i<len;i++)
	{
		if(output[i]>='0'&&output[i]<='9')
			temp2[p++]=output[i];	
	}
	temp2[p]='\0';
	//printf("%s\n%s\n",correct,output);
	//printf("%s %s\n",temp1,temp2);

	qsort(temp2,p,sizeof(temp2[0]),comp);

	if(strcmp(temp1,temp2)==0)
		return 1;
	return 0;

}

//Append the 1st 'length' characters of 'string2' at the end of 'string1'.
char *strncat(char *string1, char *string2, int length)
{
	int i, j;

	for(i = 0, j = strlen(string1); i < length && string2[i] != NULL; i++, j++)
	{
      string1[j] = string2[i];
	}

	string1[j] = NULL;

	return(string1);
}
