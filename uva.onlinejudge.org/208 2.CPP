#define SIZE 21
#define NO  '0'
#define YES '1'

#include<stdio.h>

int  tail, end, max, path_num, queue[SIZE], street[SIZE];
char reachable[SIZE], count[SIZE], path[SIZE][SIZE];

void initial_state(void);
void find_all_reachable_nodes(int node);
void find_path(int node, int index);
void print_path(int num);

int main(void)
{
	int start, dest, case_num;

	case_num = 1;

	while(scanf(" %d", &end) == 1)
	{  
		initial_state();

		//'max' keeps the maximum numbering of nodes.
		max = end;

		while(scanf(" %d %d", &start, &dest) == 2)
		{
			if (start == 0 && dest == 0) break;

			if (start > max) max = start;
			if (dest  > max) max = dest;

			path[start][dest] = YES;
			path[dest][start] = YES;
		}

		find_all_reachable_nodes(end);

		//Start from the node '1'.
		street[0] = 1;
		count[1] = YES;

		//Show the output.
		printf("CASE %d:\n", case_num++);		
		find_path(1, 1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", path_num, end);
	}

	return(0);
}

void initial_state(void)
{
	int i, j;

	//There is no path from any node to any node.
	for(i = 0; i < SIZE; i++)
	{
		//All the nodes haven't been traversed and are not reachable from the 'end'.
		reachable[i] = NO;

		for(j = 0; j < SIZE; j++) path[i][j] = NO;
	}

	//The number of path is 0.
	path_num = 0;	

	return;
}

void find_all_reachable_nodes(int node)
{
	int i, j;

	for(i = 0; i <= max; i++) count[i] = NO;

	tail = 1;
	queue[0] = node;
	count[node] = reachable[node] = YES;
   
	for(i = 0; i < tail; i++)
	{
		for(j = 0; j <= max; j++)
		{
			if (path[queue[i]][j] == YES && count[j] == NO)
			{  				
				queue[tail++] = j;
				count[j] = reachable[j] = YES;
			}
		}
	}

	for(i = 0; i <= max; i++) count[i] = NO;

	return;
}

void find_path(int node, int index)
{
	int i;

	//If the ending node has been reached.
	if (node == end)
	{
		print_path(index);
		return;
	}

	//Traverse the adjacent node of 'node'.
	for(i = 0; i <= max; i++)
	{
		if (path[node][i] == YES && count[i] == NO && reachable[i] == YES)
		{
			street[index] = i;
			count[i] = YES;
			find_path(i, index + 1);
			count[i] = NO;
		}
	}

	return;
}

void print_path(int num)
{
	int i;

	//Print the path.
	for(i = 0; i < num; i++)
	{
		if (i == 0) printf("%d", street[i]);
		else printf(" %d", street[i]);
	}

	printf("\n");

	//Increase the number of paths.
	++path_num;

	return;
}