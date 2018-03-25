#include <stdlib.h>
#include <stdio.h>

#include "baurLinkedList.h"

/* private functions prototypes*/

static BLL_NODE* create_node(int val);


/* public functions */

/*
* @brief Creates and returns linked list node
*/
BLL_NODE * bll_create_root_node(int val) 
{
	return create_node(val);
}

/*
* @brief Prints out linked list
*/
void bll_print_list(BLL_NODE* root) 
{
	while (root) 
	{
		printf( "%d ", root->val);
		root = root->next;
	}
	printf("\n");
}

/*
* @brief Returns size of the linked list
*/
int bll_size(BLL_NODE* root) 
{
	int size = 0;

	while (root)
	{
		size++;
		root = root->next;
	}

	return size;
}

/*
* @brief Checks if the linked list is empty
*/
bool bll_empty(BLL_NODE* root) 
{
	return (root == NULL);
}

/*
* @brief Push new element in front of the list
*/
void bll_push_front(BLL_NODE** root, int val) 
{
	BLL_NODE* temp = create_node(val);
	temp->next = *root;
	*root = temp;
}

/*
* @brief Push new element in the back
*/
void bll_push_back(BLL_NODE* root, int val) 
{
	BLL_NODE* temp = create_node(val);
	
	BLL_NODE* cur = root;
	while (cur->next) 
	{
		cur = cur->next;
	}

	cur->next = temp;
}

/*
* @brief Pop from front
*/
void bll_pop_front(BLL_NODE** root) 
{
	if (*root == NULL)
	{
		printf("Linked List is already empty!!!\n");
		return;
	}

	BLL_NODE* cur = *root;
	*root = cur->next;
	free(cur);
}

/*
* @brief Pop from back
*/
void bll_pop_back(BLL_NODE** root) 
{
	if (*root == NULL) 
	{
		printf("Linked List is already empty!!!\n");
		return;
	}

	BLL_NODE* cur = *root;
	BLL_NODE* prev = NULL;
	
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	
	if (prev) 
	{
		prev->next = NULL;
	}
	else 
	{
		*root = NULL;
	}

	free(cur);
}

/*
* @brief Insert an element at specified position
*/
void bll_insert(BLL_NODE** root, int index, int val) 
{
	if (index > bll_size(*root)) 
	{
		printf("Can't insert because index is greater than size\n");
	}

	BLL_NODE* temp = create_node(val);
	
	// handle the root case
	if (index == 0) 
	{
		temp->next = *root;
		*root = temp;
		return;
	}

	BLL_NODE* cur = *root;
	BLL_NODE* prev = NULL;

	while (index) 
	{
		prev = cur;
		cur = cur->next;
		index--;
	}

	prev->next = temp;
	temp->next = cur;
}

/*
* @brief Delete the element at specified position
*/
void bll_erase(BLL_NODE** root, int index) 
{

}

/*
* @brief Reverse linked list
*/
void bll_reverse(BLL_NODE** root);

/*
* @brief Destroys existing linked list
*/
void bll_destroy(BLL_NODE** root);


/*****************private functions ****************/
static BLL_NODE* create_node(int val) 
{
	BLL_NODE *ret = (BLL_NODE *)malloc(sizeof(BLL_NODE));
	ret->val = val;
	ret->next = NULL;

	return ret;
}