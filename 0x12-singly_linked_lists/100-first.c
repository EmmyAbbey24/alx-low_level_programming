#include <stdio.h>

/* Declare the function prototype */
void print_intro(void) __attribute__((constructor));

/**
 * print_intro - Prints an introduction
 *
 * Description: This function is executed automatically
 * before the main function is called. It prints two lines.
 */
void print_intro(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    /* The main function is empty in this example */
    return 0;
}
