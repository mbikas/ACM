/*Huffman code by chormen*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define sz 121
#define NULL 0
#define INF (pow(2, 31)-1)

#define Left(i) (i<<1)
#define Rigt(i) ((i<<1)+1)
#define Parent(i) (i>>1)

#define swap(a, b) a^=b^=a^=b

char sign, letter[sz];
long occur, number, heapSize, freq[sz], bits[sz];

struct node{

	char sign;
	long bits;
     long freq;

	node *rigt;
	node *left;
};

node *huffman[2*sz], *ptr, *ztr, *mid;

void MinHeapify(long ind)
{
	long left, rigt, smallest;

	left = Left(ind);
	rigt = Rigt(ind);

	if(left <= heapSize && huffman[left]->freq < huffman[ind]->freq)
		smallest = left;
	else
		smallest = ind;

	if(rigt <= heapSize && huffman[rigt]->freq < huffman[smallest]->freq)
		smallest = rigt;

	if(smallest != ind)
	{
		mid = huffman[ind];
		huffman[ind] = huffman[smallest];
		huffman[smallest] = mid;

		MinHeapify(smallest);
	}
}

void HeapExtractMin(void)
{
	ptr = huffman[1];
	huffman[1] = huffman[heapSize];

	heapSize-= 1;

	MinHeapify(1);

	return ;
}

void HeapDecreaseKey(long ind)
{
	while(ind > 1 && huffman[Parent(ind)]->freq > huffman[ind]->freq)
	{
		mid = huffman[ind];
		huffman[ind] = huffman[Parent(ind)];
		huffman[Parent(ind)] = mid;

		ind = Parent(ind);
	}
}

void BuildMinHeap(void)
{
	long ind;

	heapSize = 0;
	for(ind = 1; ind <= number; ind++)
	{
		heapSize+= 1;

		huffman[heapSize] = new(node);

		huffman[heapSize]->sign = letter[ind];
		huffman[heapSize]->freq = freq[ind];
		huffman[heapSize]->bits = 0;
		huffman[heapSize]->rigt = NULL;
		huffman[heapSize]->left = NULL;

		HeapDecreaseKey(heapSize);
	}
}

void RunDFS(node *ptr, long bit)
{
	//printf("RunDfs code = %c, %ld\n", ptr->sign, ptr->freq);

	if(ptr->left == NULL && ptr->rigt == NULL)
     {
		ptr->bits = bit;

		long ind = ptr->sign;

          freq[ind] = ptr->freq;
		bits[ind] = ptr->bits;

		/*printf("Answer code = %c, %ld, %ld \n",ptr->sign, ptr->freq, ptr->bits);
		printf("letter = %c, freq = %ld, bits = %ld\n", ind, freq[ind], bits[ind]);*/

		return;
     }

	RunDFS(ptr->left, bit+1);

	RunDFS(ptr->rigt, bit+1);

	return;
}

void HuffmanCode(void)
{
     long ind, left, rigt;

	BuildMinHeap();

	/*for(ind = 1; ind <= number; ind++)
	{
		ptr = huffman[ind];

		printf("Build huffmanCode = %c, %ld\n", ptr->sign, ptr->freq);
	}*/

	for(ind = 1; ind< number; ind++)
	{
		ztr = new(node);
		ztr->freq = ztr->sign = ztr->bits = 0;

		HeapExtractMin();

		//printf("huffmanCode = %c, %ld\n", ptr->sign, ptr->freq);

		ztr->freq+= ptr->freq;
		ztr->left = ptr;

		HeapExtractMin();

		//printf("huffman code = %c, %ld\n", ptr->sign, ptr->freq);

		ztr->freq+= ptr->freq;
		ztr->rigt = ptr;
		
		heapSize+= 1;
		huffman[heapSize] = ztr;

		HeapDecreaseKey(heapSize);

		//printf("huffman code = %c, %ld\n", ztr->sign, ztr->freq);
	}

	HeapExtractMin();
	ztr = ptr;

	//printf("out huffman code = %c, %ld\n", ztr->sign, ztr->freq);

	memset(freq, 0, sizeof(freq));
     memset(bits, 0, sizeof(bits));

	RunDFS(ztr,0);
}

void main(void)
{
	freopen("H:\\shajib_Algorithms Code\\huffmanc.in", "rt", stdin);

	long ind;
	char str[sz];

	while(gets(str))
	{
		
		number = atol(str);
          if(number == 0) break;

		memset(letter, 0, sizeof(letter));
		memset(freq, 0, sizeof(freq));

		for(ind = 1; ind <= number; ind++)
          {
			gets(str);
			sscanf(str, "%c %ld", &sign, &occur);

			letter[ind] = sign;
			freq[ind] = occur;

			//printf("main func = %c, %ld\n", letter[ind], freq[ind]);
		}


		if(number == 1)
		{
			printf("letter = %c, freq = %ld, bits = %ld\n", sign, occur, 1);
          	continue;
		}

		HuffmanCode();

		for(ind = 1; ind < sz; ind++)
		{
			if(bits[ind])
			{
				printf("letter = %c, freq = %ld, bits = %ld\n", (char)ind, freq[ind], bits[ind]);
			}
		}
	}
}