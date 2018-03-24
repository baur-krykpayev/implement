#include <stdlib.h>
#include <stdio.h>

#include "baurVector.h"

/* private functions */
static int powerOfTwoCapacity(int capacity);
static void upsize(BAUR_VECTOR* vector);
static void downsize(BAUR_VECTOR* vector);

/* public functions */

BAUR_VECTOR* bvector_new(int capacity)
{
	int twoPowerCapacity = powerOfTwoCapacity(capacity);

	BAUR_VECTOR* vector = (BAUR_VECTOR*)malloc(sizeof(BAUR_VECTOR));
	
	if (vector == NULL) 
	{
		printf("Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}

	vector->size = 0;
	vector->capacity = twoPowerCapacity;
	vector->data = (int*)malloc(sizeof(int)*twoPowerCapacity);

	if (vector->data == NULL) 
	{
		printf("Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}

	return vector;
}

int bvector_size(BAUR_VECTOR* vector) 
{
	return vector->size;
}

bool bvector_empty(BAUR_VECTOR* vector) 
{
	return (vector->size == 0);
}

void bvector_push_back(BAUR_VECTOR* vector, int elem) 
{
	// check the size of the vector
	if (vector->size == vector->capacity) 
	{
		upsize(vector);
	}

	vector->data[vector->size++] = elem;
}

int bvector_at(BAUR_VECTOR* vector, int pos) 
{
	if (pos < 0 || pos >= vector->size) 
	{
		printf("AT: Trying to access out of bounds");
		exit(EXIT_FAILURE);
	}

	return *(vector->data + pos);
}

/*
* @brief Inserts element at specified position in a given vector
*/
void bvector_insert(BAUR_VECTOR* vector, int pos, int elem) 
{
	if (pos < 0 || pos > vector->size)
	{
		printf("INSERT: Trying to access out of bounds\n");
		exit(EXIT_FAILURE);
	}

	// check the size of the vector
	if (vector->size == vector->capacity)
	{
		upsize(vector);
	}

	// shift by 1
	for (int i = vector->size; i > pos; --i) 
	{
		vector->data[i] = vector->data[i-1];
	}

	vector->data[pos] = elem;
	vector->size++;
}

/*
* @brief Delets element at specified position in a given vector
*/
void bvector_delete(BAUR_VECTOR* vector, int pos) 
{
	if (pos < 0 || pos > vector->size)
	{
		printf("DELETE: Trying to access out of bounds");
		exit(EXIT_FAILURE);
	}

	// shift by 1
	for (int i = pos; i < vector->size-1; i++)
	{
		vector->data[i] = vector->data[i + 1];
	}

	vector->size--;

	if (vector->size < vector->capacity/4) 
	{
		downsize(vector);
	}
}

/*
* @brief Finds first occurence of the element if it is present
*/
int bvector_find(BAUR_VECTOR* vector, int elem) 
{
	int pos = -1;

	for (int i = 0; i < vector->size; i++) 
	{
		if (*(vector->data + i) == elem)
		{
			pos = i;
			break;
		}
	}

	return pos;
}

/*
* @brief Deletes the last element from the vector
*/
void bvector_pop_back(BAUR_VECTOR* vector)
{
	if (vector->size == 0) 
	{
		printf("This bvector is empty!!!");
		exit(EXIT_FAILURE);
	}

	// shift by 1
	vector->size--;

	if (vector->size < vector->capacity / 4)
	{
		downsize(vector);
	}
}


void bvector_print(BAUR_VECTOR* vector) 
{
	if (bvector_empty(vector)) 
	{
		printf("This bvector is empty!!!");
	}
	else 
	{
		for (int i = 0; i < vector->size; i++) 
		{
			printf("%d ", *(vector->data+i));
		}
	}

	printf("\n\n");
}

/************* private functions ****************/

/*
 * @brief returns power of two capacity
 */
static int powerOfTwoCapacity(int capacity) 
{
	int ret = 1;

	while (ret < capacity*2) 
	{
		ret *= 2;
	}

	return ret;
}

/*
* @brief makes vector two times bigger
*/
static void upsize(BAUR_VECTOR* vector) 
{
	// TODO add overflow detection
	int new_capacity = 2 * vector->capacity;

	int* data = realloc(vector->data, sizeof(int)*new_capacity);
	if (data != NULL) 
	{
		printf("UPSIZING: Resizing to new capacity of %d: \n", new_capacity);
		vector->capacity = new_capacity;
		vector->data = data;
	}
	else 
	{
		printf("UPSIZING: Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}
}

/*
* @brief makes vector two times smaller
*/
static void downsize(BAUR_VECTOR* vector)
{
	// TODO add overflow detection
	int new_capacity = vector->capacity/2;

	int* data = realloc(vector->data, sizeof(int)*new_capacity);
	if (data != NULL)
	{
		printf("DOWNSIZING: Resizing to new capacity of %d: \n", new_capacity);
		vector->capacity = new_capacity;
		vector->data = data;
	}
	else
	{
		printf("DOWNSIZING: Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}
}


