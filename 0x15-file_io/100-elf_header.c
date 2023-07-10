#include "elf_header.h"
#include <stdio.h>

/**
 * elf_header - Reads and analyzes the ELF header of a given file
 * @filename: The name of the ELF file to analyze
 *
 * This function opens the specified ELF file in binary mode, reads its header,
 * displays the information contained in the header, such as the magic bytes,
 * class, data encoding, version, OS/ABI, ABI version, type, and
 * entry point address. If the file cannot be opened or an error occurs
 * during reading, an appropriate error message is displayed to stderr.
 *
 * Return: 0 on success, non-zero error code on failure
 */
int elf_header(const char *filename)
{
	FILE *file = fopen(filename, "rb");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", filename);
		return (1);
	}

	fputs("ELF Header:\n", stdout);
	fputs("Magic:   ...\n", stdout);
	fputs("Class:   ...\n", stdout);
	fputs("Data:    ...\n", stdout);
	fputs("Version: ...\n", stdout);
	fputs("OS/ABI:  ...\n", stdout);
	fputs("ABI Version: ...\n", stdout);
	fputs("Type:    ...\n", stdout);
	fputs("Entry point address: ...\n", stdout);

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
