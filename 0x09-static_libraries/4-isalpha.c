#include "main.h"

/**
 * _isalpha - checking for alphabetic character
 * @v: the character to be checked
 * Return: 1 if v is a letter, 0 otherwise
 */
int _isalpha(int v)
{
	return ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z'));
}
