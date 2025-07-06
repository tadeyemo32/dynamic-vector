#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t hugeSize = (size_t)1024 * 1024 * 1024 * 1024 * 5ULL; // 5 TB

    printf("Trying to malloc %zu bytes...\n", hugeSize);

    void *ptr = malloc(hugeSize);

    if (ptr == NULL) {
        printf("malloc failed: Not enough memory\n");
    } else {
        printf("malloc succeeded (unexpected!)\n");
        free(ptr);
    }

    return 0;
}
