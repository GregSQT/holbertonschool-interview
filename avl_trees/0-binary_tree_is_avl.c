#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * check_avl - Recursively checks if a tree is an AVL tree.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum allowed value for node.
 * @max: Maximum allowed value for node.
 * @height: Pointer to store the height of the current node.
 *
 * Return: 1 if tree is AVL, otherwise 0.
 */
int check_avl(const binary_tree_t *tree, int min, int max, int *height)
{
    int left_height = 0, right_height = 0;
    int left_avl, right_avl;
    
    if (!tree)
    {
        *height = 0;
        return (1);
    }
    
    if (tree->n <= min || tree->n >= max)
        return (0);
    
    left_avl = check_avl(tree->left, min, tree->n, &left_height);
    right_avl = check_avl(tree->right, tree->n, max, &right_height);
    
    *height = (left_height > right_height ? left_height : right_height) + 1;
    
    if (!left_avl || !right_avl)
        return (0);
    
    if (abs(left_height - right_height) > 1)
        return (0);
    
    return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height = 0;
    
    if (!tree)
        return (0);
    
    return (check_avl(tree, INT_MIN, INT_MAX, &height));
}
