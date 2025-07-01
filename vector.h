#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> // for size_t

typedef struct ArrayList {
    void *data;         // Pointer to allocated memory for elements
    size_t size;        // Number of elements currently in the vector
    size_t capacity;    // Allocated capacity (in number of elements)
    size_t element_size; // Size of each element (e.g., sizeof(int))
} ArrayList;

// Creates a new vector with given element size and initial capacity
ArrayList *create_vector(size_t element_size, size_t initial_capacity);

// Frees memory used by the vector
void free_vector(ArrayList *vector);

// Adds an element to the end of the vector
int vector_push(ArrayList *vector, void *element);

// Removes the last element from the vector
int vector_pop(ArrayList *vector, void *out_element);

// Gets a pointer to the element at the given index
void *vector_get(ArrayList *vector, size_t index);

// Sets the element at a given index
int vector_set(ArrayList *vector, size_t index, void *element);

// Returns the current size
size_t vector_size(ArrayList *vector);

// Returns the current capacity
size_t vector_capacity(ArrayList *vector);

#endif // VECTOR_H
