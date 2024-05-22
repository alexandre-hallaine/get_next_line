#pragma once

#ifndef BUFFER_SIZE
# define BUFFER_SIZE (1 << 10)
#endif

char *get_next_line(int fd);
