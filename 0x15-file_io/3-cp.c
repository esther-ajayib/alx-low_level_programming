#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * exit_error - Helper function to exit with an error message
 * @msg: The error message to display
 *
 * Description: Prints the error message to standard error and exits with
 *              a non-zero status code.
 */
void exit_error(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(1);
}

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 * Return: 0 on success, 1 on failure
 *
 * Description: Copies the content of a file to another file.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		exit_error("Usage: cp file_from file_to");

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
		exit_error("Error: Can't read from file");

	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (to_fd == -1)
	{
		close(from_fd);
		exit_error("Error: Can't write to file");
	}

	while ((bytes_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(from_fd);
			close(to_fd);
			exit_error("Error: Can't write to file");
		}
	}

	if (bytes_read == -1)
	{
		close(from_fd);
		close(to_fd);
		exit_error("Error: Can't read from file");
	}

	if (close(from_fd) == -1)
		exit_error("Error: Can't close file descriptor");

	if (close(to_fd) == -1)
		exit_error("Error: Can't close file descriptor");

	return (0);
}
