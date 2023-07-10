#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf_header.h>

void print_error(const char *message) 
{
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header(const Elf64_Ehdr *header) 
{
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) 
    {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:   %s\n", (header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
    printf("  Data:    %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version: %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:  %s\n", (header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Unknown");
    printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:    ");
    switch (header->e_type) 
    {
        case ET_NONE:
            printf("No file type\n");
            break;
        case ET_REL:
            printf("Relocatable file\n");
            break;
        case ET_EXEC:
            printf("Executable file\n");
            break;
        case ET_DYN:
            printf("Shared object file\n");
            break;
        case ET_CORE:
            printf("Core file\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Entry point address: 0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        print_error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) 
    {
        print_error("Unable to open file");
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) 
    {
        print_error("Failed to read ELF header");
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) 
    {
        print_error("File is not an ELF file");
    }

    print_elf_header(&header);

    close(fd);
    return (0);
}
