#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include "9-binary_tree_height.c"

/**
 * printCurrentLevel - print all the values in the level
 *					level
 * @root: root of the tree
 * @level: the level to print
 * @func: printing function
 */
void printCurrentLevel(binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		printCurrentLevel(root->left, level - 1, func);
		printCurrentLevel(root->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = binary_tree_height2((binary_tree_t *)tree);
	size_t i;

	if (tree && func)
	{
		for (i = 1; i <= height; i++)
		{
			printCurrentLevel((binary_tree_t *)tree, i, func);
		}
	}
}
