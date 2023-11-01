#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include "15-binary_tree_is_full.c"
#include "14-binary_tree_balance.c"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect or not
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL returns 0, otherwise
 * if the size = 2^height - 1 returns 1
 * of if left-subtree_height = right-subtree_height
 * and all nodes are full and it's balance factor is 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t lheight = binary_tree_height(tree->left);
	size_t rheight = binary_tree_height(tree->right);
	size_t height_check = (lheight == rheight);
	int full_check = binary_tree_is_full(tree);

	if (!tree)
	{
		return (0);
	}
	return (height_check && full_check && (!binary_tree_balance(tree)));
}
