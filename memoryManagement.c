#include <stdio.h>
#include <stdlib.h>

int global_1;
int global_2;
int global_3;

int function(int n){
    if(n == 4)
        return 0;
    int stack_n = n;
    printf("Address of stack_%d: %p\n", n, (void*)&stack_n);
    function(n+1);
}

int main () {
    printf("Address of global_1: %p\n", (void*)&global_1);
    printf("Address of global_2: %p\n", (void*)&global_2);
    printf("Address of global_3: %p\n\n", (void*)&global_3);

    function(1);

    int *heap_1 = (int*)malloc(sizeof(int));
    int *heap_2 = (int*)malloc(sizeof(int));
    int *heap_3 = (int*)malloc(sizeof(int));

    printf("\nAddress of heap_1: %p\n", (void*)heap_1);
    printf("Address of heap_2: %p\n", (void*)heap_2);
    printf("Address of heap_3: %p\n", (void*)heap_3);

    free(heap_1);
    free(heap_2);
    free(heap_3);

    return 0;
    
}
