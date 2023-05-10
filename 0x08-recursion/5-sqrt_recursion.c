#include "main.h"

/**
 * sqrt_helper - Recursive helper function to find the square root.
 * @n: The number to find the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: The square root if found, or -1 if the square root is not natural.
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);

	if (guess * guess > n)
		return (-1);

	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The square root if found, or -1 if the square root is not natural.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}
