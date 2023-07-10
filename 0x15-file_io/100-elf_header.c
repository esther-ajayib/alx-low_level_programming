#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

/**
 * print_error - Prints an error message to stderr and exits with status code 98
 * @message: The error message to display
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * elf_header - Reads and analyzes the ELF header of a given file
 * @filename: The name of the ELF file to analyze
 */
void elf_header(const char *filename)
{
	int fd, nread;
	Elf64_Ehdr header;
	char buffer[BUFFER_SIZE];

	/* Open the file in read-only mode */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Unable to open file");

	/* Read the ELF header */
	nread = read(fd, &header, sizeof(header));
	if (nread != sizeof(header))
		print_error("Error reading ELF header");

	/* Check if the file is a valid ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	/* Print the ELF header information */
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %d>\n", header.e_ident[EI_OSABI]);
		break;
	}
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header.e_type)
	{
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Entry point address:               0x%lx\n", header.e_entry);

	close(fd);
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
		print_error("Usage: elf_header elf_filename");

	elf_header(argv[1]);
	return 0;
}
