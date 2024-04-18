#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/time.h>

void error(int code, char *str, ...) {
    va_list args;

    va_start(args, str);
    vfprintf(stderr, str, args);
    va_end(args);
    exit(code);

}

size_t test(char *file) {
    struct timeval start, end;

    int fd = open(file, O_RDONLY);
    if (fd == -1)
        error(2, "Failed to open file %s\n", file);

    gettimeofday(&start, NULL);

    char *line;
    while ((line = get_next_line(fd)))
        free(line);

    gettimeofday(&end, NULL);

    close(fd);
    return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

int main(int argc, char **argv) {
    if (argc != 2)
        error(1, "Usage: %s <file>\n", argv[0]);

    size_t tmp, time = test(argv[1]);
    for (int i = 0; i < 100; i++)
        if ((tmp = test(argv[1])) < time)
            time = tmp;

    printf("Average time: %ld µs\n", time);
}
