#include "elf_header.h"
#include <stdio.h>

int elf_header(const char *filename)
{
	FILE *file = fopen(filename, "rb");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", filename);
		return (1);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ...\n");
	printf("  Class:   ...\n");
	printf("  Data:    ...\n");
	printf("  Version: ...\n");  
	printf("  OS/ABI:  ...\n");
	printf("  ABI Version: ...\n");
	printf("  Type:    ...\n");
	printf("  Entry point address: ...\n");

	fclose(file);
	return (0);
}

/**
 * main - The entry point for the program to get the header of an ELF file
 * @argc: The number of arguments
 * @argv: The pointer to an array of arguments
 * Return: 0 on success, 98 on failure
 */

int main(int argc, char *argv[])
{
	int status;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	status = elf_header(argv[1]);
	return (status);
}
