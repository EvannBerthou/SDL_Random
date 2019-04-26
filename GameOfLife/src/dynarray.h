#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stdio.h>

typedef struct Dynarray{

	char* data;
	size_t count;
	size_t capacity;
	size_t element_size;

} Dynarray;

void init_array(Dynarray* a, size_t elemen_size);
void array_push(Dynarray* a, void* data);
void array_delete_at(Dynarray* a, size_t index);
int array_contains(Dynarray* a, void* data);
void free_array(Dynarray* a);
void* array_data(Dynarray* a);


#endif
