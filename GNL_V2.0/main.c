/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:09:31 by ablaamim          #+#    #+#             */
/*   Updated: 2021/12/10 13:15:16 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	char	*line;
	char	*line1;
	int	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	int fd1 = open("test0.txt", O_RDONLY);
	line1 = get_next_line(fd1);
	while (line != NULL && line1 != NULL)
	{
		printf("%s", line);
		printf("%s", line1);
		free(line);
		free(line1);
		line = get_next_line(fd);
		line1 = get_next_line(fd1);
	}
	close (fd);
	close(fd1);
	return (EXIT_SUCCESS);
}
