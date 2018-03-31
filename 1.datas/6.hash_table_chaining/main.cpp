/**
 * @file main.cpp
 * @brief Application entry point
 * @copyright
 *    (C)2018 Baur Krykpayev.
 * @addtogroup main
 * @{
 */

/* =============================================================================
 * Include Files
 * =============================================================================
 */
#include <stdio.h>
#include "HashTable.h"

/* =============================================================================
 * Private Defines
 * =============================================================================
 */

/* =============================================================================
 * Private Macros
 * =============================================================================
 */

/* =============================================================================
 * Private Data Types
 * =============================================================================
 */

/* =============================================================================
 * Public Variables
 * =============================================================================
 */

/* =============================================================================
 * Private Variables
 * =============================================================================
 */

/* =============================================================================
 * Private Function Prototypes (static)
 * =============================================================================
 */


/* =============================================================================
 * Public Constants
 * =============================================================================
 */

/* =============================================================================
 * Private Constants
 * =============================================================================
 */

/* =============================================================================
 * Public Function Definitions
 * =============================================================================
 */

/**
 * @brief application entry point
 */
int main(void)
{
	printf("Let's implement hash table with chaining!!!\n");

	HashTable_Init();
	printf("current capacity: %d\n", HashTable_GetCapacity());
	HashTable_Insert(23, 54);
	HashTable_Insert(12013, 46);
	HashTable_Insert(46, 88);
	HashTable_Insert(47, 88);
	HashTable_Print();
	HashTable_Insert(48, 88);
	HashTable_Insert(49, 88);
	HashTable_Insert(50, 88);
	HashTable_Insert(51, 88);
	HashTable_Insert(52, 88);
	HashTable_Insert(53, 88);
	HashTable_Insert(53, 88);
	HashTable_Insert(12, 88);
	HashTable_Insert(1, 77);
	HashTable_Insert(1293, 88);
	HashTable_Insert(120, 88);
	HashTable_Insert(12312, 88);

	HashTable_Print();

	HashTable_Remove(12312);
	HashTable_Remove(12321);
	HashTable_Remove(22222);

	printf(HashTable_Find(12013) ? "true\n" : "false\n");
	printf(HashTable_Find(11) ? "true\n" : "false\n");
	printf(HashTable_Find(53) ? "true\n" : "false\n");
	HashTable_Print();

	printf("current capacity: %d\n", HashTable_GetCapacity());

	HashTable_Destroy();

	return 0;
}

/* =============================================================================
 * Private Function Definitions
 * =============================================================================
 */

/** @} */
