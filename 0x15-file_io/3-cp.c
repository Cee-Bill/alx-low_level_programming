#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * new_buffer - creates a buffer of 1024 bytes.
 * @file_to: char * | the file name name to copied to
 * Return: pointer to the new buffer
 */

char *new_buffer(char *file_to)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Cant't write to %s\n",
			file_to);
		exit(99);
	}
	return (buffer);
}

/**
 * close_fd - closes a file descriptor
 * @fd: int | the descriptor to be closed
 * Return: void
 */

void close_fd(int fd)
{
	int _close;

	_close = close(fd);
	if (_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
			fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: int | the count of arguements
 * @argv: array * | array of pointers to each arguement
 * Return: 0 if successful. f the number of argument is not the correct
 * one, exit with code 97
 */

int main(int argc, char *argv[])
{
	int f_from, f_to, _read, _write;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = new_buffer(argv[2]);
	f_from = open(argv[1], O_RDONLY);
	_read = read(f_from, buffer, 1024);
	f_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f_from == -1 || _read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n",
				argv[1]);
			free(buffer);
			exit(98);
		}
		_write = write(f_to, buffer, _read);
		if (f_to == -1 || _write == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		_read = read(f_from, buffer, 1024);
		f_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (_read > 0);
	free(buffer);
	close_fd(f_from);
	close_fd(f_to);

	return (0);
}
