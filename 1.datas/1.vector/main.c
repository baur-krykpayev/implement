#include <stdio.h>
#include "baurVector.h"

void main() 
{
	printf("Baur's Vector implementation!!!\n");
	BAUR_VECTOR* vector = bvector_new(2);

	printf("Vector capacity: %d\n", vector->capacity);
	printf("Vector size: %d\n", bvector_size(vector));

	bvector_print(vector);

	bvector_push_back(vector, 2);

	bvector_push_back(vector, 3);
	bvector_push_back(vector, 4);

	bvector_print(vector);

	bvector_push_back(vector, 2);

	bvector_push_back(vector, 3);
	bvector_push_back(vector, 4);

	bvector_print(vector);
	int last = bvector_size(vector) - 1;
	printf("Vector elem at pos: %d is %d\n", last, bvector_at(vector, last));
	printf("Vector size: %d\n", bvector_size(vector));


	BAUR_VECTOR* vector2 = bvector_new(0);

	bvector_push_back(vector2, 0);
	bvector_push_back(vector2, 1);
	bvector_push_back(vector2, 2);
	bvector_push_back(vector2, 4);
	bvector_print(vector2);
	
	bvector_insert(vector2, 3, 3);
	bvector_print(vector2);

	bvector_insert(vector2, 5, 5);
	bvector_print(vector2);
	printf("here\n");
	bvector_insert(vector2, 0, -1);
	bvector_print(vector2);

	bvector_delete(vector2, 0);
	bvector_delete(vector2, 5);
	bvector_delete(vector2, 0);
	bvector_delete(vector2, 0);

	bvector_delete(vector2, 0);
	bvector_delete(vector2, 0);
	bvector_print(vector2);

	bvector_push_back(vector2, 0);
	bvector_push_back(vector2, 1);
	bvector_push_back(vector2, 2);
	bvector_push_back(vector2, 4);
	
	int elem = bvector_at(vector2, 3);


	printf("Pos of elem %d is %d\n", elem, bvector_find(vector2, elem));

	printf("Pos of elem 101 is %d\n", bvector_find(vector2, 101));
	
	bvector_print(vector2);
	bvector_pop_back(vector2);
	bvector_pop_back(vector2);
	bvector_print(vector2);
}