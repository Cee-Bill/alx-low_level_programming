#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to
 * the POSIX standard output
 * @filename: char | pointer to the textfile
 * @letters: size_t | number of letters it should read and print
 * Return: actual number of letters it could read and print
 * or 0, if the file cannot be opened or read.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t _file, text_rd, text_wr;
	char *text;

	if (filename == NULL)
		return (0);

	_file = open(filename, O_RDONLY);
	if (_file == -1)
		return (0);

	text = malloc(sizeof(char) * letters);
	if (text == NULL)
		return (0);

	text_rd = read(_file, text, letters);
	if (text_rd == -1)
	{
		free(text);
		close(_file);
		return (0);
	}

	text_wr = write(STDOUT_FILENO, text, text_rd);
	if (text_wr == -1)
	{
		free(text);
		close(_file);
		return (0);
	}

	close(_file);
	return (text_wr);
}
