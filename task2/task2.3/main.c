#include <stdio.h>

int global_var = 10;

void increase_stack() {
    int large_array[1000]; 
    printf("Address of large array in stack: %p\n", (void*)large_array);
}

int main() {
    int i;  

 
    printf("The stack top is near %p\n", (void*)&i);
    
    printf("Global variable address (data segment): %p\n", (void*)&global_var);

    printf("Function address (text segment): %p\n", (void*)increase_stack);

    increase_stack();

    return 0;
}