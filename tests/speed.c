#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/time.h>

#define NUM_TESTS 100
#define SKIP_OUTLIERS 10

void error(int code, char *str, ...) {
    va_list args;
    va_start(args, str);
    vfprintf(stderr, str, args);
    va_end(args);
    exit(code);
}

long test(char *file) {
    struct timeval start, end;

    int fd = open(file, O_RDONLY);
    if (fd == -1)
        error(2, "Error: Cannot open file '%s'\n", file);

    char *line;
    gettimeofday(&start, NULL);
    while ((line = get_next_line(fd))) free(line);
    gettimeofday(&end, NULL);

    close(fd);
    return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

int main(int argc, char **argv) {
    if (argc != 2)
        error(1, "Usage: %s <file_to_read>\n", argv[0]);
    
    long timings[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++)
        timings[i] = test(argv[1]);

    for (int i = 0; i < NUM_TESTS - 1; i++)
        for (int j = 0; j < NUM_TESTS - i - 1; j++)
            if (timings[j] > timings[j + 1]) {
                long temp = timings[j];
                timings[j] = timings[j + 1];
                timings[j + 1] = temp;
            }

    long total = 0; // Exclude outliers
    for (int i = SKIP_OUTLIERS; i < NUM_TESTS - SKIP_OUTLIERS; i++)
        total += timings[i];
    long average = total / (NUM_TESTS - 2 * SKIP_OUTLIERS);

    printf("Average time (excluding outliers): %ld microseconds\n", average); 
    return 0;
}
