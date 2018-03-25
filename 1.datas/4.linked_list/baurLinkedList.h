
/*
* @file baurLinkedList.h
* @brief This module creates my own linked list implementation.
*/

#ifndef BAURLINKEDLIST_H_
#define BAURLINKEDLIST_H_

#include <stdbool.h>

/* Public data*/

typedef struct Node 
{
	int val;
	struct Node* next;
} BLL_NODE;


/* Public functions */

/*
 * @brief Creates and returns linked list node
 */
BLL_NODE* bll_create_root_node(int val);

/*
 * @brief Prints out linked list
 */
void bll_print_list(BLL_NODE* root);

/*
 * @brief Returns size of the linked list
 */
int bll_size(BLL_NODE* root);

/*
* @brief Checks if the linked list is empty
*/
bool bll_empty(BLL_NODE* root);

/*
 * @brief Push new element in front of the list
 */
void bll_push_front(BLL_NODE** root, int val);

/*
* @brief Push new element in the back
*/
void bll_push_back(BLL_NODE* root, int val);

/*
 * @brief Pop from front
 */
void bll_pop_front(BLL_NODE** root);

/*
 * @brief Pop from back
 */
void bll_pop_back(BLL_NODE** root);

/*
 * @brief Insert an element at specified position
 */
void bll_insert(BLL_NODE** root, int index, int val);

/*
* @brief Delete the element at specified position
*/
void bll_erase(BLL_NODE** root, int index);

/*
* @brief Reverse linked list
*/
void bll_reverse(BLL_NODE** root);

/*
* @brief Destroys existing linked list
*/
void bll_destroy(BLL_NODE** root);

#endif /* !BAURLINKEDLIST_H_ */