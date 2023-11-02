#include "binary_trees.h"

/**
 * check_if_ancestor - checks if node 1 is an ancestor of node 2
 * @node1: first node to check (ancestor)
 * @node2: second node to check (child)
 * Return: 1 if node 1 is an ancestor of node 2
 * else 0
 */
int check_if_ancestor(const binary_tree_t *node1, const binary_tree_t *node2)
{
	binary_tree_t *i = node2->parent;

	while (i)
	{
		if (i == node1)
		{
			return (1);
		}

		i = i->parent;
	}
	return (0);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * if no common ancestor was found return NULL
 *
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{

	if (!first || !second)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	if (check_if_ancestor(first, second))
	{
		return ((binary_tree_t *)first);
	}
	if (check_if_ancestor(second, first))
	{
		return ((binary_tree_t *)second);
	}

	if (first->parent)
	{
		return (binary_trees_ancestor(first->parent, second));
	}
	if (second->parent)
	{
		return (binary_trees_ancestor(first, second->parent));
	}

	return (NULL);
}
/*
 *	while (parent1 && parent2)
 *	{
 *		if (parent1 == parent2)
 *			return (parent1);
 *
 *		if (parent1->parent && !check_if_ancestor(parent1, parent2))
 *		{
 *			parent1 = parent1->parent;
 *		}
 *
 *		if (parent2->parent && !check_if_ancestor(parent2, parent1))
 *		{
 *			parent2 = parent2->parent;
 *		}
 *	}
 *	return (NULL);
 */
