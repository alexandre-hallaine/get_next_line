#pragma once

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1 << 8)
#endif

char *get_next_line(int fd);
