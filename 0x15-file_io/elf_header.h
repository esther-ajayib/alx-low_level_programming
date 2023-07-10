#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <elf.h>

int elf_header(const char *filename);
void print_error(const char *msg);
void print_elf_header(Elf64_Ehdr *header);
const char *get_osabi_name(unsigned char osabi);
const char *get_type_name(unsigned int type);

#endif /* ELF_HEADER_H */
