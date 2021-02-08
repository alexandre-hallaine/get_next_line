/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:37:45 by ahallain          #+#    #+#             */
/*   Updated: 2021/02/08 23:08:54 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
		return (1);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	close(fd);
	return (0);
}
