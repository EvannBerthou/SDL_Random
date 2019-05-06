#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stdio.h>

typedef struct Dynarray{

    char* data;
    size_t count;
    size_t capacity;
    size_t element_size;
    
}Dynarray;

void init_array(Dynarray* a, size_t element_size);
void array_push(Dynarray* a, void* data);
void array_delete_at(Dynarray* a, size_t index);
void array_delete_element(Dynarray* a, void* element);
int array_coutains(Dynarray* a, void* data);
void free_array(Dynarray*a );
void* array_data(Dynarray* a);
#endif
