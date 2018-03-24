/*
 * @file baurVector.h
 * @brief This module creates my own vector implementation.
 *	Basically, this module will support resizing array
 */

#ifndef BAURVECTOR_H_
#define BAURVECTOR_H_

#include <stdbool.h>

/* Public data*/
typedef struct
{
	// size always points on empty space
	int size;
	int capacity;
	int *data;
} BAUR_VECTOR;


/* Public functions */

/*
 * @brief Create the vector
 * @return returns pointer to baur vectore
 */

BAUR_VECTOR* bvector_new(int capacity);



 /*
 * @brief Return the size of the vector
 * @return Size of the vector
 */
int bvector_size(BAUR_VECTOR* vector);

/*
* @brief Check if vector is empty
* @return true if empty, false if not
*/
bool bvector_empty(BAUR_VECTOR* vector);

 /*
 * @brief Push element at the vector back
 */
void bvector_push_back(BAUR_VECTOR* vector, int elem);

/*
 * @brief returns element at specified position
 */
int bvector_at(BAUR_VECTOR* vector, int pos);

/*
 * @brief Inserts element at specified position in a given vector
 */
void bvector_insert(BAUR_VECTOR* vector, int pos, int elem);

/*
 * @brief Delets element at specified position in a given vector
 */
void bvector_delete(BAUR_VECTOR* vector, int pos);

/*
* @brief Finds first occurence of the elemnt
*/
int bvector_find(BAUR_VECTOR* vector, int elem);

/*
* @brief Deletes the last element from the vector
*/
void bvector_pop_back(BAUR_VECTOR* vector);


/*
* @brief Prints all elements in the vector
*/
void bvector_print(BAUR_VECTOR* vector);


#endif /* !BAURVECTOR_H_ */