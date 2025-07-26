#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> // for size_t

typedef struct ArrayList {
    void *data;         // Pointer to allocated memory for elements
    size_t size;        // Number of elements currently in the vector
    size_t capacity;   
    size_t element_size; 
} ArrayList;

ArrayList *create_vector(size_t element_size, size_t initial_capacity);

void free_vector(ArrayList *vector);

int vector_push(ArrayList *vector, void *element);

int vector_popback(ArrayList *vector, void *out_element);

void *vector_get(ArrayList *vector, size_t index);

int vector_set(ArrayList *vector, size_t index, void *element);

size_t vector_size(ArrayList *vector);

size_t vector_capacity(ArrayList *vector);

#endif // VECTOR_H
