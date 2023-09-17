#include "shell.h"

/**
 * _input_buffer - handle input and buffers
 * @_info: struct | param
 * @buf: &buffer
 * @_length: &len
 * Return: ssize_t | number of bytes read
 */

ssize_t _input_buffer(info_t *_info, char **buf, size_t *_length)
{
	ssize_t read_file = 0;
	size_t len_p = 0;

	if (!*_length)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sig_num_handler);

		read_file = getline(buf, &len_p, stdin);

		if (read_file > 0)
		{
			if ((*buf)[read_file - 1] == '\n')
			{
				(*buf)[read_file - 1] = '\0';
				read_file--;
			}
			_info->linecount_flag = 1;
			clear_comment(*buf);
			all_history_list(_info, *buf, _info->histcount++);
			*_length = read_file;
			_info->cmd_buf = buf;
		}
	}
	return (read_file);
}

/**
 * read_line - reads an input line
 * @_info: param struct|
 * Return: int | count of bytes read
 */
ssize_t read_line(info_t *_info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t read_file = 0;
	char **buffer_p = &(_info->arg), *p;

	buf = NULL;
	_putchar(BUF_FLUSH);
	read_file = _input_buffer(_info, &buf, &len);

	if (read_file == -1)
		return (-1);

	if (len)
	{
		j = i = len = 0;
		p = buf + i;

		read_chain(_info, buf, &j, i, len);

		while (j < len)
		{
			if (yes_chain(_info, buf, &j))
				break;
			j++;
		}

		i = j + 1;

		if (i >= len)
		{
			i = len = 0;
			_info->cmd_buf_type = CMD_NORM;
		}
		*buffer_p = p;

		return (_str_len(p));
	}
	*buffer_p = buf;
	return (read_file);
}

/**
 * read_buffer - reads the command from a buffer
 * @_info: struct | param
 * @buf: buffer
 * @i: int | size
 * Return: read bytes
 */
ssize_t read_buffer(info_t *_info, char *buf, size_t *i)
{
	ssize_t read_bytes = 0;

	if (*i)
		return (0);

	read_bytes = read(_info->readfd, buf, READ_BUF_SIZE);

	if (read_bytes >= 0)
		*i = read_bytes;

	return (read_bytes);
}

/**
 * get_line - gets the next line of input
 * @_info: struct | param
 * @ptr: pointer to buffer
 * @_length: size of allocated ptr buffer
 * Return: s
 */
int get_line(info_t *_info, char **ptr, size_t *_length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t read_bytes = 0, s = 0;
	char *p = NULL, *newp = NULL, *c;

	p = *ptr;

	if (p && _length)
		s = *_length;

	if (i == len)
		i = len = 0;

	read_bytes = read_buffer(_info, buf, &len);

	if (read_bytes == -1 || (read_bytes == 0 && len == 0))
		return (-1);

	c = _str_chr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	newp = _realloc(p, s, s ? s + k : k + 1);

	if (!newp)
		return (p ? (free(p), -1) : -1);

	if (s)
		_strn_cat(newp, buf + i, k - i);
	else
		_strn_cpy(newp, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = newp;

	if (_length)
		*_length = s;
	*ptr = p;

	return (s);
}

/**
 * sig_num_handler - handles ctrl + C
 * @sig_num: signal number to be blocked
 * Return: void
 */

void sig_num_handler(__attribute__((unused)) int sig_num)
{
	_puts("\n$ ");
	_putchar(BUF_FLUSH);
}
