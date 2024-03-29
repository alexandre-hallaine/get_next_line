#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1 << 8)
#endif

#include <stddef.h>

char *get_next_line(int fd);

size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);

#endif
