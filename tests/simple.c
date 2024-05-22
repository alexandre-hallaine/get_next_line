#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

#include <fcntl.h>

long test(int fd) {
    char *line = get_next_line(fd);
    long len = line ? strlen(line) : -1;

    printf("fd: %d, len: %ld\n", fd, len);
    return len;
}

long test_file(char *file) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) return -2;

    printf("file: %s, ", file);
    return test(fd);
}

int main(int argc, char **argv) {
    if (test(-1) != -1) return 1;
    if (test_file("/dev/null") != -1) return 2;
    if (test_file("/dev/urandom") < 0) return 3;
    return 0;
}
