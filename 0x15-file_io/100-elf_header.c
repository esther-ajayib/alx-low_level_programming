#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

#define BUF_SIZE 64

/**
 * print_error - Prints the error message and exits with status code 98
 * @msg: The error message to be printed
 */
void print_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: The ELF header structure
 */
void print_elf_header(Elf64_Ehdr header)
{
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
			printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
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
			printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
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
			printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
	}
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", header.e_type);
	}
	printf("  Entry point address:               0x%lx\n", (unsigned long) header.e_entry);
}

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: Cannot read file");

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file");

	print_elf_header(header);

	if (close(fd) == -1)
		print_error("Error: Cannot close file");

	return (0);
}
