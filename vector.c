#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



ArrayList *create_vector(size_t element_size, size_t initial_capacity) {
    if (element_size == 0 || initial_capacity == 0) {
        printf("Element size and initial capacity must be greater than zero.\n");
        return NULL;
    }

    // Allocate memory for the ArrayList struct
    ArrayList *vector = (ArrayList *)malloc(sizeof(ArrayList));
    if (!vector) {
        printf("Memory allocation failed for vector structure.\n");
        return NULL;
    }

    // Allocate memory for the internal data array
    vector->data = malloc(element_size * initial_capacity);
    if (!vector->data) {
        printf("Memory allocation failed for data array.\n");
        free(vector);
        return NULL;
    }

    // Initialize fields
    vector->size = 0;
    vector->capacity = initial_capacity;
    vector->element_size = element_size;

    return vector;
}
void free_vector(ArrayList *vector){

    if (vector) {
        free(vector->data); // Free the internal data array
        free(vector);       // Free the ArrayList structure itself
    }

}

int vector_push(ArrayList *vector, void *element) {
    if (!vector || !element) {
        printf("Invalid vector or element.\n");
        return -1;
    }

    if (vector->size == vector->capacity) {
        size_t new_capacity = vector->capacity * 2;
        void *new_data = realloc(vector->data, new_capacity * vector->element_size);
        if (!new_data) {
            printf("Failed to allocate memory during resize.\n");
            return -1;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    void *dest = (char *)vector->data + (vector->size * vector->element_size);

    memcpy(dest, element, vector->element_size);

    vector->size++;

    return 0;  
}





