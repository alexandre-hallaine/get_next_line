# GetNextLine

## Overview

`get_next_line` is a robust and efficient C function designed for reading text files line by line. It's particularly well-suited for handling large files due to its exceptional memory efficiency. Here's how it achieves this:

* **Intelligent Caching:** `get_next_line` only caches the necessary data for the current line, minimizing memory footprint and optimizing performance, especially for large files or resource-constrained environments.
* **Dynamic Buffer Management:** The `BUFFER_SIZE` macro lets you fine-tune how much data is read from the file in each I/O operation.

## Usage

1. **Include the Header:**
   ```c
   #include "get_next_line.h"  // Note: Use quotes for local header files
   ```

2. **Call the Function:**
   ```c
   int fd = open("your_file.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL) {
      printf("%s\n", line);
      free(line);
   }

   close(fd);
   ```

## Build and Installation (with Meson)

1. **Configure and Build:**
   ```bash
   meson setup build
   meson compile -C build
   ```

2. **Install (Optional):**
   ```bash
   meson install -C build
   ```

3. **Link:**
   ```bash
   gcc main.c -lgnl
   ```
   Add `-L <path_to_build_dir>` if you haven't installed the library.

## Testing

- **Functional Test (`simple.c`):**
   ```bash
   meson test -C build
   ```

- **Speed Test (`speed.c`):**
   ```bash
   ./build/speed <your_file.txt>
   ```

## Error Handling and Memory Management

* **Error Handling:** Always check the return value of `get_next_line`. If it's `NULL`, this indicates either an error or the end of the file has been reached.

* **Memory Management:** Free the memory allocated by `get_next_line` after processing each line to prevent memory leaks:
   ```c
   free(line);
   ```

## License

This project is licensed under the MIT License.  See the [LICENSE](LICENSE) file for details.
