#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: is the name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write “fails”
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_op, file_wr, _len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[_len])
			_len++;
	}

	file_op = open(filename, O_WRONLY | O_APPEND);
	file_wr = write(file_op, text_content, _len);

	if (file_op == -1 || file_wr == -1)
		return (-1);

	close(file_op);
	return (1);
}
