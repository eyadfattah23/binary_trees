#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include "11-binary_tree_size.c"

/**
 * power - calculates x ^ y
 * @x: base
 * @y: exponent
 * Return: x to the power of y
 */
size_t power(size_t x, size_t y)
{
	size_t i, result = 1;

	for (i = 0; i < y; i++)
	{
		result *= x;
	}
	return (result);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect or not
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL returns 0, otherwise
 * if the size = 2^height - 1 returns 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree), size = binary_tree_size(tree);

	if (!tree)
		return (0);

	if (size == power(2, height + 1) - 1)
		return (1);
	return (0);
}
