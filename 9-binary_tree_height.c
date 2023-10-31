#include "binary_trees.h"

/**
 * @binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (-1);
	}
	if (1 + binary_tree_height(tree->left) >= binary_tree_height(tree->right) + 1)
	{
		/* code */
		if (tree->left)
		{
			return (1 + binary_tree_height(tree->left));
		}
		return (0);
	}
	if (tree->right)
		return (binary_tree_height(tree->right) + 1);
	return (0);
}
