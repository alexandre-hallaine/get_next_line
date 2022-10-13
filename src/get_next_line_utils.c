#include <stddef.h>

size_t ft_strlen(const char *s)
{
	size_t len = 0;
	if (s)
		while (s[len])
			++len;
	return (len);
}

char *ft_strchr(const char *s, int c)
{
	if (s)
		for (; *s; ++s)
			if (*s == c)
				return (char *)s;
	return NULL;
}
