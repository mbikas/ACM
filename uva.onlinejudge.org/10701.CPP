#define SIZE 53

#include<stdio.h>

char preorder[SIZE], inorder[SIZE], postorder[SIZE];
int  length, post_index;

void find_children(int lower, int upper, int pre_index);
int  index_of_root_in_inorder(int lower, int upper, int root);

int main(void)
{
	int test_case;

	scanf(" %d", &test_case);
	
	while(test_case--)
	{
		scanf(" %d %s %s", &length, preorder, inorder);
		
		postorder[length] = NULL;
		post_index = length - 1;
		find_children(0, length - 1, 0);
		
		printf("%s\n", postorder);
	}

	return(0);
}

void find_children(int lower, int upper, int pre_index)
{
	int in_index;

	postorder[post_index--] = preorder[pre_index];

	//Determine the index of the root 'pre_index' from the inorder traversal in the
	//closed interval ['lower', 'upper'].
	in_index = index_of_root_in_inorder(lower, upper, pre_index);

	//If there are right children.
	if (upper - in_index > 0) find_children(in_index + 1, upper, pre_index + (in_index - lower) + 1);

	//If there are left children.
	if (in_index - lower > 0) find_children(lower, in_index - 1, pre_index + 1);

	return;
}

int index_of_root_in_inorder(int lower, int upper, int root)
{
	int i;

   //As the interval is closed ['lower', 'upper'].
	for(i = lower; i <= upper; i++)
	{
		if (preorder[root] == inorder[i]) break;
	}

   return(i);
}
