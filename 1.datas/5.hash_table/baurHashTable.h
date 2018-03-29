/*
* @file baurHashTable.h
* @brief This module creates my own hash table implementation.
*/

#ifndef BAUR_HASH_TABLE_H_
#define BAUR_HASH_TABLE_H_

#include <stdbool.h>

/* Public data*/

/*
 * @brief Key Value Pair struct
 */
typedef struct 
{
	char* key;
	char* value;
} KEY_VALUE_PAIR;

/*
 * @brief Hash Table struct
 */
typedef struct
{
	int size;
	int count;
	KEY_VALUE_PAIR** data;
} BAUR_HASH_TABLE;


/* Public functions */

/*
 * @brief Create the hash table
 */
BAUR_HASH_TABLE* create_table(int size);

/*
 * @brief Destroy the hash table
 */
void destroy_table(BAUR_HASH_TABLE* table);

/*
 * @brief Print the hash table
 */
void print_table(BAUR_HASH_TABLE* table);

/*
 * @brief Adds value to the corresponding key,
 *	If key does not exist, adds it	
 */
void insert(BAUR_HASH_TABLE* table, const char* key, const char* value);

/*
 * @brief Checks if the key exists in the hash table
 */
bool search(BAUR_HASH_TABLE* table, const char* key);

/*
* @brief Delete the value associated with the key
*/
void delete_key(BAUR_HASH_TABLE* table, const char* key);

#endif /* !BAUR_HASH_TABLE_H_ */