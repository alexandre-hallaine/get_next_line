#pragma once

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1 << 8)
#endif

// get_next_line.c
char    *get_next_line(int fd);
