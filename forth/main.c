#include <stdio.h>
#include <stdlib.h>
#include "int_stack.h" 
#include <string.h>

int main() {
    int_stack_t stack; // Correctly declare the stack variable
    const int capacity = 20; 

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int_stack_init(&stack, capacity); 

    printf("Enter numbers or operations (+, -, *, /). Type 'exit' to quit.\n");

    while ((read = getline(&line, &len, stdin)) != -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0'; // Remove newline character
        }

        if (strcmp(line, "exit") == 0) {
            break; // Exit loop
        }

    }

    free(line);

    // Add any necessary cleanup for your stack if needed

    return 0; // Correctly end the main function
}


