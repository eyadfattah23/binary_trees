#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (tree->left || tree->right)
	{
		if (binary_tree_height(tree->left) >= binary_tree_height(tree->right))
		{
			return (1 + binary_tree_height(tree->left));
		}
		else
		{
			return (binary_tree_height(tree->right) + 1);
		}
	}

	return (0);
}
