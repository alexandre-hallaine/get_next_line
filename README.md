# Fast Get Next Line - C Implementation

## Overview

An optimized C implementation of the `get_next_line` function, engineered for high performance. This function reads lines from a file descriptor into a dynamic string, focusing on scalability and error handling.

> ⚠️ **Disclaimer**: This repository is not open for contributions.

## Table of Contents

- [Installation & Compilation](#installation--compilation)
- [Usage](#usage)
- [Error Handling](#error-handling)
- [Technical Specifications](#technical-specifications)
- [Performance Metrics](#performance-metrics)
- [Example](#example)

## Installation & Compilation

Clone this repository and navigate to the directory where it is located. The core files for the `get_next_line` function are:

- **Header File**: `include/get_next_line.h`
- **Source Files**: 
  - `src/get_next_line.c`
  - `src/get_next_line_utils.c`

Compile these source files along with your project to integrate the `get_next_line` functionality:

```bash
gcc -o your_program your_program.c src/get_next_line.c src/get_next_line_utils.c
```

## Usage

The `main.c` under the `src` directory serves as a testing suite. The program reads from a file if specified as a command-line argument, otherwise from the standard input.

### Command Line Usage

```bash
./get_next_line <filename>  # Reads from a file
./get_next_line             # Reads from standard input
```

## Error Handling

The code gracefully handles possible memory allocation and file I/O errors. Make sure to integrate these error-handling mechanisms into your own application logic.

## Technical Specifications

- **Language**: C
- **Required Libraries**: `<stdio.h>`, `<stdlib.h>`, `<unistd.h>`
- **Data Structures**: Dynamic strings
- **Utility Functions**: 
  - `ft_strlen`: Custom implementation of `strlen`
  - `ft_strchr`: Custom implementation of `strchr`
- **Memory Management**: Uses dynamic memory allocation; callers must free allocated memory.
- **Concurrency**: Utilizes a static variable; not thread-safe.
- **Buffering**: Employs a buffer of size `BUFFER_SIZE` for optimized I/O.

## Performance Metrics

Tested on a `big.txt` file with the following characteristics:

- **File Size**: 6,488,666 bytes
- **Lines**: 128,457
- **Words**: 1,095,695

Average execution time: 0.048 seconds.

## Example

A minimal example to demonstrate usage:

```c
#include <stdio.h>
#include "get_next_line.h"

int main() {
    char *line;
    while ((line = get_next_line(0)) != NULL) {
        printf("%s\n", line);
        free(line);
    }
    return 0;
}
```
