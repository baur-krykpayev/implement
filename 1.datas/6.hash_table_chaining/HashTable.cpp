/**
 * @file HashTable.cpp
 * @brief Implements the hash table with chaining
 * @copyright
 *    (C)2018 Baur Krykpayev
 * @addtogroup HashTable
 * @{
 */

/* =============================================================================
 * Include Files
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include "HashTable.h"

/* =============================================================================
 * Private Defines
 * =============================================================================
 */
/**
 * @brief Defines initial max capacity of the hash table
 */
#define INIT_MAX_CAPACITY (UINT32)(16)

/* =============================================================================
 * Private Macros
 * =============================================================================
 */

/* =============================================================================
 * Private Data Types
 * =============================================================================
 */

/**
 * @brief Linked list item
 * @details this is the member of linked list
 */
typedef struct node
{
	/** @brief key of the node */
	UINT32 key;
	/** @brief value of the node */
	INT32 value;
	/** @brief pointer to the next node */
	struct node* next;
} HASH_NODE;

/**
 * @brief Linked list implementation
 * @details All link list nodes share a key
 */
typedef struct
{
	/* @brief head pointing the first element of Linked List
	 * at an index of Hash Table */
	HASH_NODE* head;

	/* @brief tail pointing the last element of Linked List
	 * at an index of Hash Table */
	HASH_NODE* tail;
} HASH_LIST;

/*
 * @brief Hash Table struct
 */
typedef struct
{
	/** @brief number of buckets occupied in the table now */
	UINT32 size;
	/** @brief max bucket capacity of the hash table */
	UINT32 capacity;
	HASH_LIST* list;
} HASH_TABLE;

/* =============================================================================
 * Public Variables
 * =============================================================================
 */

/* =============================================================================
 * Private Variables
 * =============================================================================
 */

static HASH_TABLE hashTable;

/* =============================================================================
 * Private Function Prototypes (static)
 * =============================================================================
 */

static HASH_NODE* createHashNode(UINT32 key, INT32 value);
static UINT32 hash(UINT32 key);
static INT32 findInList(HASH_NODE* root, UINT32 key);
static HASH_NODE* getNode(HASH_NODE* root, UINT32 pos);
static void tableRehash(void);

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

void HashTable_Init(void)
{
	hashTable.list = (HASH_LIST*)malloc((INIT_MAX_CAPACITY)*sizeof(HASH_NODE));
	hashTable.capacity = INIT_MAX_CAPACITY;
	hashTable.size = 0;

	for (UINT8 i = 0; i < hashTable.capacity; i++)
    {
		hashTable.list[i].head = NULL;
		hashTable.list[i].tail = NULL;
	}
}

void HashTable_Destroy(void)
{
	for (UINT32 i = 0; i < hashTable.capacity; i++)
	{
		HASH_NODE* cur = hashTable.list[i].head;
		while(cur)
		{
			HASH_NODE* temp = cur->next;
			free(cur);
			cur = temp;
		}
	}

	free(hashTable.list);
}

void HashTable_Insert(UINT32 key, INT32 value)
{
	UINT32 index = hash(key) % hashTable.capacity;
	printf("index: %d\n", index);
	HASH_NODE* root = hashTable.list[index].head;
	HASH_NODE* hashNode = createHashNode(key, value);

	if(!root)
	{

		printf("inserting new!!\n");
		hashTable.list[index].head = hashNode;
		hashTable.list[index].tail = hashNode;
		hashTable.size++;
	}
	else
	{
		if (findInList(root, key) == -1)
		{
			// key does not exist - append
			hashTable.list[index].tail->next = hashNode;
			hashTable.list[index].tail = hashNode;
			hashTable.size++;
		}
		else
		{
			HASH_NODE* updateNode = getNode(root, index);
			updateNode->value = value;
			free(hashNode);
		}
	}

	UINT32 load = (100*hashTable.size)/hashTable.capacity;

	if (load >= 75)
	{
		printf("INCREASING TABLE SIZE AND REHASHING!!!\n");
		tableRehash();
	}
}


bool HashTable_Find(INT32 key)
{
	UINT32 index = hash(key) % hashTable.capacity;
	bool exists = false;
	HASH_NODE* root = hashTable.list[index].head;

	if(!root)
	{
		exists = false;
	}
	else
	{
		exists = (findInList(root, key) == -1) ? false : true;
	}

	return exists;
}

void HashTable_Print(void)
{
	for(UINT32 i = 0; i < hashTable.capacity; i++)
	{
		if (hashTable.list[i].head != NULL)
		{
			printf("%d: ", i);

			HASH_NODE* cur = hashTable.list[i].head;

			while(cur)
			{
				printf(" [%d, %d] ", cur->key, cur->value);
				cur = cur->next;
			}
			printf("\n");
		}
	}
}

UINT32 HashTable_GetCapacity()
{
	return hashTable.capacity;
}

void HashTable_Remove(UINT32 key)
{
	UINT32 index = hash(key) % hashTable.capacity;
	HASH_NODE* root = hashTable.list[index].head;

	if (!root)
	{
		printf("REMOVE: No such key!!!\n");
	}
	else
	{
		HASH_NODE* cur = root;
		HASH_NODE* remove = NULL;

		// this is case when key is at the root of linked list
		if (cur->key == key)
		{
			hashTable.list[index].head = cur->next;
			remove = cur->next;
		}
		else
		{
			// move the right position
			while (cur->next->key != key)
			{
				cur = cur->next;
			}

			// handle the tail case
			if (hashTable.list[index].tail == cur->next)
			{
				cur->next = NULL;
				remove = hashTable.list[index].tail;
				hashTable.list[index].tail = cur;

			}
			else
			{
				remove = cur->next;
				cur->next = cur->next->next;
			}
		}

		// don't forget about memory
		free(remove);
		printf("REMOVE: Key was removed!!!\n");
	}
}

/* =============================================================================
 * Private Function Definitions
 * =============================================================================
 */

/*
 * @brief creates new hash node
 * @param key - key
 * @param value - value
 * @return - returns hash node in the hash table
 */
static HASH_NODE* createHashNode(UINT32 key, INT32 value)
{
	HASH_NODE* hashNode = (HASH_NODE*)malloc(sizeof(HASH_NODE));

	hashNode->key = key;
	hashNode->value = value;
	hashNode->next = NULL;

	return hashNode;
}

/*
 * @brief this is the hashing function
 * @details the return needs to be divided by the number of buckets
 * @details accepts only
 * @param key - key to hash
 * @return - returns hash value
 */
static UINT32 hash(UINT32 key)
{
	key = ((key >> 16) ^ key) * 0x45d9f3b;
	key = ((key >> 16) ^ key) * 0x45d9f3b;
	key = (key >> 16) ^ key;
	return key;
}

/*
 * @brief Finds the value in the linked list
 * @param root - root of the linked list
 * @param key - key to find
 * @return - position if key is found; -1 otherwise
 */
static INT32 findInList(HASH_NODE* root, UINT32 key)
{
	HASH_NODE* cur = root;
	INT32 pos = 0;

	while(cur)
	{
		if (cur->key == key)
		{
			return pos;
		}
		pos++;
		cur = cur->next;
	}

	return -1;
}

/*
 * @brief Get the linked list node
 * @param root - root of the linked list
 * @param pos - position at which node is located
 * @return - hash node
 */
static HASH_NODE* getNode(HASH_NODE* root, UINT32 pos)
{
	HASH_NODE* cur = root;

	for(UINT32 i = 0; i < pos; i++)
	{
		cur = cur->next;
	}

	return cur;
}

/*
 * @brief increasing the size of the hash table and rehashing it
 */
static void tableRehash(void)
{
	HASH_LIST* tempList = hashTable.list;
	hashTable.size = 0;
	hashTable.capacity *= 2;

	hashTable.list = (HASH_LIST*)malloc(hashTable.capacity*sizeof(HASH_NODE));

	for (UINT32 i = 0; i < hashTable.capacity; i++)
    {
		hashTable.list[i].head = NULL;
		hashTable.list[i].tail = NULL;
	}

	// populating the hash table back
	for (UINT32 i = 0; i < hashTable.capacity/2; i++)
	{
		HASH_NODE* cur = tempList[i].head;

		while(cur)
		{
			HashTable_Insert(cur->key, cur->value);
			cur = cur->next;
		}
	}

	// destroy temp
	for (UINT32 i = 0; i < hashTable.capacity/2; i++)
	{
		HASH_NODE* cur = tempList[i].head;
		while(cur)
		{
			HASH_NODE* tempNode = cur->next;
			free(cur);
			cur = tempNode;
		}
	}
	free(tempList);
}

/** @} */

