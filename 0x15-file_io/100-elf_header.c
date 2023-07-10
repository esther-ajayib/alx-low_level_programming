#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @elf_header: Pointer to the ELF header structure
 */
void print_elf_header(uint8_t *elf_header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++)
		printf("%02x ", elf_header[i]);
	printf("\n");
	printf("  Class:   %s\n", elf_header[4] == 1 ? "ELF32" : "ELF64");
	printf("  Data:    %s\n", elf_header[5] == 1 ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version: %d (current)\n", elf_header[6]);
	printf("  OS/ABI:  UNIX - ");
	switch (elf_header[7])
	{
		case 0: printf("System V\n"); break;
		case 1: printf("HP-UX\n"); break;
		case 2: printf("NetBSD\n"); break;
		case 3: printf("Linux\n"); break;
		case 6: printf("Solaris\n"); break;
		case 9: printf("FreeBSD\n"); break;
		default: printf("<unknown: %d>\n", elf_header[7]); break;
	}
	printf("  ABI Version: %d\n", elf_header[8]);
	printf("  Type:    ");
	switch (*(uint16_t *)(elf_header + 16))
	{
		case 1: printf("REL (Relocatable file)\n"); break;
		case 2: printf("EXEC (Executable file)\n"); break;
		case 3: printf("DYN (Shared object file)\n"); break;
		case 4: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %d>\n", *(uint16_t *)(elf_header + 16)); break;
	}
	printf("  Entry point address: 0x%x\n", *(uint32_t *)(elf_header + 24));
}

/**
 * elf_header - Reads and analyzes the ELF header of a given file
 * @filename: The name of the ELF file to analyze
 *
 * This function opens the specified ELF file in binary mode, reads its header,
 * and calls the print_elf_header function to display the information.
 * If the file cannot be opened or an error occurs during reading, an appropriate
 * error message is displayed to stderr.
 *
 * Return: 0 on success, non-zero error code on failure
 */
int elf_header(const char *filename)
{
	int file = open(filename, O_RDONLY);

	if (file == -1)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", filename);
		return 98;
	}

	uint8_t elf_header[32];
	ssize_t bytes_read = read(file, elf_header, sizeof(elf_header));
	if (bytes_read != sizeof(elf_header))
	{
		fprintf(stderr, "Error: Failed to read ELF header\n");
		close(file);
		return 98;
	}

	print_elf_header(elf_header);

	close(file);
	return 0;
}

/**
 * main - The entry point for the program to get the header of an ELF file
 * @argc: The number of arguments
 * @argv: The pointer to an array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	return elf_header(argv[1]);
}
