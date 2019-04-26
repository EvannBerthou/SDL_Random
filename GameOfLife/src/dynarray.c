#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dynarray.h"
void init_array(Dynarray* a, size_t element_size){
	a->count = 0;
	a->capacity = 8;
	a->element_size = element_size;
	a->data = malloc(a->capacity*element_size);
    if (a->data == NULL) exit(0);
}

void array_push(Dynarray* a, void* data){
	if (a->count == a->capacity){
		a->capacity *= 2;
		a->data = realloc(a->data, a->capacity*a->element_size);
        if (a->data == NULL) exit(0);
	}

	memcpy(
		a->data + a->count * a->element_size,
		data,
		a->element_size);
	a->count++;
}

void array_delete_at(Dynarray* a, size_t index){

    if (index >= a->count){
        printf("The given index is greater than the array count (%ld>%ld)\n", index+1, a->count);
        return;
    }

    memmove(
        a->data + index * a->element_size,
        a->data + (index + 1) * a->element_size,
        a->element_size * (a->count - index - 1));
    a->count--;

}
void array_delete_element(Dynarray* a, void* element){
	int index = array_contains(a, element);
	if (index >= 0) array_delete_at(a,(size_t)index);
}

int array_contains(Dynarray* a, void* data){
	for (size_t i = 0; i < a->count; i++){
		if(memcmp(
			(char*)a->data + i * a->element_size,
			(char*)data,
			a->element_size) == 0){
			return (int)i;
		}
	}
    return -1;
}

void free_array(Dynarray* a){
	free(a->data);
	a->count = 0;
}

void* array_data(Dynarray* a){
	return a->data;
}

