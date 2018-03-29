#include <stdio.h>
#include <stdlib.h>
#include "baurHashTable.h"

int main(void)
{
	printf("Baur's hash table implementation!!!\n");
	BAUR_HASH_TABLE* hashTable = create_table(100);

	
	destroy_table(hashTable);

	return EXIT_SUCCESS;
}