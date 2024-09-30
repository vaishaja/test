#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processInput(char *input) {
    char buffer[10];

    // 1. Buffer overflow vulnerability
    strcpy(buffer, input);  // Unsafe copy, no bounds checking

    // 2. Potential null pointer dereference
    if (input) {
        printf("Input: %s\n", input);
    }

    // 3. Improper error handling
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        // Missing error handling here
        printf("Failed to open file\n");
        return; // Should handle cleanup
    }

    // Read file (not actually implemented)
    fclose(file);
}

int main() {
    char *userInput = NULL;

    // 4. Memory leak
    userInput = (char *)malloc(50 * sizeof(char)); // Allocated but not freed

    // Simulate user input (for demonstration purposes)
    strcpy(userInput, "This is a very long input that exceeds the buffer!");

    processInput(userInput);

    // 5. Unhandled edge case: Check for null before using
    if (userInput) {
        free(userInput);  // Freeing allocated memory
    }

    return 0;
}
