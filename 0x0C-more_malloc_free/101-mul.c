#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 98 on error
 */
int multiply(char *num1, char *num2) {
	int len1 = 0, len2 = 0, i, j, carry;
	int *result;
	int res_size;

	while (num1[len1] != '\0')
		len1++;
	while (num2[len2] != '\0')
		len2++;

	res_size = len1 + len2;
	result = calloc(res_size, sizeof(int));

	for (i = len1 - 1; i >= 0; i--) {
		carry = 0;
		for (j = len2 - 1; j >= 0; j--) {
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';
			int sum = digit1 * digit2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i] += carry;
	}

	i = 0;
	while (i < res_size - 1 && result[i] == 0)
		i++;

	for (; i < res_size; i++)
		printf("%d", result[i]);
	printf("\n");

	free(result);

	return (0);
}

int main(int argc, char *argv[]) {
	int i;

	char *num1;
	char *num2;

	if (argc != 3) {
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i] != '\0'; i++) {
		if (!isdigit((unsigned char)num1[i])) {
			printf("Error\n");
			return (98);
		}
	}

	for (i = 0; num2[i] != '\0'; i++) {
		if (!isdigit((unsigned char)num2[i])) {
			printf("Error\n");
			return (98);
		}
	}

	multiply(num1, num2);

	return (0);
}
