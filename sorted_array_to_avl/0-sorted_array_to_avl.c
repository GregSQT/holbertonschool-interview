#include "binary_trees.h"

/**
 * new_node - creates new node
 * @value: value of new node
 * Return: new node
 */
avl_t *new_node(int value)
{
	avl_t *new = malloc(sizeof(avl_t));

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
/**
 * array_to_tree - recursive function to build tree
 * @array: array to build from
 * @start: start
 * @end: end
 * Return: avl tree
 */
avl_t *array_to_tree(int *array, int start, int end)
{
	avl_t *root = NULL;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	root = new_node(array[mid]);
	if (root == NULL)
		return (NULL);
	root->left = array_to_tree(array, start, mid - 1);
	if (root->left != NULL)
		root->left->parent = root;
	root->right = array_to_tree(array, mid + 1, end);
	if (root->right != NULL)
		root->right->parent = root;
	return (root);
}
/**
 * sorted_array_to_avl - entry point
 * @array: array to build tree from
 * @size: size of array
 * Return: avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = array_to_tree(array, 0, size - 1);

	if (size < 1)
		return (NULL);
	return (root);
}
