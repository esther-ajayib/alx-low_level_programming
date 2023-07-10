#include "elf_header.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * print_error - Prints an error message to stderr and exits with status code 98
 * @msg: The error message to print
 */
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
		   header->e_ident[0], header->e_ident[1], header->e_ident[2], header->e_ident[3],
		   header->e_ident[4], header->e_ident[5], header->e_ident[6], header->e_ident[7],
		   header->e_ident[8], header->e_ident[9], header->e_ident[10], header->e_ident[11],
		   header->e_ident[12], header->e_ident[13], header->e_ident[14], header->e_ident[15]);
	printf("  Class:                             ELF%d\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? 32 : 64);
	printf("  Data:                              %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", get_osabi_name(header->e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", get_type_name(header->e_type));
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * get_osabi_name - Returns the name corresponding to the given OS/ABI identifier
 * @osabi: The OS/ABI identifier
 *
 * Return: The name of the OS/ABI
 */
const char *get_osabi_name(unsigned char osabi)
{
	switch (osabi)
	{
		case ELFOSABI_SYSV: return "UNIX - System V";
		case ELFOSABI_NETBSD: return "UNIX - NetBSD";
		case ELFOSABI_SOLARIS: return "UNIX - Solaris";
		default: return "<unknown>";
	}
}

/**
 * get_type_name - Returns the name corresponding to the given ELF type
 * @type: The ELF type
 *
 * Return: The name of the ELF type
 */
const char *get_type_name(unsigned int type)
{
	switch (type)
	{
		case ET_NONE: return "NONE (No file type)";
		case ET_REL: return "REL (Relocatable file)";
		case ET_EXEC: return "EXEC (Executable file)";
		case ET_DYN: return "DYN (Shared object file)";
		case ET_CORE: return "CORE (Core file)";
		default: return "<unknown>";
	}
}

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
	int fd, read_count;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Error: Unable to open file");

	read_count = read(fd, &header, sizeof(header));
	if (read_count != sizeof(header))
		print_error("Error: Unable to read ELF header");

	print_elf_header(&header);

	close(fd);
	return 0;
}

/**
 * main - The entry point for the program to get the header of an ELF file
 * @argc: The number of arguments
 * @argv: The pointer to an array of arguments
 *
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
