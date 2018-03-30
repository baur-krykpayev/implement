//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	BST_NODE* root = NULL;

	root = bst_insertNode(root, 3);
	root = bst_insertNode(root, 1);
	root = bst_insertNode(root, 2);


	bst_printLevelOrder(root);
	bst_printInorder(root);

	root = bst_insertNode(root, 6);
	root = bst_insertNode(root, 4);
	root = bst_insertNode(root, 8);

	printf("\nheight: %d\n", bst_getHeight(root));
	bst_printLevelOrder(root);
	bst_printInorder(root);
	printf("\n");
	printf("root: %d\n", root->data);

	bst_destroy(root);
	root = NULL;

	//printf("root: %d\n", root->data);

	bst_printLevelOrder(root);

	return 0;
}
