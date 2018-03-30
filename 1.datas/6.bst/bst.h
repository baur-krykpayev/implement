/**
 * @file bst.h
 * @brief Header for custom binary search tree implementation
 * @copyright
 *    (C)2017 Baur Krykpayev.
 *
 * @addtogroup BinarySearchTree
 * @{
 */

#ifndef BST_H_
#define BST_H_

/*
 * @brief BST node struct
 */
typedef struct BST_NODE
{
	int data;
	struct BST_NODE* left;
	struct BST_NODE* right;
}BST_NODE;

/*
 * @brief inserts node into the tree
 */
BST_NODE* bst_insertNode(BST_NODE* root, int value);

/*
 * @brief Returns height of the tree
 */
int bst_getHeight(BST_NODE* root);

/*
 * @brief prints level order traversal of the tree
 */
void bst_printLevelOrder(BST_NODE* root);

/*
 * @brief prints in order traversal of the tree
 */
void bst_printInorder(BST_NODE* root);

/*
 * @brief destroys the bst and frees up the memory
 */
void bst_destroy(BST_NODE* root);


#endif /* BST_H_ */
