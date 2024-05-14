# Get Next Line (GNL) Library

This C library provides the function `get_next_line` for efficiently reading a file line by line.

## Purpose

The `get_next_line` function is designed to handle reading from files in a buffered manner, optimizing performance while maintaining the ability to read one line at a time.

## Usage

1. **Include the header file:**

   ```c
   #include "get_next_line.h"
   ```

2. **Call the function:**

   ```c
   int fd = open("your_file.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL) {
       // Process the line
       printf("%s\n", line);
       free(line); // Free the memory allocated by get_next_line
   }

   close(fd);
   ```

## Building and Testing

- This project uses Meson. Follow Meson's instructions to build and run.

## License

Specify your license here. If you are unsure, the MIT license is a permissive option.

## Additional Notes

- Error handling is not extensively implemented in this basic version. Consider adding error checks in a production environment.
- The `BUFFER_SIZE` constant in `get_next_line.c` controls the buffer size. Adjust it for optimal performance.
