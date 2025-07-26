#include "vector.h"
#include <stdio.h>
#include <string.h>

int main() {
    // Example 1: Using vector with integers
    printf("=== Integer Vector Example ===\n");
    ArrayList *int_vec = create_vector(sizeof(int), 2);
    
    // Push some integers
    int nums[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        vector_push(int_vec, &nums[i]);
        printf("Pushed: %d, Size: %zu, Capacity: %zu\n", 
               nums[i], int_vec->size, int_vec->capacity);
    }
    
    // Pop and print
    int popped_int;
    while (int_vec->size > 0) {
        vector_popback(int_vec, &popped_int);
        printf("Popped: %d, Remaining size: %zu\n", popped_int, int_vec->size);
    }
    
    free_vector(int_vec);
    printf("\n");
    
    // Example 2: Using vector with strings
    printf("=== String Vector Example ===\n");
    ArrayList *str_vec = create_vector(sizeof(char*), 3);
    
    // Note: We store pointers to strings (char*)
    char* names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    for (int i = 0; i < 5; i++) {
        vector_push(str_vec, &names[i]);
        printf("Pushed: %s, Size: %zu, Capacity: %zu\n", 
               names[i], str_vec->size, str_vec->capacity);
    }
    
    // Pop and print
    char* popped_str;
    while (str_vec->size > 0) {
        vector_popback(str_vec, &popped_str);
        printf("Popped: %s, Remaining size: %zu\n", popped_str, str_vec->size);
    }
    
    free_vector(str_vec);
    printf("\n");
    
    // Example 3: Using vector with custom struct
    printf("=== Struct Vector Example ===\n");
    typedef struct {
        int id;
        char name[20];
        float score;
    } Student;
    
    ArrayList *student_vec = create_vector(sizeof(Student), 2);
    
    Student students[] = {
        {1, "John", 85.5},
        {2, "Jane", 92.0},
        {3, "Mike", 78.5}
    };
    
    for (int i = 0; i < 3; i++) {
        vector_push(student_vec, &students[i]);
        printf("Pushed: %d %s %.1f, Size: %zu\n", 
               students[i].id, students[i].name, students[i].score, 
               student_vec->size);
    }
    
    // Pop and print
    Student popped_student;
    while (student_vec->size > 0) {
        vector_popback(student_vec, &popped_student);
        printf("Popped: %d %s %.1f, Remaining size: %zu\n", 
               popped_student.id, popped_student.name, popped_student.score,
               student_vec->size);
    }
    
    free_vector(student_vec);
    
    return 0;
}