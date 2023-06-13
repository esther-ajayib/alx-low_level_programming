#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * print_error_and_exit - Print error message and exit with specified code.
 * @code: The exit code.
 * @msg: The error message.
 */
void print_error_and_exit(int code, char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * cp_file - Copy the content of one file to another.
 * @file_from: The source file name.
 * @file_to: The destination file name.
 */
void cp_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(98, "Error: Can't read from file");

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		print_error_and_exit(99, "Error: Can't write to file");

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			print_error_and_exit(99, "Error: Can't write to file");
	}

	if (bytes_read == -1)
		print_error_and_exit(98, "Error: Can't read from file");

	if (close(fd_from) == -1)
		print_error_and_exit(100, "Error: Can't close fd");

	if (close(fd_to) == -1)
		print_error_and_exit(100, "Error: Can't close fd");
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or the appropriate error code.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to");

	cp_file(argv[1], argv[2]);

	return (0);
}
