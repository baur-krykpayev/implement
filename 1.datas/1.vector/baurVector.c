#include <stdlib.h>
#include <stdio.h>

#include "baurVector.h"

/* private functions */
static int powerOfTwoCapacity(int capacity);
static void upsize(BAUR_VECTOR* vector);

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
		printf("Resizing to new capacity of %d: \n", new_capacity);
		vector->capacity = new_capacity;
		vector->data = data;
	}
	else 
	{
		printf("Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}
}


