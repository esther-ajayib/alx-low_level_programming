#include "elf_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
	int file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to open file %s\n", filename);
		return (98);
	}

	char magic[4];
	if (read(file_descriptor, magic, 4) != 4)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	// Display the information from the ELF header
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n", magic[0], magic[1], magic[2], magic[3]);

	// Read and display the remaining header information
	// Modify the code below to read the necessary information
	// and display it in the desired format

	char class;
	if (read(file_descriptor, &class, 1) != 1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read class from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	char data;
	if (read(file_descriptor, &data, 1) != 1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read data encoding from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	unsigned char version;
	if (read(file_descriptor, &version, 1) != 1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read version from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	char os_abi;
	if (read(file_descriptor, &os_abi, 1) != 1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read OS/ABI from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	unsigned char abi_version;
	if (read(file_descriptor, &abi_version, 1) != 1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read ABI version from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	lseek(file_descriptor, 8, SEEK_CUR); // Skip the next 8 bytes

	unsigned short type;
	if (read(file_descriptor, &type, 2) != 2)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read type from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	lseek(file_descriptor, 36, SEEK_CUR); // Skip the next 36 bytes

	unsigned long long entry_point;
	if (read(file_descriptor, &entry_point, 8) != 8)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read entry point address from file %s\n", filename);
		close(file_descriptor);
		return (98);
	}

	printf("  Class:   %s\n", (class == 1) ? "ELF32" : "ELF64");
	printf("  Data:    %s\n", (data == 1) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version: %u (current)\n", version);
	printf("  OS/ABI:  %s\n", get_os_abi_string(os_abi));
	printf("  ABI Version: %u\n", abi_version);
	printf("  Type:    %s\n", get_elf_type_string(type));
	printf("  Entry point address: %llx\n", entry_point);

	close(file_descriptor);
	return (0);
}

/**
 * get_os_abi_string - Returns the string representation of the OS/ABI byte
 * @os_abi: The OS/ABI byte value
 *
 * Return: The string representation of the OS/ABI byte
 */
const char *get_os_abi_string(char os_abi)
{
	switch (os_abi)
	{
	case 0:
		return "System V";
	case 1:
		return "HP-UX";
	case 2:
		return "NetBSD";
	case 3:
		return "Linux";
	case 4:
		return "GNU Hurd";
	case 6:
		return "Solaris";
	case 7:
		return "AIX";
	default:
		return ("Unknown");
	}
}

/**
 * get_elf_type_string - Returns the string representation of the ELF type
 * @type: The ELF type value
 *
 * Return: The string representation of the ELF type
 */
const char *get_elf_type_string(unsigned short type)
{
	switch (type)
	{
	case 1:
        return "REL (Relocatable file)";
	case 2:
		return "EXEC (Executable file)";
	case 3:
		return "DYN (Shared object file)";
	case 4:
		return "CORE (Core file)";
	default:
		return ("Unknown");
	}
}

/**
 * main - The entry point for the program to get the ELF header of a file
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