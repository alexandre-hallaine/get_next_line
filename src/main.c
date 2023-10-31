#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

char *get_next_line(int fd);

void error(const char *str) {
    printf("%s", str);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc > 2)
        error("usage: ./a.out <file>");
    int fd = argc == 1 ? 0 : open(argv[1], O_RDONLY);
    if (fd == -1)
        error("an error occured with open");

    clock_t start, end;
    char *str;
    size_t index = 0;
    (void) index;

    start = clock();
    while ((str = get_next_line(fd))) {
        // printf("%zu: %s", ++index, str);
        free(str);
    }
    end = clock();
    close(fd);

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("get_next_line took %f seconds to execute.\n", cpu_time_used);
    return 0;
}
