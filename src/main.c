#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

void error(char *str)
{
	printf("%s", str);
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		error("usage: ./a.out <file>");

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("an error occured with open");

	size_t index = 0;
	char *str;
	while ((str = get_next_line(fd)))
	{
		//printf("%zu: %s", ++index, str);
		free(str);
	}
	(void)index;

	close(fd);
	return 0;
}
