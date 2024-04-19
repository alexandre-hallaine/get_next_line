#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *get_next_line(int fd) {
    static char *str = NULL;
    char buf[BUFFER_SIZE + 1], *endl = NULL;
    ssize_t str_len = 0, buf_len = 0;

    if (str != NULL) {
        str_len = strchr(str, '\0') - str;
        endl = strchr(str, '\n');
    }

    while (endl == NULL) {
        buf_len = read(fd, buf, BUFFER_SIZE);
        if (buf_len <= 0) break;
        buf[buf_len] = '\0';

        str = realloc(str, str_len + buf_len + 1);
        strcpy(str + str_len, buf);

        endl = strchr(str + str_len, '\n');
        str_len += buf_len;
    }

    char *line = str;
    if (endl == NULL)
        str = NULL;
    else {
        *endl = '\0';
        str = strdup(endl + 1);
    }

    return line;
}
