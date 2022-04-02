#include <stdio.h>

// create tree
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

// create tree
struct node *create_tree(int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
// leaf counter
int leaf_counter(struct node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return leaf_counter(root->left) + leaf_counter(root->right);
}
int main(int argc, char const *argv[])
{
	struct node *root = create_tree(1);
	root->left = create_tree(2);
	root->right = create_tree(3);
	root->left->left = create_tree(4);
	root->left->right = create_tree(5);
	root->right->left = create_tree(6);
	root->right->right = create_tree(7);
	root->left->left->left = create_tree(8);
	return 0;
}
