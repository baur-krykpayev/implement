#include <stdio.h>
#include <stdlib.h>
#include "baurLinkedList.h"

int main(void)
{
	printf("Baur's Linked List implementation!!!\n");

	BLL_NODE* root1 = bll_create_root_node(12);
	bll_print_list(root1);
	printf("The size of the LL: %d\n", bll_size(root1));

	bll_push_back(root1, -2);
	bll_push_back(root1, 111);
	bll_push_back(root1, 4);
	bll_print_list(root1);
	printf("The size of the LL: %d\n", bll_size(root1));

	bll_push_front(&root1, 55);
	bll_push_front(&root1, 77);
	bll_push_front(&root1, 8);
	bll_print_list(root1);
	printf("The size of the LL: %d\n", bll_size(root1));

	bll_pop_back(&root1);
	bll_pop_back(&root1);
	bll_print_list(root1);
	printf("The size of the LL: %d\n", bll_size(root1));

	bll_pop_front(&root1);
	bll_print_list(root1);
	printf("The size of the LL: %d\n", bll_size(root1));

	bll_insert(&root1,0,2000);
	bll_insert(&root1, 3, 13);
	bll_insert(&root1, 6, 33);
	bll_print_list(root1);
	printf("The size of the LL: %d\n", bll_size(root1));



	return EXIT_SUCCESS;
}