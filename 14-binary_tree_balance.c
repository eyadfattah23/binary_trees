#include "binary_trees.h"
/**
 * binary_tree_height2 - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of a binary tree
 */
int binary_tree_height2(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (binary_tree_height2(tree->left) >= binary_tree_height2(tree->right))
	{
		return (1 + binary_tree_height2(tree->left));
	}
	else
	{
		return (binary_tree_height2(tree->right) + 1);
	}

	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of a binary tree or If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (binary_tree_height2(tree->left) - binary_tree_height2(tree->right));
}
