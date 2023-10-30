# Fast Get Next Line in C

## Introduction

This project is an extremely fast version of the `get_next_line` function in C. This implementation is crafted for performance and is not intended to follow any specific coding norms or academic guidelines.

> :warning: **Disclaimer:** This is an archived project and is not accepting any contributions or updates. It is not compliant with any standard coding norms.

## Table of Contents

- [Installation & Compilation](#installation--compilation)
- [Usage](#usage)
- [Testing](#testing)
- [Performance](#performance)

## Installation & Compilation

**Files for `get_next_line` Function:**

- `get_next_line.h`
- `get_next_line.c`
- `get_next_line_utils.c`

Simply include these files in your project.

## Usage

### Basic Example

```c
#include "get_next_line.h"

int main(void) {
    char *line;
    while ((line = get_next_line(0))) {
        printf("%s\n", line);
        free(line);
    }
    return 0;
}
```

## Testing

The repository includes a Makefile exclusively for testing purposes. To run the test:

```bash
$ make
```

> Note: The `Makefile` is not a prerequisite for using `get_next_line` in your projects; it is provided only for testing.

## Performance

Performance has been a primary focus for this implementation. Benchmarks were performed on a `big.txt` file with these attributes:

- File Size: 6,488,666 bytes
- Lines: 128,457
- Words: 1,095,695

Average real-time duration for reading the file: ~0.065s
