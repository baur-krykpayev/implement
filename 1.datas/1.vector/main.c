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

	bvector_push_back(vector, 2);

	bvector_push_back(vector, 3);
	bvector_push_back(vector, 4);

	bvector_push_back(vector, 2);

	bvector_push_back(vector, 3);
	bvector_push_back(vector, 4);

	bvector_print(vector);

	printf("Vector size: %d\n", bvector_size(vector));

	bvector_push_back(vector, -2);

	bvector_push_back(vector, -3);
	bvector_push_back(vector, -4);

	bvector_push_back(vector, -2);

	bvector_push_back(vector, -3);
	bvector_push_back(vector, -4);

	bvector_print(vector);

	printf("Vector size: %d\n", bvector_size(vector));
}