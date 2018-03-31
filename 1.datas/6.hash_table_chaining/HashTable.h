/**
 * @file HashTable.h
 * @brief Header for the hash table implementation
 * @copyright
 *    (C)2018 Baur Krykpayev
 * @addtogroup HashTable
 * @{
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

/* =============================================================================
 *                               Include Files
 * =============================================================================
 */

#include "common.h"

/* =============================================================================
 *                             Public Data Types
 * =============================================================================
 */

/* =============================================================================
 *                         Public Defines and Macros
 * =============================================================================
 */

/* =============================================================================
 *                             Public Constants
 * =============================================================================
 */

/* =============================================================================
 *                        Public Function Prototypes
 * =============================================================================
 */

/*
 * @brief Inits the hashtable
 */
void HashTable_Init(void);

/*
 * @brief Destroys hash table
 */
void HashTable_Destroy(void);

/*
 * @brief Inserts key-value pair; updates the value if key already present
 * @param key - key to insert
 * @param value - value to insert
 */
void HashTable_Insert(UINT32 key, INT32 value);

/*
 * @brief Checks if the value exists in hash table
 * @param key - key to find
 */
bool HashTable_Find(INT32 key);

/*
 * @brief Print hash table
 */
void HashTable_Print(void);

/*
 * @brief Return current hash table capacity
 * @return - current capacity
 */
UINT32 HashTable_GetCapacity(void);

/*
 * @brief Removes a key from hash table
 * @param key - key to remove
 */
void HashTable_Remove(UINT32 key);

/** @} */
#endif /* HASHTABLE_H_ */
