#include "main.h"

/**
 * create_file - creates a file.
 * @filename: name of the file to be created
 * @text_content: is a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure (file can not be created, file can
 * not be written, write “fails”
 */

int create_file(const char *filename, char *text_content)
{
	int _file, text_wr;
	int _len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[_len])
		{
			_len++;
		}
	}

	_file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	text_wr = write(_file, text_content, _len);

	if (_file == -1 || text_wr == -1)
		return (-1);

	close(_file);

	return (1);
}
