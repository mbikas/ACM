#define SIZE 500005

#include<stdio.h>

int num, temp[SIZE], array[SIZE];
unsigned long long count;

void merge_sort(int start, int end);
void merge_data(int start1, int end1, int start2, int end2);

int main(void)
{
	int i;
	
	while(scanf(" %d", &num) == 1 && num)
	{
		for(i = 0, count = 0; i < num; i++) scanf(" %d", &array[i]);
		merge_sort(0, num - 1);
		printf("%llu\n", count);
	}
	
	return(0);
}

void merge_sort(int start, int end)
{
	int middle;
	
	if (start == end) return;

	middle = (start + end) / 2;
	merge_sort(start, middle);
	merge_sort(middle + 1, end);
	merge_data(start, middle, middle + 1, end);
	
	return;
}

void merge_data(int start1, int end1, int start2, int end2)
{
	int i, j, k;
	
	for(i = start1, j = start2, k = 0; i <= end1 && j <= end2;	)
	{
		if (array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			count += (end1 - i + 1);
			temp[k++] = array[j++];
		}
	}

	while(i <= end1) temp[k++] = array[i++];
	while(j <= end2) temp[k++] = array[j++];

	for(i = 0, j = start1; i < k; i++, j++) array[j] = temp[i];
	
	return;
}