#include "getline.h"
#include "utilities.h"

/**
 * _realloc - reallocate a buffer
 * @old: pointer to the buffer
 * @old_size: current size of the buffer
 * @new_size: desired size of the buffer
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new buffer.
 */
static void *_realloc(void *old, size_t old_size, size_t new_size)
{
	void *new = NULL;

	if (old)
	{
		if (new_size)
		{
			new = malloc(new_size);
			if (new)
			{
				_memcpy(new, old, old_size < new_size ? old_size : new_size);
				free(old);
			}
		}
		else
		{
			free(old);
		}
	}
	return (new);
}

/**
 * _getline_append - appends input to line
 * @buff: buffer
 * @line: line
 * @size: line size
 * @n: number of character to copy
 * Return: pointer to the line input
 */
static char *_getline_append(buff_s *buff, char **line, size_t *size, size_t n)
{
	char *ptr = NULL;

	if (*line)
		ptr = _realloc(*line, *size, *size + n);
	else
		ptr = malloc(n + 1);

	if (ptr)
	{
		*line = ptr;
		if (*size)
			*size -= 1;

		_memcpy(*line + *size, buff->next, n);
		*size += n;

		(*line)[*size] = '\0';
		*size += 1;
	}
	else
	{
		free_all(1, *line);
		*line = NULL;
		*size = 0;
	}

	return (*line);
}

/**
 * _getline_buff - delete, get, and creat
 * e
 * @table: table
 * @fd: file descriptor
 * Return: NULL or pointer associated with fd
 */
static buff_s *_getline_buff(buf_node_table *table, const int fd)
{
	buff_hash_table_t *node = NULL;
	size_t hsh_index = fd % BUFF_TABLE_SIZE;

	if (table)
	{
		if (fd < 0)
		{
			for (hsh_index = 0; hsh_index < BUFF_TABLE_SIZE; hsh_index++)
			{
				while ((node = (*table)[hsh_index]))
				{
					(*table)[hsh_index] = node->next;
					free_all(1, node);
				}
			}
		}
		else
		{
			node = (*table)[hsh_index];
			while (node && node->fd != fd)
				node = node->next;

			if (node == NULL)
			{
				node = malloc(sizeof(*node));
				if (node)
				{
					node->fd = fd;
					node->buf.next = NULL;
					node->buf.left_proc = 0;
					node->next = (*table)[hsh_index];
					(*table)[hsh_index] = node;
				}
			}
		}
	}
	return (node ? &node->buf : NULL);
}

/**
 * my_getline - Read a line of input.
 * @fd: File descriptor from which to read.
 * Return: If an error occurs or there are no more lines, return NULL.
 * Otherwise, return the next line of input.
 */

char *my_getline(const int fd)
{
	static buf_node_table table;
	buff_s *buff_se = _getline_buff(&table, fd);
	char *line = NULL;
	size_t size = 0;
	ssize_t endOfLine = 0, numRead = 0;

	if (buff_se)
	{
		do {
			if (buff_se->left_proc == 0)
				buff_se->next = buff_se->buffer;
			if (numRead)
				buff_se->left_proc = numRead;
			if (buff_se->left_proc)
			{
				endOfLine = _memchr(buff_se->next, '\n', buff_se->left_proc);
				if (endOfLine == -1)
				{
					if (_getline_append(buff_se, &line, &size, buff_se->left_proc))
						buff_se->next += buff_se->left_proc, buff_se->left_proc = 0;
					else
						break;
				}
				else
				{
					if (_getline_append(buff_se, &line, &size, endOfLine + 1))
						buff_se->next += endOfLine + 1, buff_se->left_proc -= endOfLine + 1;
					break;
				}
			}
		} while ((numRead = read(fd, buff_se->buffer, BUFFER_SIZE)) > 0);
		if (numRead == -1)
		{
			free_all(1, line);
			line = NULL;
			size = 0;
		}
	}
	return (line);
}
