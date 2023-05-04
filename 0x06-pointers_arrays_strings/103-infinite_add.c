#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: The first number to add
 * @n2: The second number to add
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: A pointer to the result, or 0 if the result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, len, i, j, k, sum, carry;

	for (len1 = 0; n1[len1]; len1++)
		;
	for (len2 = 0; n2[len2]; len2++)
		;
	if (len1 > size_r || len2 > size_r)
		return (0);
	i = len1 - 1, j = len2 - 1, len = carry = 0;
	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		if (len >= size_r)
			return (0);
		r[len++] = sum % 10 + '0';
		carry = sum / 10;
	}
	if (len >= size_r)
		return (0);
	r[len] = '\0';
	for (i = 0, k = len - 1; i < k; i++, k--)
		sum = r[i], r[i] = r[k], r[k] = sum;
	return (r);
}
