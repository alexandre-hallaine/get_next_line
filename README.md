# Get Next Line (GNL) Library

This C library provides the function `get_next_line` for efficiently reading a file line by line.

## Purpose

The `get_next_line` function is designed to handle reading from files in a buffered manner, optimizing performance while maintaining the ability to read one line at a time. It dynamically allocates memory for each line, returning a null-terminated string (`char *`).

## Usage

1. **Include the header file:**

   ```c
   #include <get_next_line.h>
   ```

2. **Call the function:**

   ```c
   int fd = open("your_file.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL) {
       printf("%s\n", line); // Process the line
       free(line); // Free the memory allocated by get_next_line
   }

   close(fd);
   ```

## Installation

This project uses the Meson build system. To build and install the library, follow these steps:

1.  **Install Meson:** If you don't have Meson installed, you can get it from https://mesonbuild.com/.
2.  **Configure Build:** Run `meson setup build` to configure the build directory.
3.  **Build:** Run `meson compile -C build` to compile the library.
4.  **Install:** Run `meson install -C build` to install the library and header file.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Additional Notes

- Error handling is not extensively implemented in this basic version. Consider adding error checks in a production environment.
- The `BUFFER_SIZE` constant in `get_next_line.c` controls the buffer size. Adjust it for optimal performance.
