/**
 * @file bst.cpp
 * @brief Implements the custom binary search tree.
 * @copyright
 *    (C)2017 Baur Krykpayev.
 * @addtogroup AdaptiveSwitchLoadDriver
 * @{
 */

#include "bst.h"
#include "stdlib.h"
#include "stdio.h"

/***** static function prototypes*******/
static BST_NODE* bst_newNode(int value);
static void bst_printLevel(BST_NODE* root, int level);

/*****public functions*******/

BST_NODE* bst_insertNode(BST_NODE* root, int value)
{
	if (root == NULL)
	{
		root = bst_newNode(value);
		return root;
	}

	if (value < root->data)
	{
		root->left = bst_insertNode(root->left, value);
	}
	else
	{
		root->right = bst_insertNode(root->right, value);
	}

	return root;
}

int bst_getHeight(BST_NODE* root)
{
    if (root == NULL)
    {
    	return 0;
    }

    /* compute the height of each subtree */
    int l = bst_getHeight(root->left);
    int r = bst_getHeight(root->right);

    return (l > r) ? l+1 : r+1;
}

void bst_printLevelOrder(BST_NODE* root)
{
	if (root == NULL)
	{
		printf("tree is empty\n");
		return;
	}

	int h = bst_getHeight(root);
	for (int i=1; i<=h; i++)
	{
		bst_printLevel(root, i);
	}
	printf("\n");
}

void bst_printInorder(BST_NODE* root)
{
	if (root == NULL)
	{
	return;
	}

	if (root->left != NULL)
	{
		bst_printInorder(root->left);
	}
	printf("%d ", root->data);

	if (root->right != NULL)
	{
		bst_printInorder(root->right);
	}
}

void bst_destroy(BST_NODE* root)
{
	if (root == NULL)
	{
		return;
	}


	bst_destroy(root->left);
	bst_destroy(root->right);

	free(root);
}


/*****private function*******/

/*
 * @brief returns new binary search tree node
 */
static BST_NODE* bst_newNode(int value)
{
	BST_NODE* newNode = (BST_NODE*)malloc(sizeof(BST_NODE));
	newNode->data = value;
	newNode->left =  NULL;
	newNode->right =  NULL;

	return newNode;
}

/*
 * @brief prints given bst level
 */
static void bst_printLevel(BST_NODE* root, int level)
{
    if (root == NULL)
    {
    	return;
    }

    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
    	bst_printLevel(root->left, level-1);
    	bst_printLevel(root->right, level-1);
    }
}
