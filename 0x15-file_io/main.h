#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>  /* for size_t */

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void print_error(char *msg);
void print_elf_header(Elf64_Ehdr header);

#endif /* MAIN_H */
