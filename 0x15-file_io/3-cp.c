#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int safe_close(int);
int copy_file(const char *file_from, const char *file_to);

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 on success, otherwise 1
 */
int main(int argc, char *argv[])
{
	const char *file_from;
        const char *file_to;
	int result;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	result = copy_file(file_from, file_to);

	return ((result == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}

/**
 * copy_file - Copies the content of one file to another
 * @file_from: The source file
 * @file_to: The destination file
 *
 * Return: 0 on success, otherwise -1
 */
int copy_file(const char *file_from, const char *file_to)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;
	int from_fd, to_fd;

	from_fd = open(file_from, O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return (-1);
	}

	to_fd = open(file_to, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		safe_close(from_fd);
		return (-1);
	}

	while ((bytes_read = read(from_fd, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			safe_close(from_fd);
			safe_close(to_fd);
			return (-1);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		safe_close(from_fd);
		safe_close(to_fd);
		return (-1);
	}

	if (safe_close(from_fd) == -1)
		return (-1);

	if (safe_close(to_fd) == -1)
		return (-1);

	return (0);
}

/**
 * safe_close - Closes a file descriptor
 * @fd: The file descriptor to close
 *
 * Return: 0 on success, otherwise -1
 */
int safe_close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		return -1;
	}
	return (0);
}
