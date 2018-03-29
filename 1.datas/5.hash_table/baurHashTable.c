#include <stdlib.h>
#include <stdio.h>
#include "baurHashTable.h"

/********************private macros*********************/

/*
 * @brief Prime that is used for hashing
 */
#define HASH_PRIME_1 (191)

/*
 * @brief Prime that is used for hashing
 */
#define HASH_PRIME_2 (271)


/********** private variables *******************/

static KEY_VALUE_PAIR NO_PAIR = { NULL, NULL };

/********** private function prototypes *********/

static KEY_VALUE_PAIR* create_pair(const char* key, const char* val);
static void delete_pair(KEY_VALUE_PAIR* pair);
static int hash(const char* s, const int prime, const int size);
static int get_hash(const char* s, const int size, const int attempt);

/************* public functions  ****************/

BAUR_HASH_TABLE* create_table(int size) 
{
	BAUR_HASH_TABLE* hashTable = (BAUR_HASH_TABLE *)malloc(sizeof(BAUR_HASH_TABLE));
	
	hashTable->size = size;
	hashTable->count = 0;
	hashTable->data = calloc(size, sizeof(KEY_VALUE_PAIR));

	return hashTable;
}

void destroy_table(BAUR_HASH_TABLE* table)
{
	for (int i = 0; i < table->size; i++)
	{
		KEY_VALUE_PAIR* temp = table->data[i];
		if (temp) 
		{
			delete_pair(temp);
		}
	}

	free(table->data);
	free(table);
}

/*
* @brief Print the hash table
*/
void print_table(BAUR_HASH_TABLE* table) 
{

}

/*
* @brief Adds value to the corresponding key,
*	If key does not exist, adds it
*/
void insert(BAUR_HASH_TABLE* table, const char* key, const char* value)
{
	KEY_VALUE_PAIR* pair = create_pair(key, value);
	int hash = get_hash(pair->key, table->size, 0);
	KEY_VALUE_PAIR* cur = table->data[hash];
	int attempt = 1;
	
	// just in case current hash is already occupied
	while (cur && cur != &NO_PAIR) 
	{
		hash = get_hash(pair->key, table->size, attempt);
		cur = table->data[hash];
		attempt++;
	}
	
	table->data[hash] = pair;
	table->count++;
}

/*
 * @brief Checks if the key exists in the hash table
 * @return The value attributed to key if it exists
 */
bool search(BAUR_HASH_TABLE* table, const char* key) 
{
	int hash = get_hash(key, table->size, 0);
	KEY_VALUE_PAIR* cur = table->data[hash];
	int attempt = 1;

	// just in case current hash is already occupied
	while (cur)
	{
		if (cur != &NO_PAIR && !strcmp(cur->key, key))
		{
			return cur->value;
		}

		hash = get_hash(key, table->size, attempt);
		cur = table->data[hash];
		attempt++;
	}

	return NULL;
}


void delete_key(BAUR_HASH_TABLE* table, const char* key) 
{
	int hash = get_hash(key, table->size, 0);
	KEY_VALUE_PAIR* cur = table->data[hash];
	int attempt = 1;

	// just in case current hash is already occupied
	while (cur)
	{
		if (cur != &NO_PAIR && !strcmp(cur->key, key))
		{
			delete_pair(cur);
			table->data[hash] = &NO_PAIR;
		}

		hash = get_hash(key, table->size, attempt);
		cur = table->data[hash];
		attempt++;
	}

	table->size--;
}


/************* private functions ****************/


/*
* @brief Destroy pair that is stored in hash table
*/
static KEY_VALUE_PAIR* create_pair(const char* key, const char* val)
{
	KEY_VALUE_PAIR* pair = malloc(sizeof(KEY_VALUE_PAIR));

	pair->key = key;
	pair->value = val;

	return pair;
}

/*
 * @brief Destroy pair that is stored in hash table
 */
static void delete_pair(KEY_VALUE_PAIR* pair) 
{
	free(pair->key);
	free(pair->value);
	free(pair);
}

/*
* @brief Function to generate hash of the string
* @param s - string of chars to hash
* @param prime - a prime number that is used in hashing
*	this number should be bigger than character set
* @param size - size of the hash table 
*/
static int hash(const char* s, const int prime, const int size)
{
	long hash = 0;
	const int len = strlen(s);
	
	for (int i = 0; i < len; i++) 
	{
		hash += (long)pow(prime, len - (i + 1)*s[i]);
		hash = hash % size;
	}

	return (int)hash;
}

/*
* @brief Function to generate the complex hashing with collission handling
* @details The collision resolution is performed using open addressing with
*	double hashing
* @param s - string of chars to hash
* @param size - size of the hash table
* @param attempt - basically number of collisions
*/
static int get_hash(const char* s, const int size, const int attempt)
{
	const int firstHash = hash(s, HASH_PRIME_1, size);
	const int secondHash = hash(s, HASH_PRIME_2, size);
	return (firstHash + (attempt*(secondHash + 1))) % size;
}