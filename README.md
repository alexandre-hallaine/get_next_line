# Fast Get Next Line

## Overview

A highly efficient implementation of the `get_next_line` function in C, designed for superior speed when reading lines from files. Key features:

* **Optimized Buffering:** Leverages a `BUFFER_SIZE` buffer to streamline file I/O operations.
* **Flexible:** Works with standard C library functions (`strchr`, `strcpy`, etc.) with a `ft` branch providing a libc-free alternative for constrained environments.  
* **Dynamic Memory Management:** Allocates memory for each line as needed.

## Installation & Compilation

1. **Clone repository:**
   ```bash
   git clone https://github.com/your-username/fast-get-next-line 
   ```
2. **Compile:**
   ```bash
   make
   ```
3. **Link with your project:**
   ```bash
   gcc -o your_program your_program.c libgnl.a
   ```

## Performance

* **Benchmark File:**  6,488,666 bytes, 128,457 lines, 1,095,695 words.
* **Average Execution Time:** 0.030 seconds, demonstrating exceptional speed. 

## Example Usage

```c
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *line;
  while ((line = get_next_line(0))) { // Read from standard input (file descriptor 0)
    printf("%s\n", line);
    free(line); 
  }
  return 0;
}
```

## Notes

* Remember to free the memory returned by `get_next_line` to prevent memory leaks.
