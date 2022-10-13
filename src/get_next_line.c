#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

char *alloc(char *str, size_t len)
{
	char *new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);

	new[len] = 0;
	while (len--)
		new[len] = str[len];
	return (new);
}

char *concat_buff(char *str, size_t str_len, char *buff, size_t buff_len)
{
	if (!str)
		return alloc(buff, buff_len);

	char *new_str = malloc(sizeof(char) * (str_len + buff_len + 1));
	if (!new_str)
		return (NULL);

	new_str[str_len + buff_len] = 0;
	while (buff_len--)
		new_str[str_len + buff_len] = buff[buff_len];
	while (str_len--)
		new_str[str_len] = str[str_len];

	free(str);
	return new_str;
}

char *get_next_line(int fd)
{
	static char *last = NULL;
	char *str = last, *endl = ft_strchr(str, '\n'), buff[BUFFER_SIZE + 1];
	last = NULL;

	size_t size = endl ? ft_strlen(endl) + (endl - str) : ft_strlen(str);
	ssize_t buff_size = 0;

	while (endl == NULL && (buff_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[buff_size] = 0;
		str = concat_buff(str, size, buff, buff_size);

		endl = ft_strchr(str + size, '\n');
		size += buff_size;
	}

	if (endl != NULL)
	{
		last = alloc(endl + 1, size - (endl - str));
		str[endl - str + 1] = 0;
	}
	return str;
}
