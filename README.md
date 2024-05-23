# GetNextLine

`get_next_line` is a powerful C function designed for efficiently reading text files line by line. It's particularly valuable for handling large files due to its smart memory management:

* **Minimal Memory Footprint:** Caches only the data needed for the current line, making it ideal for large files or resource-constrained systems.
* **Customizable Buffer Size:**  The `BUFFER_SIZE` macro allows you to tailor how much data is read in each operation.

## Installation

1. **Configure and Build:**
   ```bash
   meson setup build
   meson compile -C build
   ```

2. **Install (Optional):**
   ```bash
   meson install -C build
   ```

3. **Link in Your Project:**
   ```bash
   gcc main.c -lgnl
   ```
   Add `-L <path_to_build_dir>` if the library is not installed.

## Example Code

```c
#include "get_next_line.h"

int main() {
   int fd = open("your_file.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL) {
      printf("%s\n", line);
      free(line); // Important: Prevent memory leaks
   }

   close(fd);
   return 0;
}
```

## Testing

- **Functional Tests (`simple.c`):**
   ```bash
   meson test -C build
   ```

- **Speed Test (`speed.c`):**
   ```bash
   ./build/tests/speed <your_file.txt>
   ```

## Additional Notes

* **Multiple Files:** When reading from multiple files sequentially, ensure all lines are consumed from the current file (until `get_next_line` returns `NULL`) before switching to the next. Alternatively, clear the internal buffer by reading from `/dev/null`.

## License

This project is licensed under the MIT License.  See the [LICENSE](LICENSE) file for details.
