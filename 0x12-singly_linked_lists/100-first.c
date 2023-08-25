#include <stdio.h>

// Declare the function prototype
void print_intro(void) __attribute__((constructor));

// Function that prints an introduction
void print_intro(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}

int main(void)
{
    // The main function is empty in this example
    return 0;
}
